#ifndef _DLIST_H_
#define _DLIST_H_

#include <stdexcept>

namespace listspc
{
   // forward class declaration
   template <typename dataType> class list;

   #include "node.h"
   #include "iterator.h"
   #include "const_iterator.h"

   /***********************************************\
      template class for doubly linked list
   \***********************************************/

   template <typename dataType> class list
   {
      private:
         node<dataType> *head, *tail;
         int numItems;
         
      public:
         
         /*****************************************\
            iterator friendship and functions
         \*****************************************/
         
         friend class iterator<dataType>;
         friend class const_iterator<dataType>;

         iterator<dataType> begin() 
         {
            return iterator<dataType>(this, head);
         }
         
         const_iterator<dataType> begin() const 
         {
            return const_iterator<dataType> (this, head);
         }

         iterator<dataType> end() 
         {
            return iterator<dataType>(this, NULL);
         }           
         
         const_iterator<dataType> end() const
         {
            return const_iterator<dataType>(this, NULL);
         }           
         
         /*****************************************\
            constructor and destructor functions
         \*****************************************/
         
         // default constructor
         list() : head(NULL), tail(NULL), numItems(0) 
         {
         }
         
         // copy constructor
         list(const list<dataType> &other) : 
            head(NULL), tail(NULL), numItems(0) 
         {
            for (const_iterator<dataType> itr = other.begin(); itr != other.end(); itr++) 
            {
               pushBack(*itr);
            }
         }
         
         // destructor
         ~list() 
         {
            clear();
         }
         
         /*****************************************\
            size and swap functions
         \*****************************************/
         
         void clear()
         {
            node<dataType> *current = NULL;
            
            while(head != NULL) 
            {
               // delete every node in list
               current = head;
               head = head->next;
               delete current;
            }
            numItems = 0;
            tail = NULL;
         }
         
         void swap(list<dataType> &other) 
         {
            std::swap(numItems, other.numItems);
            std::swap(head, other.head);
            std::swap(tail, other.tail);
         }
         
         bool empty() 
         {
            return (numItems == 0);
         }
         
         int size() 
         {
            return numItems;
         }
         
         /*****************************************\
            push and insertion functions
         \*****************************************/
         
         void pushFront(const dataType &item) 
         {
            // insert item into front of list
            
            head = new node<dataType>(item, NULL, head);
            numItems++;
            if (numItems == 1)
            {
               // As only one item in list, this will be the tail as well as the head.
               tail = head;
            }
         }

         void pushBack(const dataType &item) 
         {
            // insert item into back of list
            
            if (empty()) 
            {
               pushFront(item);
            } 
            else 
            {
               tail = new node<dataType>(item, tail, NULL);
               numItems++;
            }
         }
         
         iterator<dataType>insert(const iterator<dataType> iter, const dataType &item) 
         {
            // insert item into list before the node iter is pointing to. 
            // return iterator pointing to the new node 
            
            if (iter.current == head) 
            {
               // iter is pointing to the first node in the list 
               pushFront(item);
               return begin();
            } 
            else if (iter.current == NULL) 
            {
               // iter is pointing to beyond end of list 
               pushBack(item);
               return iterator<dataType>(this, tail);
            } 
            else 
            {
               // inserting node between head and tail nodes
               node<dataType> *newNode = new node<dataType>(item, iter.current->prev, iter.current);

               numItems++;
               return iterator<dataType> (this, newNode);
            }
         }
         
         /*****************************************\
            pop and erase functions
         \*****************************************/
         
         void popFront() 
         {
            // remove first item from list
            
            if (numItems == 1)
            {
               // removing last node in list
               delete head;
               head = tail = NULL;
            }
            else
            {
               if (empty()) 
               {
                  throw std::invalid_argument("Attempting to pop front of empty list");
               }
            
               // make next node in list the new head
               head = head->next;
               
               // delete the front node
               delete head->prev;
            }
            numItems--;
         }
         
         void popBack() 
         {
            // remove last item from list
            
            if (numItems == 1) 
            {
                // removing last node in list
               delete tail;
               head = tail = NULL;
            }
            else
            {
               if (empty()) 
               {
                  throw std::invalid_argument("Attempting to pop back of empty list");
               }
           
               // make prev node in list the new tail
               tail = tail->prev;
               
               // delete the final node
               delete tail->next;
            }
            numItems--;
         }

         iterator<dataType> erase(iterator<dataType> &iter) 
         {
            // delete the node iter is pointing to.
            // update iter to point to next node and then return it
            
            // keep track of node to be deleted
            node<dataType> *removeNode = iter.current;
            
            // advance iter to next node
            iter++;
            
            if (removeNode == head) 
            {
               popFront();
            } 
            else if (removeNode == tail) 
            {
               popBack();
            } 
            else 
            {  
               // removeNode is between head and tail nodes
               delete removeNode;
               numItems--;
            }
            
            return iter;
         }
         
         /*****************************************\
            find
         \*****************************************/
         
         iterator<dataType> find(const dataType &searchData)
         {
            // look for searchData in list.
            // return iterator to where found
            // if not found return end iterator
               
            node<dataType> *findNode = head;
            
            while (findNode != NULL && findNode->data != searchData)
            {
               findNode = findNode->next;
            }
            
            return iterator<dataType> (this, findNode);
         }
         
         /*****************************************\
            overloaded operators
         \*****************************************/
         
         // assignment operator
         list<dataType>& operator = (const list<dataType> &other) 
         {
            list<dataType> tempCopy(other);
            
            swap(tempCopy);
            return *this;
         }
   };
}
#endif

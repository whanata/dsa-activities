#ifndef _CONSTDLISTITERATOR_H_
#define _CONSTDLISTITERATOR_H_

#include "node.h"

/***********************************************\
   template iterator class for doubly linked
   list class
\***********************************************/

template <typename dataType> class const_iterator
{
   friend class list<dataType>;
   
   private:
      const list<dataType> *parent;
      const node<dataType> *current;
      
   public:
      // constructor
      const_iterator() : parent(NULL), current(NULL) 
      {
      }
      
      const_iterator(const list<dataType> *myParent, const node<dataType> *position) :
         parent(myParent), current(position) 
      {
      }
           
      /***********************************************\
         data access operators
      \***********************************************/
      
      // overloaded dereference operator
      const dataType& operator * () const 
      {
         if (current == NULL) 
         {
            throw std::invalid_argument("Attempting to dereference NULL in iterator");
         }
         return current->data;
      }

      // overloaded arrow operator
      const dataType* operator -> () const 
      {
         if (current == NULL) 
         {
            throw std::invalid_argument("Attempting to dereference NULL in iterator");
         }
         return &(current->data);
      }
      
      /***********************************************\
         increment operators
      \***********************************************/
      
      // overloaded prefix increment operator. E.g ++i;
      const_iterator<dataType> operator ++ () 
      {
         if (current == NULL) 
         {
            throw std::invalid_argument("Attempting to advance past end in iterator");
         }
         current = current->next;
         return *this;
      }
      
      // overloaded postfix increment operator. E.g. i++;
      const_iterator<dataType> operator ++ (int) 
      {
         const_iterator<dataType> current_data = *this;
         ++(*this);
         return current_data;
      }
      
      /***********************************************\
         decrement operators
      \***********************************************/
      
      // overloaded prefix decrement operator. E.g. --i;
      const_iterator<dataType> operator -- () 
      {
         if (current == NULL) 
         {
            throw std::invalid_argument("Attempting to advance before start in iterator");
         }
         current = current->prev;
         return *this;
      }
      
      // overloaded postfix decrement operator. E.g. i--;
      const_iterator<dataType> operator -- (int) 
      {
         iterator<dataType> current_data = *this;
         --(*this);
         return current_data;
      }
      
      /***********************************************\
         equality operators
      \***********************************************/
      
      // overloaded equality operator
      bool operator == (const const_iterator &other) const
      {
         return current == other.current;
      }
      
      // overloaded inequality operator
      bool operator != (const const_iterator &other) const
      {
         return current != other.current;
      }
};
#endif

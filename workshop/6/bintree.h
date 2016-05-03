#ifndef BINTREE_H_
#define BINTREE_H_

#include <stdexcept>
   
void throw_exception(const char* message)
{
   throw std::invalid_argument(message);
}
         
namespace treespc
{
   // forward class declaration
   template <typename dataType> class bintree;
   template <typename dataType> class binnode;
   
   #include "const_iterator.h"
   #include "binnode.h"

   /********************************************************\
      template class for a binary tree
   \********************************************************/
      
   template <typename dataType> class bintree
   {
      friend const_iterator<dataType>;
   
      private:
         binnode<dataType> *root;
         int numItems;
         
      public:
        
         /*******************************************************\
            constructors & destructors
         \*******************************************************/
         
         // constructor
         bintree() : root(NULL), numItems(0) {}

         // copy constructor
         bintree(const bintree<dataType> &other) : numItems(other.numItems) 
         {
            if (other.root != NULL) 
            {
               root = new binnode<dataType>(*(other.root));
            }
            else 
            {
               root = NULL;
            }
         }
         
         // destructor
         ~bintree() 
         {
            if (root != NULL) delete root;
         }
              
         /*******************************************************\
            tree information
         \*******************************************************/
         
         bool empty() const 
         {
            return (numItems == 0);
         }
         
         int size() const 
         {
            return numItems;
         }
           
         /*******************************************************\
            iterator functions
         \*******************************************************/
         
         const_iterator<dataType> begin() const
         {
            return const_iterator<dataType>(this);
         }
         
         const_iterator<dataType> end() const
         {
            return const_iterator<dataType>(this, NULL);
         }
         
         /*******************************************************\
            insertion erasure and find functions
         \*******************************************************/
         
         void insert(const dataType& newData) 
         {
            if (root == NULL) 
            {
               root = new binnode<dataType>(newData, NULL);
            } 
            else 
            {
               root->insert(newData);
            }
            numItems++;
         }
         
         void erase(const dataType& delData) 
         {
            if (root == NULL) 
            {
               throw_exception("data does not exist in tree to erase");
            }
            
            root->erase(root, delData);
            
            numItems--;
         }
         
         const_iterator<dataType> find(const dataType &findData) const 
         {
            if (root == NULL) 
            {
               return end();
            }
            else 
            {
               return const_iterator<dataType>(this, root->find(findData));
            }
         }
         
         /*******************************************************\
            overloaded operators 
         \*******************************************************/

         bintree<dataType>& operator = (const bintree<dataType> &other) 
         {
            if (root != NULL) 
            {
               delete root;
               numItems = 0;
            }
            
            if (other.root != NULL) 
            {
               root = new binnode<dataType>(*(other.root));
               numItems = other.numItems;
            }
            return *this;
         }
   };
}

#endif

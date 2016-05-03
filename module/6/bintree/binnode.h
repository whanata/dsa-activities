#ifndef BINNODE_H
#define BINNODE_H

#include <math.h>
#include <iostream> 
#include <stdexcept>

/********************************************************\
   template node class for binary tree
\********************************************************/

template <typename dataType> class binnode 
{
   friend const_iterator<dataType>;
   
   private:
      dataType nodeData;
      binnode<dataType> *left, *right, *root;
      
      bool leafNode()
      {
         return (left == NULL && right == NULL);
      }
      
      bool hasRightBranchOnly()
      {
         return (left == NULL && right != NULL);
      } 
      
      bool hasLeftBranchOnly()
      {
         return (left != NULL && right == NULL);
      }
      
      void addToLeftSide(binnode<dataType> *branch)
      {
         binnode<dataType> *furthestLeft = this;
         
         // keep moving to the left until unable to do so
         while (furthestLeft->left != NULL) furthestLeft = furthestLeft->left;
         
         // we have found the left most point to add the branch
         furthestLeft->left = branch;
      }
      
      void deleteNode(binnode<dataType>* &root) 
      {
         if (leafNode()) 
         {
            root = NULL;
         } 
         else if (hasRightBranchOnly()) 
         {
            root = right;
         } 
         else if (hasLeftBranchOnly()) 
         {
            root = left;
         } 
         else   
         {
            // has left and right branch
            // attach left branch to left side of right branch
            right->addToLeftSide(left);
            // make root point to right branch
            root = right;
         }
         
         // cut node out of tree then delete
         left = right = NULL;
         delete (this); 
      }
           
   public:
      
      /********************************************************\
         constructors and destructors
      \********************************************************/

      // constructors
      binnode() : root(NULL), left(NULL), right(NULL)
      {
      }
   
      binnode(const dataType& dataItem, binnode<dataType> *parent) :
         nodeData(dataItem), root(parent), left(NULL), right(NULL)
      {
      }

      // copy constructor
      binnode(const binnode<dataType> &otherNode) : 
         nodeData(otherNode.nodeData), root(NULL)
      {
         if (otherNode.left != NULL) 
         {
            // make use of the copy constructor to 
            // recursively copy left sub-tree of otherNode
            left = new binnode<dataType>(*(otherNode.left));
            left->root = this;
         }
         else 
         {
            left = NULL;
         }
         
         if (otherNode.right != NULL) 
         {
            right = new binnode<dataType>(*(otherNode.right));
            right->root = this;
         }
         else 
         {
            right = NULL;
         }
      }
   
      // destructor
      ~binnode() 
      {
         // destructor will recursively destroy entire tree
         if (left != NULL) delete left;
         if (right != NULL) delete right;
      }
      
      /********************************************************\
         insert, delete and find
      \********************************************************/
      
      void insert(const dataType& dataItem) 
      {
         if (nodeData == dataItem) 
         {
            throw_exception("dataItem already in tree");
         }
      
         if (dataItem < nodeData) 
         {
            // dataItem must go somewhere in left sub-branch
            if (left == NULL) 
            {
               // left has no sub-branch, add a new node to it
               left = new binnode(dataItem, this);
            } 
            else 
            {
               // there is a left sub-branch, recurse into it
               left->insert(dataItem);
            }
         } 
         else 
         {
            // dataItem must go somewhere in right sub-branch
            if (right == NULL) right = new binnode(dataItem, this);
            else right->insert(dataItem);
         }
      }
      
      void erase(binnode<dataType>* &root, const dataType &delData) 
      {
         if (delData == nodeData) 
         {
            // delData found. now delete it
            deleteNode(root);
         } 
         else if (delData < nodeData) 
         {
            // delData must be in the left sub-branch
            if (left == NULL) throw_exception("Item to delete not in tree");
            else left->erase(left, delData);
         } 
         else 
         {
            // delData must be in the right sub-branch
            if (right == NULL) throw_exception("Item to delete not in tree");
            else right->erase(right, delData);
         }
      }
      
      const binnode<dataType>* find(const dataType &findData) const
      {
         if (findData == nodeData) 
         {
            // return address of this binnode containing nodeData
            return this;
         } 
         else if (findData < nodeData) 
         {
            // findData must be in the left sub-branch
            if (left == NULL) return NULL;
            else return left->find(findData);
         } 
         else 
         {
            // findData must be in the right sub-branch
            if (right == NULL) return NULL;
            else return right->find(findData);
         }
      }   
      /********************************************************\
         overloaded operators 
      \********************************************************/

      // binnode<dataType>& operator = (const binnode<dataType> &other) 
      // never used. copy constructor will be called from bintree operator =
      
};

#endif

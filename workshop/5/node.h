#ifndef _DNODE_H
#define _DNODE_H

/***********************************************\
   template node class for doubly linked list
\***********************************************/

template <typename dataType> struct node
{
   dataType data;
   node *prev, *next;
   
   // constructors
   node() : prev(NULL), next(NULL) {}

   node(const dataType& dataItem, node *prevPtr, node *nextPtr) : 
       data(dataItem), prev(prevPtr), next(nextPtr) 
   {   
      // we are now pointing to nodes on either side
      // get them pointing to this node
      if (prev != NULL) prev->next = this;
      if (next != NULL) next->prev = this;
   }
   
   // destructor
   ~node()
   {
      // cut node out of list before deleting
      if (prev != NULL) prev->next = next;
      if (next != NULL) next->prev = prev;
   }
};
#endif

#include <iostream>

#include "testclass.h"
#include "list.h"

void print_container(const listspc::list<testclass> & container)
{ 
   // demonstrate -> operator with iterator
   // and const iterator
      
   listspc::const_iterator<testclass> c_iter;
   
   for (c_iter = container.begin(); c_iter != container.end(); c_iter++)
   {
      std::cout << c_iter->getData() << " ";
   }
   std::cout << "\n";
}

void update_container(listspc::list<testclass> & container)
{
   // demonstrate * operator with iterator
   // and non-const iterator
      
   listspc::iterator<testclass> iter;
   int i=2;

   for (iter = container.begin(); iter != container.end(); iter++)
   {
      (*iter).setData(i);
      i += 2;
   }
}

int main()
{
   listspc::list<testclass> container;
   testclass *tc;

   // fill list
   for (int i=0; i<9; i++) 
   {
      tc = new testclass(i);
      container.push_back(*tc);
      delete tc;
   }

   update_container(container);
   print_container(container);
   
   return 0;
}

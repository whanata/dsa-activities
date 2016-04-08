#include <iostream>

#include "testclass.h"
#include "vector.h"

void print_vector(const vectorspc::vector<testclass> & vec)
{ 
   // demonstrate -> operator with iterator
   // and const iterator
      
   vectorspc::const_iterator<testclass> c_iter;
   
   for (c_iter = vec.begin(); c_iter != vec.end(); c_iter++)
   {
      std::cout << c_iter->getData() << " ";
   }
   std::cout << "\n";
}

void update_vector(vectorspc::vector<testclass> & vec)
{
   // demonstrate * operator with iterator
   // and non-const iterator
      
   vectorspc::iterator<testclass> iter;
   int i=2;

   for (iter = vec.begin(); iter != vec.end(); iter++)
   {
      (*iter).setData(i);
      i += 2;
   }
}

int main()
{
   vectorspc::vector<testclass>  vec;
   testclass *tc;

   // fill vector
   for (int i=0; i<9; i++) 
   {
      tc = new testclass(i);
      vec.push_back(*tc);
      delete tc;
   }

   update_vector(vec);
   print_vector(vec);
   
   return 0;
}

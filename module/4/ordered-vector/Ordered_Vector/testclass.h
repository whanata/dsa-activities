#ifndef _TESTCLASS_H
#define _TESTCLASS_H

#include <iostream>

class testclass
{
   private:
      int data;

   public:
      testclass(): data(0) {}
      testclass(int x): data(x) {}

      int getData() const { return data ;}

      void setData(int x) { data = x; }
      
      // overload relational operators
      
      bool operator == (const testclass &other) const
      {
         return data == other.data;
      }
      
      bool operator != (const testclass &other) const
      {
         return data != other.data;
      }
      
      bool operator < (const testclass &other) const
      {
         return data < other.data;
      }
      
      bool operator <= (const testclass &other) const
      {
         return data <= other.data;
      }
      
      bool operator >= (const testclass &other) const
      {
         return data >= other.data;
      }
      
      bool operator > (const testclass &other) const
      {
         return data > other.data;
      }
};

#endif
 

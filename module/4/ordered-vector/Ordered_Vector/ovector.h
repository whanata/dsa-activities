#ifndef VECTOR_H_ 
#define VECTOR_H_ 

#include <stdexcept> 
// include Standard Template Library vector class
#include <vector> 

/***********************************************\ 
   template class for ordered vector 
\***********************************************/ 

namespace ovecspc
{
   template<typename dataType> class orderedVector 
   { 
      private: 
         // standard template library vector class
         std::vector<dataType> aVector; 

         // typedef iterator names to simplify coding
         typedef typename std::vector<dataType>::iterator iterator; 
         typedef typename std::vector<dataType>::const_iterator const_iterator; 

      public: 

         /*****************************************\ 
            size functions 
         \*****************************************/ 
         
         size_t size() const 
         { 
            return aVector.size(); 
         } 

         bool empty() const 
         { 
            return aVector.empty(); 
         } 
         
         /*****************************************\ 
            insert and push functions 
         \*****************************************/ 

         void insert(const dataType &newData) 
         { 
            // set iterator to correct position with binary search 
            // lower_bound is found in algorithms library         
            iterator position = lower_bound(aVector.begin(), aVector.end(), newData); 

            // insert data into vector just before position 
            aVector.insert(position, newData); 
         } 

         /*****************************************\ 
            iterator functions 
            Do not return non-const iterators.
            Users of them could change data in the 
            ordered vector and break its ordering.
            This cannot be allowed.
         \*****************************************/ 

         const_iterator begin() const 
         { 
            return aVector.begin(); 
         } 

         const_iterator end() const 
         { 
            return aVector.end(); 
         } 

         /*****************************************\ 
            erase and pop functions 
         \*****************************************/ 

         void erase(const dataType &data) 
         { 
            // set iterator to correct position with binary search
            iterator itr = lower_bound(aVector.begin(), aVector.end(), data); 

            // if data found then erase it 
            if (data == *itr) aVector.erase(itr); 
         } 

         void pop_back() 
         { 
            aVector.pop_back(); 
         } 

         void pop_front() 
         { 
            // The STL vector class has no pop_front function
            // do it this way
            aVector.erase(aVector.begin()); 
         } 

         /*****************************************\ 
            misc functions 
         \*****************************************/ 

         const_iterator find(const dataType &data) const
         { 
            const_iterator found = lower_bound(aVector.begin(), aVector.end(), data); 

            return found;
         } 

         /*****************************************\ 
            overloaded operators 
            for reasons given above for iterators,
            only return a const []
         \*****************************************/ 

         // overloaded const [] operator 
         const dataType& operator [] (int index) const 
         { 
            return aVector[index]; 
         } 

         // overloaded assignment operator 
         orderedVector<dataType>& operator = (const orderedVector<dataType> &other) 
         { 
            aVector = other.aVector; 
            return *this; 
         } 
   }; 
}
#endif 
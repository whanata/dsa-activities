#ifndef VECTOR_H 
#define VECTOR_H 
   
#include <iostream>
#include <stdexcept> 
#include <vector> 
   
namespace vectorspc
{
   // forward declaration of vector class
   template<typename dataType> class Vector;

   /***********************************************\ 
      template class for vector 
   \***********************************************/ 
      
   template<typename dataType> class Vector 
   { 
      // typedef iterator names to simplify coding
      typedef typename std::vector<dataType>::iterator iterator; 
      typedef typename std::vector<dataType>::const_iterator const_iterator; 

      private: 
         static const int INITIAL_CAPACITY = 100; 
            
         // int currentCapacity; 
         // int numItems; 
         // dataType* this->theData; 
         std::vector<dataType> theData;
         
         /*****************************************\ 
            resize functions 
         \*****************************************/ 
         
         // dataType* buildDataArray(int capacity) const
         // {
         //    dataType* this->theData = new dataType[capacity]; 
         //    if (this->theData == NULL) 
         //    { 
         //       throw std::runtime_error("Unable to allocate memory for data array"); 
         //    }
         //    return this->theData;
         // }
    
         // void resize(int newCapacity) 
         // { 
         //    if (newCapacity > currentCapacity) 
         //    { 
         //       // set aside space with extra capacity 
         //       currentCapacity = newCapacity; 
         //       dataType *newData = buildDataArray(newCapacity);
                  
         //       // copy the items across to the new space 
         //       for (int i=0; i<numItems; i++) 
         //       { 
         //          newData[i] = this->theData[i]; 
         //       } 
                  
         //       // delete the old data array
         //       delete[] this->theData; 
                  
         //       // make this->theData equal to the newly allocated array
         //       this->theData = newData; 
         //    } 
         // } 
    
         // void resize() 
         // { 
         //    resize(currentCapacity * 2); 
         // } 
            
      public: 
    
         /*****************************************\ 
            constructors and destructors 
         \*****************************************/ 
    
         // // default constructor 
         // Vector(): 
         //    currentCapacity(INITIAL_CAPACITY), 
         //    numItems(0) 
         // { 
         //    this->theData = buildDataArray(currentCapacity);
         // } 
         
         // Vector(int starting_capacity): 
         //    currentCapacity(starting_capacity), 
         //    numItems(0) 
         // { 
         //    this->theData = buildDataArray(currentCapacity);
         // } 
    
         // // copy constructor 
         // Vector(const vector<dataType> &other): 
         //    currentCapacity(0), 
         //    numItems(0),
         //    this->theData(NULL)
         // { 
         //    // make use of overloaded equals operator to reduce duplication of code
         //    *this = other;
         // } 
    
         // // destructor 
         // ~Vector() 
         // { 
         //    delete [] this->theData; 
         // } 
            
         /*****************************************\ 
            vector size functions 
         \*****************************************/ 
    
         bool isEmpty() const 
         { 
            return this->theData.empty(); 
         } 
    
         int size() const 
         { 
            return this->theData.size(); 
         } 
    
         /*****************************************\ 
            insertion and push functions 
         \*****************************************/ 
         
         iterator insert(iterator iter, const dataType &item) 
         {
            insert(item, iter.current);
            
            return iter;
         }
    
         void insert(const dataType &newData, int index) 
         { 
            this->theData.insert(index, newData); 
         } 
    
         void pushBack(const dataType &newData) 
         { 
            // append newData to the end of the vector 
            this->theData.push_back(newData); 
         } 
    
         void pushFront(const dataType &newData) 
         { 
            // insert newData into the front of the vector 
            insert(newData, this->begin()); 
         } 
            
         /*****************************************\ 
            erase and pop functions 
         \*****************************************/ 
            
         void clear()
         {
            this->theData.clear();
         }
         
         iterator erase(iterator &iter) 
         {
            erase(iter.current);
            
            return iter;
         }
    
         void erase(int index) 
         { 
            this->theData.erase(index);
         } 
    
         void popBack() 
         { 
            this->theData.pop_back(); 
         } 
    
         void popFront() 
         { 
            this->theData.erase(this->begin());
         } 
         
         /******************************************\ 
            const and non-const iterators for vector 
         \******************************************/ 
         
         iterator begin()
         {
            return this->theData.begin();
         }
         
         const_iterator begin() const
         {
            return this->theData.begin();
         }
               
         iterator end()
         {
            return this->theData.end();
         }
         
         const_iterator end() const
         {
            return this->theData.end();
         }
    
         /******************************************\ 
            find 
         \******************************************/ 

         iterator find(const dataType &searchData)
         {
            // look for searchData in vector.
            // if found return iterator where found
            // otherwise return end iterator.
               
            for (int i=0; i<this->theData.size(); i++)
            {
               if (this->theData[i] == searchData) 
               {
                  return iterator(this, i);
               }
            }
            return end();
         }

         /*****************************************\ 
            at
         \*****************************************/ 

         dataType& at (int index) 
         {
            return this->theData.at(index);
         }

         const dataType& at (int index) const 
         {
            return this->theData.at(index);
         }
         
         /*****************************************\ 
            overloaded operators 
         \*****************************************/ 
    
         // overloaded [] operator 
         dataType& operator [] (int index) 
         { 
            return this->theData[index]; 
         } 
            
         // overloaded const [] operator 
         const dataType& operator [] (int index) const 
         { 
            return this->theData[index]; 
         } 
    
         // overloaded assignment operator 
         Vector<dataType>& operator = (const Vector<dataType> &other) 
         { 
            this->theData = other.theData; 
            return *this; 
         } 
   };
}
  
#endif 

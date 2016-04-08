#ifndef VECTOR_CONST_ITERATOR_H_ 
#define VECTOR_CONST_ITERATOR_H_ 
   
/***********************************************\ 
   template const_iterator class for vector 
\***********************************************/ 
   
template <typename dataType> class const_iterator 
{ 
   friend vector<dataType>;
   
   private: 
      const vector<dataType> *parent; 
      int current; 
 
   public: 
      // constructor 
      const_iterator() : 
         parent(NULL), current(0) 
      { 
      } 
      
      const_iterator(const vector<dataType> *myParent, int position) : 
         parent(myParent), current(position) 
      { 
      } 
 
      /********************************************\
         access operators
      \********************************************/
         
      // overloaded dereference operator 
      const dataType& operator * () const 
      { 
         if (current < 0 || current >= parent->numItems) 
         { 
            throw std::invalid_argument("Attempting to dereference outside vector"); 
         } 
         return parent->theData[current];  
      } 
         
      // overloaded arrow operator 
      const dataType* operator -> () const 
      { 
         if (current < 0 || current >= parent->numItems) 
         { 
            throw std::invalid_argument("Attempting to reference outside vector"); 
         } 
         return &(parent->theData[current]); 
      } 
         
      /********************************************\
         increment operators
      \********************************************/
 
      // overloaded prefix increment operator. eg ++i;
      const_iterator<dataType> operator ++ () 
      { 
         if (current >= parent->numItems) 
         { 
            throw std::invalid_argument("Attempting to advance past end of vector"); 
         } 
         current++; 
         return *this; 
      } 
 
      // overloaded postfix increment operator. eg i++;
      const_iterator<dataType> operator ++ (int) 
      { 
         const_iterator<dataType> current_data = *this; 
         ++(*this); 
         return current_data; 
      } 
         
      /********************************************\
         decrement operators
      \********************************************/
         
      // overloaded prefix decrement operator. eg --i;
      const_iterator<dataType> operator -- () 
      { 
         if (current <= 0) 
         { 
            throw std::invalid_argument("Attempting to advance before start of vector"); 
         } 
         current--; 
         return *this; 
      } 
 
      // overloaded postfix decrement operator. eg i--;
      const_iterator<dataType> operator -- (int) 
      { 
         const_iterator<dataType> current_data = *this; 
         --(*this); 
         return current_data; 
      } 
         
      /********************************************\
         equality operators
      \********************************************/
         
      // overloaded equality operator 
      bool operator == (const const_iterator &other) const
      { 
         return (parent == other.parent && current == other.current); 
      } 
 
      // overloaded inequality operator 
      bool operator != (const const_iterator &other) const
      { 
         return (parent != other.parent || current != other.current); 
      } 
}; 
#endif 

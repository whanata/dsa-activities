/*888888888888888888****************************\
   Definitions of members of stringlist class 
\***********************************************/ 
#include <iostream> 
using namespace std; 
      
class stringlist 
{ 
   private: 
      int numstrings; 
      string *strings; 
            
   public: 
      // default constructor
      stringlist() : numstrings(0), strings(NULL) {} 
            
      // copy constructor 
      stringlist(const stringlist &other)
      { 
         // make use of overloaded = operator
         *this = other;
      } 
            
      // destructor 
      ~stringlist() 
      { 
         if (numstrings > 0) delete [] strings; 
      } 
            
      // setters
      void setString(int num, const char *astring); 
      void setString(int num, const string &astring); 
      void setNumstrings(int num); 
            
      // getters
      const string& getString(int num) const; 
      int getNumstrings() const
      {  
         return numstrings;  
      } 
            
      // misc class functions
      void printStrings(); 
      void swapStrings(stringlist &other);
          
      // overloaded operators 
      stringlist& operator = (const stringlist &other) 
      { 
         // delete current strings
         if (numstrings > 0) delete [] strings; 
               
         // set up new strings
         numstrings = other.numstrings;
         if (numstrings > 0) strings = new string[numstrings];
         else strings = NULL;
                      
         // copy over strings
         for (int i=0; i<numstrings; i++) 
         { 
            strings[i] = other.strings[i]; 
         } 
      } 
}; 


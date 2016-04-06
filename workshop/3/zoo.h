#ifndef ZOO_H 
#define ZOO_H

#include <stdexcept> 
#include <string>

#include "stock.h"

using namespace std;
      
class zoo
{ 
   private: 
      stock *stocks; 
      int size;
      
   public: 
      void loadZoo(string file);
      void saveZoo(string file);
      int getNumstock();
      int numPen(string penId);
      int numClass(string className);
      bool checkInt(string text);
      void getSize(bool &gotSize, string text);
      void getStock(bool gotSize, int &stockCounter, int &counter, string *stringList, string text);
      bool checkChar(string text);
      string getString() const;

      zoo() 
      { 
         size = 0; 
         stocks = NULL;
      } 
      
      zoo(const zoo &other) 
      { 
         // copy constructor 
         stocks = NULL; 
         // make use of overloaded = operator to reduce code duplication
         *this = other; 
      } 
      
      ~zoo() 
      { 
         // destructor
         if (stocks != NULL) 
         {
            delete [] stocks; 
         }
      } 
      
      zoo& operator = (const zoo &otherZoo) 
      { 
         // clean up any allocated memory 
         if (stocks != NULL)  
         { 
            delete [] stocks; 
            stocks = NULL; 
         } 
         
         size = otherZoo.size; 
         if (size > 0) 
         { 
            // create a new stocks 
            stocks = new stock[size]; 
            
            // copy the contents of other stocks to this stocks 
            for (int i=0; i<size; i++)  
            {
               stocks[i] = otherZoo.stocks[i]; 
            }
         } 
      } 
};

#endif
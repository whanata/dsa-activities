#ifndef ZOO_H 
#define ZOO_H

#include <stdexcept> 
#include <string>

#include "stock.h"
#include "list.h"

using namespace std;
      
class zoo
{ 
   private: 
      listspc::list<stock> stocks;
      int size;
      
   public: 
      void loadZoo(string file);
      void saveZoo(string file);
      int getNumstock();
      int numPen(string penId);
      int numClass(string className);
      bool checkInt(string text);
      void getSize(bool &gotSize, string text);
      void getStock(bool gotSize, int &counter, string *stringList, string text);
      bool checkChar(string text);
      string getString() const;
      listspc::list<stock> *getPenStock(const string &pen) const;
      string getPenStockString(const string &pen) const;

      zoo() 
      { 
         size = 0; 
      } 
};

#endif
#ifndef _ZOO_H
#define _ZOO_H

#include <list>
#include <stdexcept>

#include "stock.h"

const int MAXPEN = 100;

using namespace std;

class zoo
{
   private:
      std::list<stock> zooStock;
      
      int loadNumstock(ifstream &fin)
      {
         char line[256];
         if (!readline(fin, line, 256, '\n'))
         {
            throw runtime_error("file corrupted - invalid number of stock");
         }
         
         int numStock = atoi(line);
         if (numStock < 0)
         {
            throw runtime_error("file corrupted - invalid number of stock");
         }
         return numStock;
      }
      
   public:
     
      // zoo file operations ==============================================
      void loadZoo(const char* filename)
      {
         if (zooStock.size() > 0) zooStock.clear();
         ifstream fin;
         fin.open(filename);
         if (!fin)
         {
            throw runtime_error("unable to open load file");
         }
     
         int numStock = loadNumstock(fin);
         stock *newStock;
         
         for (int i=0; i<numStock; i++) 
         {
            newStock = new stock();
            if (newStock == NULL) 
            {
               throw runtime_error("unable to allocate stock");
            }
            newStock->loadStock(fin);
            zooStock.push_back(*newStock);
         }
      }
      
      void saveZoo(const char* filename) const
      {
         ofstream fout;
         
         fout.open(filename);
         if (!fout)
         {
            throw runtime_error("unable to open save file");
         }
         fout << zooStock.size() << '\n';
         
         list<stock>::const_iterator itr;
   
         for (itr = zooStock.begin(); itr != zooStock.end(); itr++ ) 
         {
            itr->saveStock(fout);
         }
      }
      
      // getters ========================================================
      int getNumstock() const { return zooStock.size(); };
      
      int numClass(const string &classname) const
      {
        
      }

      int numPen(const string &pen) const
      {
        
      }
      
      list<stock> * getPenStock(const string &pen) const
      {
         
      }
 };
 
 #endif
 
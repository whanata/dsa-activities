#ifndef _STOCK_H
#define _STOCK_H

#include <string>
#include <stdlib.h>
#include "animal.h"

const int MAXID = 999999;

using namespace std;

class stock
{
   private:
      int ID;
      animal data;
      char sex;
      string pen;
      char line[256];
      
      void loadID(ifstream &fin)
      { 
         if (!readline(fin, line, 256, '\n'))
         {
            throw runtime_error("file corrupted - invalid stock ID");
         }
         ID = atoi(line);
      }
      
      void loadSex(ifstream &fin)
      {
         if (!readline(fin, line, 256, '\n'))
         {
            throw runtime_error("file corrupted - invalid sex");
         }
         sex = line[0];
      }
      
      void loadPen(ifstream &fin)
      {
         if (!readline(fin, line, 256, '\n'))
         {
            throw runtime_error("file corrupted - invalid pen");
         }
         pen = line;
      }
      
      bool confirmData(string &error) const
      {
         // check ID
         if (ID < 0 || ID > MAXID)
         {
            error = "invalid ID";
            return false;
         }
         
         // check sex
         if (sex != 'm' && sex != 'f')
         {
            error = "invalid sex";
            return false;
         }
         
         // check pen
         if (!validPen(pen))
         {
            error = "invalid pen";
            return false;
         }
         
         return true;
      }
      
   public:
      stock()
      {
      }
      
      // stock file operations ==================================================
      void loadStock(ifstream &fin)
      {
         loadID(fin);
         loadSex(fin);
         loadPen(fin);
         data.loadAnimal(fin);
         
         //printStock();
         
         string error;
         if (!confirmData(error))
         {
            throw out_of_range(error.c_str()); 
         }
      }
      
      void printStock()
      {
         cout << "ID = " << ID << "\n";
         cout << "sex = " << sex << "\n";
         cout << "pen " << pen << "\n";
         data.printAnimal();
         cout << "\n";
      }
      
      void saveStock(ofstream &fout) const
      {
         fout << ID  << '\n';
         fout << sex  << '\n';
         fout << pen  << '\n';
         data.saveAnimal(fout);
      }
      
      // stock utility functions ==============================================
      
      static bool validPen(const string &pen)
      {
         if (pen.length() != 3 || !isupper(pen[0]) ||
             !isdigit(pen[1]) || !isdigit(pen[2]))
         {
            return false;
         }
         return true;
      }
      
      // get stock data ========================================================
      int getID() const { return ID; }
      char getSex() const { return sex; }
      const string& getPen() const { return pen; }
      
      // get animal data ======================================================
      const string& getClassname() const { return data.getClassname(); }
      const string& getGenus() const { return data.getGenus(); }
      const string& getSpecies() const { return data.getSpecies(); }
};

#endif

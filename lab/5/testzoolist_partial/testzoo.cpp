#include <iostream>
#include "zoo.h"

using namespace std;

void printPen(const zoo &myZoo, const char *pen);

int main(int argc, char*argv[])
{  
   if (argc == 3)
   {
      try
      {
         if (!stock::validPen(argv[2]))
         {
            throw runtime_error("invalid pen argument");
         }
         
         zoo myZoo;
         myZoo.loadZoo(argv[1]);
         
         cout << "Num Stock = " << myZoo.getNumstock() << "\n";
         cout << "Num pen " << argv[2] << " = " << myZoo.numPen(argv[2]) << "\n";
         cout << "Num Mammalia = " << myZoo.numClass("Mammalia") << "\n";
         
         printPen(myZoo, argv[2]);
      }
      catch (exception &ex)
      {
         cout << "\nERROR - Exception thrown\n" << ex.what() << "\n";
      }
   }
   else
   {
      cout << "\nERROR - Invalid command line arguments\n";
      cout << "SYNTAX : testzoovec stock_text_file pen_number\n";
   }

   return 0;
}


void printPen(const zoo &myZoo, const char *pen)
{
   list <stock> *penStock = myZoo.getPenStock(pen);
   list<stock>::const_iterator itr;
   
   cout << "\nStock found in pen " << pen << "\n\n";
   
   for (itr = penStock->begin(); itr != penStock->end(); itr++ ) 
   {
      cout << itr->getID() << "\n";
      cout << itr->getSex() << "\n";
      cout << itr->getPen() << "\n";
      cout << itr->getClassname() << "\n";
      cout << itr->getGenus() << "\n";
      cout << itr->getSpecies() << "\n\n";
   }
   
   delete penStock;
}

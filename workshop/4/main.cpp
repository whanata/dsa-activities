#include <iostream>

#include "zoo.h"

using namespace std;

int main(int argc, char *argv[])
{  
   if (argc == 3)
   {
      try
      {
         zoo myZoo;
         myZoo.loadZoo(argv[1]);
         
         cout << "Num Stock = " << myZoo.getNumstock() << "\n";
         cout << "Num pen C43 = " << myZoo.numPen("C43") << "\n";
         cout << "Num Mammalia = " << myZoo.numClass("Mammalia") << "\n";
         
         myZoo.saveZoo(argv[2]);
      }
      catch (exception &ex)
      {
         cout << "\nERROR - Exception thrown\n" << ex.what() << "\n";
      }
   }
   else
   {
      cout << "\nERROR - Invalid command line arguments\n";
   }

   return 0;
}

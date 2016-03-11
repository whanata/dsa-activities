/******************************************************\
   program to print command line arguments to screen
\******************************************************/

#include <iostream>

using namespace std;

void printArguments(int argc, char *argv[]);

int main(int argc, char *argv[]) 
{
   cout << "Program name is " << argv[0] << "\nArguments\n";
   printArguments(argc, argv);

   return 0;
}

void printArguments(int argc, char *argv[])
{
   // print arguments to screen

   for (int i=1; i<argc; i++) 
   {
      cout << "arg " << i << " = " << argv[i] << '\n';
   }
}

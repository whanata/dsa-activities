/**************************************************\
   program to print entered strings to screen
\**************************************************/

#include <iostream>

using namespace std;

void getStrings(int *numstringsPtr, strings* &stringArray);
void printStrings(int numstrings, const strings *stringArray);

int main() 
{
   string *stringArray = NULL;
   int numstring = 0;

   getStrings(&numstring, stringArray);
   printStrings(numstring, stringArray);

   // clean up any allocated memory
   if (stringArray != NULL) delete [] stringArray;

   return 0;
}

void getStrings(int *numstringsPtr, strings* &stringArray)
{
   // get strings from user keyboard

   // get number os strings to be entered
   int numstrings;
   
   cout << "Enter number of strings ";
   cin >> numstrings;
   *numstringsPtr = numstrings;
   
   // allocate an array of strings
   stringArray = new string[numstrings];

   // get the user to enter the strings
   cout << "Enter strings\n";
   for (int i=0; i<numstrings; i++) 
   {
      cin >> stringArray[i];
   }
}

void printStrings(int numstrings, const strings *stringArray)
{
   // print strings to screen
   cout << "Strings entered\n";
   
   for (int i=0; i<numstrings; i++) 
   {
      cout << stringArray[i] << '\n';
   }
}



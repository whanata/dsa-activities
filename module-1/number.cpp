/**********************************************\ 
   ask user to enter a number
   print 0 to number-1
\**********************************************/

#include <iostream>

using namespace std;

int main() 
{
   int count, number;

   cout << "Please enter a number\n";
   cin >> number;

   if (cin.good()) 
   {
      // print numbers
      cout << "Printing numbers from 0 to " << number-1 << "\n";
      for (count=0; count<number; count++) 
      {
         cout << count << "\n";
      } 
   } 
   else 
   {
      cout << "Unable to read number\n";
   }

   return 0;
}
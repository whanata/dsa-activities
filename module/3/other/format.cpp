#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
   cout << "FLOATING POINT FORMATS\n";
   cout << "Scientific : " << scientific << sqrt(999.0) << "\n";
   cout << "Fixed : " << fixed << sqrt(999.0) << "\n";
   cout.unsetf(ostream::floatfield);
   cout << "Default : " << sqrt(999.0) << "\n\n";
   
   double d = 12.345678;
         
   cout << "OUTPUT MANIPULATORS\n";
   cout << fixed;
   cout << setprecision(4) << d << "\n";
   cout << setw(10) << d << "\n";
   cout << setw(10) << setfill('#') << d << "\n";
   cout << left << setw(10) << setfill('#') << d << "\n";
   
   return 0;
}

#include <iostream> 

using namespace std;
   
int doSomething();

int doSomething()
{
   static int count;
   
   // code to do something;
   
   count++;
   return count;
}

int main()
{
   int count = doSomething(); 
   cout << "Count = " << count << '\n';
   
   count = doSomething();
   cout << "Count = " << count << '\n';
   
   count = doSomething();
   cout << "Count = " << count << '\n';
   
   return 0;
}
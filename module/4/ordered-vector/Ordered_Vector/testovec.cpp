/*************************************************\ 
   Test program for demonstrating container types 
\*************************************************/ 

#include <stdlib.h>

#include "testclass.h" 
#include "ovector.h" 
#include "timer.h"

using namespace std; 


double average(const ovecspc::orderedVector<testclass> &container)
{
   std::vector<testclass>::const_iterator iter;
   std::vector<testclass>::const_iterator enditer = container.end();
   
   double total = 0;
   
   for (iter = container.begin(); iter != enditer; iter++)
   {
      total += iter->getData();
   }
   
   return total / container.size();
}

int main() 
{ 
   const int MAXDATA = 50000; 
   testclass *tc; 
   int i, keyvals[MAXDATA]; 
   timer aTimer;
   
   ovecspc::orderedVector<testclass> container; 
   std::vector<testclass>::const_iterator c_iter; 

   try 
   { 
      /*****************************************\ 
         Initialise things to demonstrate the 
         container 
         - fill keyvals and scramble it 
      \*****************************************/ 

      for (i=0; i<MAXDATA; i++) keyvals[i] = i; 
      srand(time(NULL)); 
      for (i=0; i<MAXDATA; i++) swap(keyvals[i], keyvals[random() % MAXDATA]); 
      
      /*****************************************\ 
         test inserting MAXDATA data pieces 
         into the container with keyval 0 to 
         MAXDATA-1 in random order 
      \*****************************************/ 

      aTimer.startTimer();
      for (i=0; i<MAXDATA; i++) 
      { 
         tc = new testclass(keyvals[i]); 
         container.insert(*tc); 
         delete tc;
      } 
      aTimer.stopTimer();

      cout << MAXDATA << " items in container in random order\n"; 
      cout << "time taken to push data into container = ";
      cout << aTimer.getTimeInterval() << " seconds\n";
      cout << "Num items in container = " << container.size() << "\n\n"; 

      /*****************************************\ 
         test finding data in the container 
      \*****************************************/ 

      cout << "TESTING CONTAINER FIND\n";
      
      aTimer.startTimer();
      c_iter = container.find(testclass(keyvals[0])); 
      aTimer.stopTimer();
      cout << "time taken to find first item in container = "; 
      cout << aTimer.getTimeInterval() << " seconds\n"; 
      cout << "found = " << c_iter->getData() << "\n";

      aTimer.startTimer();
      c_iter = container.find(testclass(keyvals[MAXDATA/2])); 
      aTimer.stopTimer();
      cout << "time taken to find middle item in container = "; 
      cout << aTimer.getTimeInterval() << " seconds\n"; 
      cout << "found = " << c_iter->getData() << "\n";
      
      aTimer.startTimer();
      c_iter = container.find(testclass(keyvals[MAXDATA-1])); 
      aTimer.stopTimer();
      cout << "time taken to find last item in container = "; 
      cout << aTimer.getTimeInterval() << " seconds\n"; 
      cout << "found = " << c_iter->getData() << "\n";

      aTimer.startTimer();
      c_iter = container.find(testclass(MAXDATA)); 
      aTimer.stopTimer();
      cout << "time taken to find item doesn't exist in container = ";
      cout << aTimer.getTimeInterval() << " seconds\n\n"; 
      
      /*****************************************\ 
         demonstrating iterators on data 
      \*****************************************/ 
         
      cout << "TESTING ITERATING\n";
      
      aTimer.startTimer();
      double ave = average(container);
      aTimer.stopTimer();
      cout << "Average = " << ave << "\n";
      cout << "Time to find average = " << aTimer.getTimeInterval() << " seconds\n\n";

      /*****************************************\ 
         test removing data from the container 
      \*****************************************/ 

      cout << "TESTING ERASURE\n";
      
      // erase first item in the vector
      aTimer.startTimer();
      container.pop_front();
      aTimer.stopTimer();
      cout << "pop front of vector takes " << aTimer.getTimeInterval() << " seconds\n";
            
      // erase middle item in the vector
      testclass temp(MAXDATA/2); 
      aTimer.startTimer();
      container.erase(temp); 
      aTimer.stopTimer();
      cout << "erase middle of vector takes " << aTimer.getTimeInterval() << " seconds\n";
            
      // erase last item in the vector
      aTimer.startTimer();
      container.pop_back();
      aTimer.stopTimer();
      cout << "pop back of vector takes " << aTimer.getTimeInterval() << " seconds\n";
        
      cout << "Num items in container = " << container.size() << "\n\n";
   } 
   catch (out_of_range &ex) 
   { 
      cout << "\nERROR - Out of Range Exception thrown\n" << ex.what() << "\n"; 
   } 
   catch(...) 
   { 
      cout << "\nERROR - undefined Exception thrown\n"; 
   } 

   return 0; 
} 

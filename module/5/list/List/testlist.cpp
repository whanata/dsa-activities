#include <iostream>
#include <stdlib.h>
 
#include "timer.h"
#include "list.h"
#include "testclass.h"

using namespace std;
   
double average(const listspc::list<testclass> &container)
{
	listspc::const_iterator<testclass> iter;
   listspc::const_iterator<testclass> enditer = container.end();
   
   double total = 0;
   
   for (iter = container.begin(); iter != enditer; iter++)
   {
      total += iter->getData();
   }
   
   return total / container.size();
}

unsigned int getRand(unsigned int range)
{
   // rand() is 16 bit
   // simple routine to create 32 bit random number
   // in range (0 -> range-1)
   // students are NOT required to know this for subject
   return (((rand() << 16) ^ rand()) % range);
}

int main()
{
   const unsigned int MAXDATA = 1000000; 
   timer aTimer;
   testclass *tc; 
   listspc::list<testclass> container;
   listspc::iterator<testclass> c_iter, e_iter;
   
   int i, keyvals[MAXDATA]; 
   
   try 
   { 
      /*****************************************\ 
         Initialise things to demonstrate the 
         container 
         - fill keyvals and scramble it 
      \*****************************************/ 

      for (i=0; i<MAXDATA; i++) keyvals[i] = i;
      // seed random number generator - don't need to know this
      srand(time(NULL)); 
      for (i=0; i<MAXDATA; i++) 
      {
         swap(keyvals[i], keyvals[getRand(MAXDATA)]); 
      }
      
      /*****************************************\ 
      test inserting MAXDATA data pieces 
      into the container with keyval 0 to 
      MAXDATA-1 in random order 
      \*****************************************/ 
      
      cout << "TESTING INSERTION\n";
            
      // add 10000 ints to front of list
      aTimer.startTimer();
      for (i=0; i<MAXDATA; i++) 
      { 
         tc = new testclass(keyvals[i]); 
         container.push_front(*tc); 
         delete tc;
      } 
      aTimer.stopTimer();
      cout << "push front of " << MAXDATA << " testClass takes " << aTimer.getTimeInterval() << " seconds\n";
            
      // add MAXDATA ints to back of list
      container.clear();
      aTimer.startTimer(); 
      for (i=0; i<MAXDATA; i++) 
      { 
         tc = new testclass(keyvals[i]); 
         container.push_back(*tc); 
         delete tc;
      } 
      aTimer.stopTimer();
      cout << "push back of " << MAXDATA << " testClass takes " << aTimer.getTimeInterval() << " seconds\n";
      cout << "Num items in container = " << container.size() << "\n\n";
      
      /*****************************************\ 
         test list find
      \*****************************************/ 
              
      cout << "TESTING CONTAINER FIND\n";
      
      aTimer.startTimer();
      c_iter = container.find(testclass(keyvals[0])); 
      aTimer.stopTimer();
      cout << "time taken to find first item in container = "; 
      cout << aTimer.getTimeInterval() << " seconds\n"; 
      cout << "found = " << c_iter->getData() << "\n";

      aTimer.startTimer();
      e_iter = container.find(testclass(keyvals[MAXDATA/2])); 
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
         test erasure
      \*****************************************/ 
            
      cout << "TESTING ERASURE\n";
      
      // erase first item in the list
      aTimer.startTimer();
      container.pop_front();
      aTimer.stopTimer();
      
      cout << "pop front of list takes " << aTimer.getTimeInterval() << " seconds\n";
            
      // erase middle item in the list
      aTimer.startTimer();
      container.erase(e_iter);
      aTimer.stopTimer();
      cout << "erase middle of list takes " << aTimer.getTimeInterval() << " seconds\n";
            
      // erase last item in the list
      aTimer.startTimer();
      container.pop_back();
      aTimer.stopTimer();
      cout << "pop back of list takes " << aTimer.getTimeInterval() << " seconds\n";
       
      cout << "Num items in container = " << container.size() << "\n\n";
            
      return 0; 
   }
   catch (out_of_range &ex) 
   { 
      cout << "\nERROR - Out of Range Exception thrown\n" << ex.what() << "\n"; 
   } 
   catch(...) 
   { 
      cout << "\nERROR - undefined Exception thrown\n"; 
   } 
}

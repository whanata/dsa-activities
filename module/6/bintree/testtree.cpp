/*************************************************\ 
   Test program for demonstrating container types 
\*************************************************/ 

#include <stdlib.h>

#include "testclass.h" 
#include "bintree.h" 
#include "timer.h"

using namespace std; 


double average(const treespc::bintree<testclass> &container)
{
	treespc::const_iterator<testclass> iter;
   treespc::const_iterator<testclass> enditer = container.end();
   
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
   testclass *tc; 
   int i, keyvals[MAXDATA]; 
   timer aTimer;
   
   try 
   { 
      treespc::bintree<testclass> container; 
      treespc::const_iterator<testclass> c_iter; 
      
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
      aTimer.startTimer();
      for (i=0; i<MAXDATA; i++) 
      { 
         tc = new testclass(keyvals[i]); 
         container.insert(*tc); 
         delete tc;
      } 
      aTimer.stopTimer();

      cout << MAXDATA << " items in container in random order\n"; 
      cout << "time taken to insert data into container = ";
      cout << aTimer.getTimeInterval() << " seconds\n"; 
      cout << "Num items in container = " << container.size() << "\n\n";

      /*****************************************\ 
         test tree find
      \*****************************************/ 

      cout << "TESTING CONTAINER FIND\n";

      aTimer.startTimer();
      for (i=0; i*100<MAXDATA; i++)
      {
         c_iter = container.find(testclass(keyvals[i*100]));
      }
      aTimer.stopTimer();
      cout << "Average time to find data = ";
      cout << aTimer.getTimeInterval() / i << " seconds\n\n";      
      
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
   
      aTimer.startTimer();
      for (i=0; i*100<MAXDATA; i++)
      {
		  container.erase(testclass(keyvals[i*100]));
      }
      aTimer.stopTimer();
      cout << "Time time to erase " << i << " data = ";
      cout << aTimer.getTimeInterval() << " seconds\n";
      
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

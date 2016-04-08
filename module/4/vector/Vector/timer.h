#include <sys/time.h> 
#include <time.h> 

class timer
{
   private:
      struct timeval first, second; 
            
   public:
      void startTimer()
      {
         gettimeofday(&first, NULL); 
      }
            
      void stopTimer()
      {
         gettimeofday(&second, NULL); 
      }
            
      double getTimeInterval() 
      { 
         // return the difference in seconds, including milli seconds 
         double difsec = second.tv_sec - first.tv_sec; 
         double difmil = second.tv_usec - first.tv_usec; 
            
         return (difsec + difmil / 1000000.0); 
      }    
};

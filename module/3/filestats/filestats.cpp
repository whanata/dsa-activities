#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

bool getMean(const string &file, int &size, double &mean, string &error);
bool getStats(const string &file, int &size, double &mean, double &std, string &error);

int main(int argc, char *argv[])
{
   string file, error="";
   int size;
   double mean, std;
   
   if (argc != 2)
   {
      cout << "Syntax: filestats datafile\n";
   }
   else if (getStats(argv[1], size, mean, std, error))
   {
      cout << "Number of elements in file " << file << " = " << size << "\n";
      cout << "Mean of file = " << mean << "\n";
      cout << "Standard deviation = " << std << "\n";
   }
   else
   {
      cout << "Program failed with the following error\n";
      cout << error << "\n";
   }
   return 0;
}

bool getMean(const string &file, int &size, double &mean, string &error)
{
   ifstream fin;
   double temp, total=0;
   
   // Initialise mean and size
   mean = 0;
   size = 0;
   
   // open stream to file
   fin.open(file.c_str());
   if (!fin) 
   {
      error = "Can't open " +  file;
      return false;
   }
   
   // calculate mean
   while (!fin.eof()) 
   {
      fin >> temp;
      if (fin.good()) 
      {
         total += temp;
         size++;
      } 
      else if (!fin.eof()) 
      {
         error = "Unable to read data from " + file;
         fin.close();
         return false;
      }
   }
   
   // we have finished reading the file, close the stream to it
   fin.close();
   
   // must have at least 1 item to work out mean
   if (size > 0) mean = total / size;
   return true;
}

bool getStats(const string &file, int &size, double &mean, double &std, string &error)
{
   ifstream fin;
   double temp, total = 0;
   
   // Initialise std 
   std = 0;
   
   // get mean and size
   if (!getMean(file, size, mean, error)) return false;
  
   // must have at least 2 items to work out std
   if (size < 2) return true;
   
   // calculate standard deviation
   fin.open(file.c_str());
   
   while (!fin.eof()) 
   {
      fin >> temp;
      if (fin.good()) 
      {
         temp -= mean;
         total += temp * temp;
      }
   }
   fin.close();
   
   // finalise calculation of standard deviation
   std = sqrt(total / (size-1));
   
   return true;
}

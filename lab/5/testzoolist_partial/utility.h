#ifndef _UTILITY_H
#define _UTILITY_H

#include <fstream>
#include <string.h>

using namespace std;

bool readline(ifstream &fin, char *line, int linesize, char delim)
{
   // the problem
   //  Unix ends text lines with \n
   //  Mac ends with \r
   //  Windows ends with \r\n
   // getline does not include the final delimiter
   // BUT, it will leave the \r from a windows file.
   // This means a line read with getline from a windows text file 
   // will have an additional \r tacked to the end of the line. 
   // This is very annoying!!!!
   
   if (fin.eof()) return false;
   
   fin.getline(line, linesize, delim);
   
   // check for \r and get rid of it
   if (!fin.good()) return false;
   int last = strlen(line) - 1;
   if (line >= 0 && line[last] == '\r') line[last] = '\0';
   return true;
}

#endif


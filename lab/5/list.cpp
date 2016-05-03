#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>

#include <list>

#include "person.h"

#include <stdlib.h>

using namespace std;

void sortFamily(dlist<person> &family);
void printFamily(const dlist<person> &family);
void loadFamily(dlist<person> &family, const char *file);

int main(int argc, char *argv[])
{
   list<person> family;

   try
   {
      if (argc != 2) throw runtim_error("Syntax : family family");

      loadFamily(family, argv[1]);
      printFamily(family);
      sortFamily(family);
      printFamily(family);
   }
   catch (exception &ex)
   {
   }

   return 0;
}

void loadFamily(list<person> &family, const char *file)
{
   ifstream fin;
   person member;
   
   fin.open(file);
   if (!fin) throw runtime_error("Unable to read from " + file);
   
   // load family members
   while (!fin.eof()) 
   {
      if (member.loadPerson(fin)) 
      {
         family.push_back(member);
      }
   }
   fin.close();   
}

void printFamily(const list<person> &family)
{
   list<person>::const_iterator itr = family.begin();

   for (; itr != family.end(); itr++) 
   {
      itr->printPerson();
   }
   cout << "\n";
}

void sortFamily(list<person> &family)
{
   /* use insertion sort to order family, 
      in person name order
   */

   list<person>::iterator outer = family.begin(), first, second;
   outer++;
   
   while (outer != family.end()) 
   {
      second = first = outer;
      second--;
      while (second != family.begin()) 
       {
         if (first->getSurname() < second->getSurname()) 
           {
            first->swap(second);
            first--;
            second--;
         }
         else 
           {
            break;
         }
      }
   }
}

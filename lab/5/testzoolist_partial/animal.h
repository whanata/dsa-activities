#ifndef _ANIMAL_H
#define _ANIMAL_H

#include <fstream>
#include <stdexcept>
#include <string>
#include <ctype.h>

#include "utility.h"

using namespace std;

class animal
{
   private:
      string classname, genus, species;
      char line[256];
      
      void loadData(ifstream &fin, string &data)
      {
         if (!readline(fin, line, 256, '\n'))
         {
            throw runtime_error("file corrupted - invalid animal data");
         }
         data = line;
      }
      
   public:
      // constructors =======================================================
      animal()
      {
         classname = genus = species = "";
      }
      
      animal(const char *cn, const char *g, const char *s) :
         classname(cn), genus(g), species(s)
      {
      }
      
      // animal file operations =============================================
      void saveAnimal(ofstream &fout) const
      {
         fout << classname << '\n' << genus << '\n' << species << '\n';
      }
      
      void loadAnimal(ifstream &fin)
      {
         loadData(fin, classname);
         loadData(fin, genus);
         loadData(fin, species);
      }
      
      void printAnimal()
      {
         cout << "class = " << classname << "\n";
         cout << "genus = " << genus << "\n";
         cout << "species = " << species << "\n";
      }
      
      // gettters =========================================================
      const string& getClassname() const { return classname; }
      const string& getGenus() const { return genus; }
      const string& getSpecies() const { return species; }
};

#endif

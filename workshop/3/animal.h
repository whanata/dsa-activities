#ifndef ANIMAL_H 
#define ANIMAL_H

#include <string>

using namespace std;

class animal
{
    private:
        string name;
        string genus;
        string species;

    public:
        animal()
        {
            name = "";
            genus = "";
            species = "";
        }

        animal(string name, string genus, string species)
        {
            this->name = name;
            this->genus = genus;
            this->species = species;
        }

};

#endif
#ifndef STOCK_H 
#define STOCK_H

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <stdexcept> 

#include "animal.h"

using namespace std;

class stock
{
    private:
        animal currentAnimal;
        int stockId;
        char gender;
        string enclosurePen;

    public:
        bool checkInt(string text);
        bool checkChar(string text);
        string getEnclosurePen() const;
        animal getAnimal() const;
        string getString() const;

        stock()
        {
            stockId = 0;
            gender = 0;
            enclosurePen = "";
            currentAnimal = animal();
        }

        stock(string stockId, string gender, string enclosurePen, string name, string genus, string species)   
        {
            if (this->checkInt(stockId))
            {
                this->stockId = atoi(stockId.c_str());
            }
            else
            {
                throw logic_error("Bad stock id: " + stockId);
            }

            if (this->checkChar(gender))
            {
                this->gender = gender[0];
            }
            else
            {
                throw logic_error("Bad gender: " + gender);
            }

            this->enclosurePen = enclosurePen;

            this->currentAnimal = animal(name, genus, species);
        }  
        
};

#endif
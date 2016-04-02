#ifndef STOCK_H 
#define STOCK_H

#include <string.h>
#include <cstdlib>

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

        stock()
        {
            stockId = 0;
            char gender = 0;
            string enclosurePen = "";
        }

        void setStock(string stockId, string gender, string enclosurePen, string name, string genus, string species)
        {
            cout << stockId << "\n";
            // if (this->checkInt(stockId))
            // {
            //     this->stockId = atoi(stockId.c_str());
            // }
        }
        
};

#endif
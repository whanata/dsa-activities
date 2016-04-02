#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

#include "zoo.h"
#include "stock.h"

using namespace std;

void zoo::loadZoo(string file)
{
    ifstream fin;
    string *stringList = new string[6];
    string text = "";
    bool gotSize = false;
    int counter = 0;
    int stockCounter = 0;

    // open stream to file
    fin.open(file.c_str());
    if (!fin) 
    {
        throw runtime_error("Can't open " + file);
    }

    try
    {
        while (!fin.eof()) 
        {
            getline(fin, text);
            if (fin.good()) 
            {
                this->getStock(gotSize, stockCounter, counter, stringList, text);
                this->getSize(gotSize, text);
                // cout << text << "\n";
            } 
            else if (!fin.eof()) 
            {
                fin.close();
                throw runtime_error("Unable to read data from " + file);
            }
        }
    }
    catch (exception &ex)
    {
        cout << "\nERROR - Exception thrown\n" << ex.what() << "\n";
        delete [] stringList;
        fin.close();
    }

    delete [] stringList;
    // we have finished reading the file, close the stream to it
    fin.close();

}

void zoo::getSize(bool &gotSize, string text)
{
    if (!gotSize)
    {
        if (this->checkInt(text))
        {
            this->size = atoi(text.c_str());
            gotSize = true;
        }
        else
        {
            throw logic_error("The first line for the number of stock is not an integer.");
        }
    }
}

void zoo::getStock(bool gotSize, int &stockCounter, int &counter, string *stringList, string text)
{
    if (gotSize == true)
    {
        stringList[counter] = text;
        cout << counter << ": " << text << "\n";

        if (counter >= 5)
        {
            counter = -1;
            for (int i = 0; i < 6; i++)
            {
                // cout << stringList[i] << "\n";
            }
            // cout << stringList[5];
            // stock currentStock = stock(stringList[0], stringList[1], stringList[2], stringList[3], stringList[4], stringList[5]);
            // this->stocks[0] = &currentStock;
            this->stocks[0].setStock(stringList[0], stringList[1], stringList[2], stringList[3], stringList[4], stringList[5]);
            stockCounter ++;

            // stringList[counter] = text;
        }  

        counter ++;
    }
}

void zoo::saveZoo(string file)
{

}

int zoo::getNumstock()
{
    return size;
}

int zoo::numPen(string penId)
{
    return 0;
}

int zoo::numClass(string className)
{
    return 0;
}

bool zoo::checkInt(string text)
{
    string numberSet = "1234567890";
    if (text.size() == strspn(text.c_str(), numberSet.c_str()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool zoo::checkChar(string text)
{
    if (text.size() == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
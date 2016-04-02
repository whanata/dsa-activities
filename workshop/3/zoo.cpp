#include <iostream>
// #include <string>
#include <fstream>
#include <cstdlib>
#include <string.h>

#include "zoo.h"

using namespace std;

void zoo::loadZoo(string file)
{
    ifstream fin;
    string text = "";
    bool gotSize = false;
    int counterStock = 0;

    this->originalFileName = file;

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
            fin >> text;
            if (fin.good()) 
            {
                this->getSize(gotSize, text);

                cout << text << "\n"; 
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
        fin.close();
    }

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

// void zoo::getStock(bool &gotSize, )

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
        // cout << text << "\n";
        return false;
    }
}
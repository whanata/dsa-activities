#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <sstream>

#include "zoo.h"

using namespace std;

void zoo::loadZoo(string file)
{
    ifstream fin;
    string *stringList = new string[6];
    string text = "";
    bool gotSize = false;
    int counter = 0;

    // open stream to file
    fin.open(file.c_str(), ios::in);
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
                this->getStock(gotSize, counter, stringList, text);
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

void zoo::getStock(bool gotSize, int &counter, string *stringList, string text)
{
    if (gotSize == true)
    {
        stringList[counter] = text;
        cout << counter << ": " << text << "\n";

        if (counter >= 5)
        {
            counter = -1;

            this->stocks.pushBack(stock(stringList[0], stringList[1], stringList[2], stringList[3], stringList[4], stringList[5]));
        }  

        counter ++;
    }
}

void zoo::saveZoo(string file)
{
    ofstream fout;

    fout.open(file.c_str(), ios::out);
    if (!fout) 
    {
        throw runtime_error("Can't open " + file);
    }

    try
    {
        fout << this->getString();
    }
    catch (exception &ex)
    {
        cout << "\nERROR - Exception thrown\n" << ex.what() << "\n";
        fout.close();
    }

    fout.close();
}

string zoo::getString() const
{
    listspc::const_iterator<stock> iter;
    listspc::const_iterator<stock> enditer = this->stocks.end();
    stringstream ss;
    string zooString = "";

    ss << this->size;
    zooString = ss.str();
    ss.str("");

    zooString += "\n";

    for (iter = this->stocks.begin(); iter != enditer; iter++)
    {
        zooString += iter->getString() + "\n";
    }

    return zooString;
}

int zoo::getNumstock()
{
    return size;
}

int zoo::numPen(string penId)
{
    listspc::iterator<stock> iter;
    listspc::iterator<stock> enditer = this->stocks.end();
    int counter = 0;

    for (iter = this->stocks.begin(); iter != enditer; iter++)
    {
        if (iter->getEnclosurePen() == penId)
        {
            counter ++;
        }
    }
    return counter;
}

int zoo::numClass(string className)
{
    listspc::iterator<stock> iter;
    listspc::iterator<stock> enditer = this->stocks.end();
    int counter = 0;

    for (iter = this->stocks.begin(); iter != enditer; iter++)
    {
        if (iter->getAnimalName() == className)
        {
            counter ++;
        }
    }
    return counter;
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

listspc::list<stock> *zoo::getPenStock(const string &pen) const
{
    listspc::list<stock> *stocks = new listspc::list<stock>;
    listspc::const_iterator<stock> iter;
    listspc::const_iterator<stock> enditer = this->stocks.end();

    for (iter = this->stocks.begin(); iter != enditer; iter++)
    {
        if (pen == iter->getEnclosurePen())
        {
            stocks->pushBack(*iter);
        }
    }

    if (stocks->size() == 0)
    {
        throw logic_error("No stocks with pen " + pen);
    }

    return stocks;
}

string zoo::getPenStockString(const string &pen) const 
{
    listspc::list<stock> *stocks = this->getPenStock(pen);
    listspc::iterator<stock> iter;
    listspc::iterator<stock> enditer = stocks->end();
    string stockString = "";

    for (iter = stocks->begin(); iter != enditer; iter++)
    {
        stockString += iter->getString() + "\n";
    }

    delete stocks;
    return stockString;
}
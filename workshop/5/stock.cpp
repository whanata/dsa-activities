#include <iostream>
#include <cstdlib>
#include <string.h>
#include <sstream>

#include "stock.h"

using namespace std;

bool stock::checkInt(string text)
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

bool stock::checkChar(string text)
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

string stock::getEnclosurePen() const
{
    return this->enclosurePen;
}

animal stock::getAnimal() const
{
    return this->currentAnimal;
}

string stock::getString() const
{
    stringstream ss;
    string stockIdString = "";
    string genderString = "";

    ss << this->stockId;
    stockIdString = ss.str();
    ss.str("");

    ss << this->gender;
    genderString = ss.str();
    ss.str("");

    return stockIdString + "\n" + genderString + "\n" + this->enclosurePen + "\n" + this->currentAnimal.getString();
}

string stock::getAnimalName() const
{
    return this->currentAnimal.getName();
}
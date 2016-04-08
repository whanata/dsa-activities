#include <iostream>

#include "animal.h"

string animal::getName() const
{
    return this->name;
}

string animal::getString() const
{
    return this->name + "\n" + this->genus + "\n" + this->species;
}
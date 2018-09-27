//
// Created by fonst on Sep 17.
//

#include "person.h"
#include <iostream>
#include <string>

using namespace std;

Person::Person(std::string newName)
{
    name = newName;
}

std::string Person::getName()
{
    return name;
}
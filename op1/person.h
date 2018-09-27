//
// Created by fonst on Sep 17.
//

#pragma once

#include <string>

class Person
{
private:
    std::string name;

public:
    Person(std::string newName);
    std::string getName();
};
//
// Created by fonst on Sep 17.
//

#include "module.h"
#include <iostream>

using namespace std;

void Module::setTeacher(Teacher teacher)
{
    teacher = teacher;
}

void Module::addStudent(Student newStudent)
{
    students.push_back(newStudent);
}

void Module::removeStudent(Student toRemove)
{
    // find student
    // remove it
}

void Module::removeStudent(int toRemove)
{
    students.erase(students.begin() + toRemove);
}

void Module::printPeople()
{
    cout << "Ho there, wanderer!" << endl;
}
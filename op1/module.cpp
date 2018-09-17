//
// Created by fonst on Sep 17.
//

#include "module.h"
#include <iostream>

using namespace std;

bool Module::SetTeacher(Teacher teacher)
{
    teacher = teacher;
}

bool Module::AddStudent(Student newStudent)
{
    students.push_back(newStudent);
}

bool Module::RemoveStudent(Student toRemove)
{
    // find student
    // remove it
}

bool Module::RemoveStudent(int toRemove)
{
    // remove at position
}

void Module::PrintPeople()
{
    cout << "Ho there, wanderer!" << endl;
}
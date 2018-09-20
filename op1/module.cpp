//
// Created by fonst on Sep 17.
//

#include "module.h"
#include <iostream>

using namespace std;

void Module::SetTeacher(Teacher teacher)
{
    teacher = teacher;
}

void Module::AddStudent(Student newStudent)
{
    students.push_back(newStudent);
}

void Module::RemoveStudent(Student toRemove)
{
    // find student
    // remove it
}

void Module::RemoveStudent(int toRemove)
{
    students.erase(students.begin() + toRemove);
}

void Module::PrintPeople()
{
    cout << "Ho there, wanderer!" << endl;
}
//
// Created by fonst on Sep 17.
//

#pragma once

#include <string>
#include <vector>
#include "student.h"
#include "teacher.h"

class Module
{
private:
    std::string name;
    int ec;
    std::vector<Student> students;
    Teacher teacher;

public:
    bool SetTeacher(Teacher teacher);
    bool AddStudent(Student newStudent);
    bool RemoveStudent(Student toRemove);
    bool RemoveStudent(int toRemove);
    void PrintPeople();
};
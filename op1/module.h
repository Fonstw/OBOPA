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
    void SetTeacher(Teacher teacher);
    void AddStudent(Student newStudent);
    void RemoveStudent(Student toRemove);
    void RemoveStudent(int toRemove);
    void PrintPeople();
};
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
    void setTeacher(Teacher teacher);
    void addStudent(Student newStudent);
    void removeStudent(Student toRemove);
    void removeStudent(int toRemove);
    void printPeople();
};
cmake_minimum_required(VERSION 3.12)
project(op1)

set(CMAKE_CXX_STANDARD 14)

add_executable(op1 main.cpp module.cpp module.h person.cpp person.h student.h teacher.h)
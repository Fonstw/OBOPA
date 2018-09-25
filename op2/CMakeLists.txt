cmake_minimum_required(VERSION 3.12)
project(op2)

set(CMAKE_CXX_STANDARD 14)

add_executable(op2 main.cpp cell.cpp cell.h highlife.cpp highlife.h extremes.cpp extremes.h)
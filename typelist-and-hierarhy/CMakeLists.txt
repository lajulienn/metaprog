cmake_minimum_required(VERSION 3.12)
project(typelist)

set(CMAKE_CXX_STANDARD 14)

add_executable(typelist main.cpp typelist.h fibonacci-numbers.h linear-hierarchy.h)
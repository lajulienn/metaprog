cmake_minimum_required(VERSION 3.12)
project(metaprog)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(metaprog
        singletone.cpp task1.cpp)

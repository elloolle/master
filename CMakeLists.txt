cmake_minimum_required(VERSION 3.28)
project(Calculator_of_electric_field)

set(CMAKE_CXX_STANDARD 23)

add_executable(Calculator_of_electric_field main.cpp
        calculator_of_electric_field.h
        vector.h)

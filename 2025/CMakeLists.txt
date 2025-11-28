cmake_minimum_required(VERSION 4.0)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 14)

include_directories(..)

add_executable(AdventOfCode
        src/days/day.cpp
        include/day.h
        src/main.cpp
        src/days/day01.cpp
        include/day01.h
        src/days/dayFactory.cpp
        include/dayFactory.h
        src/days/day02.cpp
        include/day02.h
        ../2025/src/main.cpp)
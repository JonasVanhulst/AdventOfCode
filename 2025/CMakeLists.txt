cmake_minimum_required(VERSION 4.0)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
        ../2025/include
        ../2025/src
        ../2025/src/days
        ../2025/src/utils
        ../2025/inputs
)

set(SRC_FILES
        src/main.cpp
        src/days/day.cpp
        src/days/day01.cpp
        src/days/day02.cpp
        src/days/day03.cpp
        src/days/day05.cpp
        src/days/day06.cpp
        src/days/dayFactory.cpp
        src/utils/utils.cpp
)

add_executable(AdventOfCode ${SRC_FILES})

# file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/inputs)

file(GLOB INPUT_FILES "${PROJECT_SOURCE_DIR}/inputs/*.txt")
foreach(file ${INPUT_FILES})
    configure_file(${file} ${CMAKE_CURRENT_BINARY_DIR}/inputs/ COPYONLY)
endforeach()
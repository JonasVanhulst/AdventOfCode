/******************************************************************************
 * Project Name: AdventOfCode
 * File: main.cpp
 * Author: Jonas Vanhulst
 * Date: 28/11/2025
 ******************************************************************************/

/* ============================
   SYSTEM / STANDARD LIBRARY INCLUDES
   ============================ */
#include <fstream>
#include <iostream>

/* ============================
   PROJECT SPECIFIC INCLUDES
   ============================ */
#include "2024/include/dayFactory.h"
#include "2024/include/utils.h"

int main(int argc, char **argv) {
    constexpr int year = 2024;  // Specify the current Advent of Code year
    AoC_2024::printYear(year);  // Printing the welcome ascii art

    constexpr int day = 1;  // Specify the current day to be solved

    /*
     * requiredFilePath function
     * @args current day and false if it's the complete task, nothing or true if the task is in test phase
     * @returns the correct filepath for the current day
     */
    const std::string filepath = AoC_2024::requiredFilePath(day, false);

    const auto puzzle = AoC_2024::createDay(day);   // Creating the day
    puzzle->welcome();  // Printing the current day in the terminal for the user

    const std::string input = AoC_2024::readFile(filepath); // Reading the file based on the filepath

    /*
     * Solving the day by calling the two functions for both parts
     */
    std::cout << "Part 1: " << std::endl << puzzle->solvePartOne(input) << std::endl;
    std::cout << "Part 2: " << std::endl << puzzle->solvePartTwo(input) << std::endl;
}

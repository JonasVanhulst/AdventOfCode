/******************************************************************************
* Project Name: AdventOfCode
 * File: day01.cpp
 * Author: Jonas Vanhulst
 * Date: 1/12/2025
 ******************************************************************************/

/* ============================
   SYSTEM / STANDARD LIBRARY INCLUDES
   ============================ */
#include <iostream>
#include <sstream>

/* ============================
   PROJECT SPECIFIC INCLUDES
   ============================ */
#include "day01.h"

/**
 * Printing the current day into the terminal
 */
void AoC_2025::day01::welcome(const int day) { std::cout << "Welcome to the Advent of Code 2025 day " << day << "!" << std::endl; }

/**
 * Solving part one of the puzzle
 * @param input
 * @return sum of the puzzle
 */
std::string AoC_2025::day01::solvePartOne(const std::string &input) {
    std::stringstream ss(input);
    std::string line;

    int position = 50;  // Initialising an integer to set the start position at 50
    int countZero = 0;  // Initialising an integer to hold the zeros that are count

    // Reading every line one by one and processes the lin
    while (std::getline(ss, line)) {
        if (line.empty()) continue;

        const char dir = line[0];   // Collecting the direction that is on the first place of the string
        const int value = std::stoi(line.substr(1));    // Collecting the value of the line position

        // Checking direction left or right and correcting the values if needed
        if (dir == 'L') {
            position = (position - value) % 100;
            if (position < 0) position += 100;
        } else {
            position = (position + value) % 100;
        }
        // If the position came on zero add the counter with one
        if (position == 0) countZero++;
    }
    // Returning the total zero counter
    return std::to_string(countZero);
}


/**
 * Solving part two of the puzzle
 * @param input
 * @return sum of the puzzle
 */
std::string AoC_2025::day01::solvePartTwo(const std::string &input) {
    std::stringstream ss(input);
    std::string line;

    int position = 50;  // Initialising an integer to set the start position at 50
    int countZero = 0;  // Initialising an integer to hold the zeros that are count

    // Reading every line one by one and processes the line
    while (std::getline(ss, line)) {
        if (line.empty()) continue;

        const char dir = line[0];   // Collecting the direction that is on the first place of the string
        const int value = std::stoi(line.substr(1));    // Collecting the value of the line position

        for (int i = 0; i < value; ++i) {
            if (dir == 'L') {
                position--; // Decreasing the position
                if (position < 0) position = 99;    // Checking the position and changing it to be in range
            } else { // 'R'
                position++; // Increasing the position
                if (position > 99) position = 0;    // Checking the position and changing it to be in range
            }

            // If the position came on zero add the counter with one
            if (position == 0) countZero++;
        }
    }

    // Returning the total zero counter
    return std::to_string(countZero);
};


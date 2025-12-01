/******************************************************************************
* Project Name: AdventOfCode
 * File: day01.cpp
 * Author: Jonas Vanhulst
 * Date: 28/11/2025
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
void AoC_2025::day01::welcome() { std::cout << "Welcome to day 01!" << std::endl; }

/**
 * Solving part one of the puzzle
 * @param input
 * @return sum of the puzzle
 */
std::string AoC_2025::day01::solvePartOne(const std::string &input) {
    std::stringstream ss(input);
    std::string line;

    int position = 50;
    int countZero = 0;

    while (std::getline(ss, line)) {
        if (line.empty()) continue;

        const char dir = line[0];
        const int value = std::stoi(line.substr(1));

        if (dir == 'L') {
            position = (position - value) % 100;
            if (position < 0) position += 100;
        } else {
            position = (position + value) % 100;
        }

        if (position == 0) countZero++;
    }

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

    int position = 50;
    int countZero = 0;

    while (std::getline(ss, line)) {
        if (line.empty()) continue;

        const char dir = line[0];
        const int value = std::stoi(line.substr(1));

        for (int i = 0; i < value; ++i) {
            if (dir == 'L') {
                position--;
                if (position < 0) position = 99;
            } else { // 'R'
                position++;
                if (position > 99) position = 0;
            }

            if (position == 0) countZero++;
        }
    }

    return std::to_string(countZero);
};
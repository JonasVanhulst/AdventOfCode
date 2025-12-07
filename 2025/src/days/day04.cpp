/******************************************************************************
* Project Name: AdventOfCode
 * File: day03.cpp
 * Author: Jonas Vanhulst
 * Date: 07/12/2025
 ******************************************************************************/

/* ============================
   SYSTEM / STANDARD LIBRARY INCLUDES
   ============================ */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

/* ============================
   PROJECT SPECIFIC INCLUDES
   ============================ */
#include "day04.h"

/**
 * Printing the current day into the terminal
 */
void AoC_2025::day04::welcome() { std::cout << "Welcome to day 04!" << std::endl; }

/**
 * Solving part one of the puzzle
 * @param input
 * @return sum of the puzzle
 */
std::string AoC_2025::day04::solvePartOne(const std::string &input) {
    std::vector<std::pair<long long, long long> > ranges;   // Creating a vector to hold every range
    std::vector<long long> numbers;                         // Creating a vector to hold all the numbers

    std::stringstream ss(input);    // Converting the input string as a stringstream
    std::string line;               // Initialising a string to hold each line data
    bool inNumbers = false;         // Flag to set if its a number
    int isFresh = 0;                // Fresh counter

    // Reading every line
    while (std::getline(ss, line)) {
        if (line.empty()) {
            inNumbers = true;   // If the line is empty we know we can start reading the numbers
            continue;
        }
        // If the flag is false we save the ranges otherwise we save the numbers
        if (!inNumbers) { ranges.push_back(parseNumbers(line)); } else { numbers.push_back(std::stoll(line)); }
    }

    // Checking every number if it fits in a range
    for (const long long number: numbers) {
        bool matched = false;   // Match flag to mark every fit
        for (const auto &range: ranges) {
            if (number >= range.first && number <= range.second) {
                matched = true;
                break;
            }
        }
        if (matched) isFresh++; // If there is a match increase the counter
    }

    // Return the result as a string
    return std::to_string(isFresh);
}

/**
 * Solving part two of the puzzle
 * @param input
 * @return sum of the puzzle
 */
std::string AoC_2025::day04::solvePartTwo(const std::string &input) {
    return "input";
}

/**
 * Function that parses numbers from a stringlist, first it wil check te separator and then convert it to long long variables
 * @param s
 * @return return the two numbers as a long long pair
 */
std::pair<long long, long long> AoC_2025::day04::parseNumbers(const std::string &s) {
    const auto separator = s.find('-'); // Seperator that is used in the inputfile

    long long a = std::stoll(s.substr(0, separator));       // Takes the number from start to seperator and converts it to a long long type
    long long b = std::stoll(s.substr(separator + 1));        // Takes the number from seperator to the end and converts it to a long long type

    return {a, b};
}

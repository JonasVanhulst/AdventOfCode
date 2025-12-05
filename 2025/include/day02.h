/******************************************************************************
* Project Name: AdventOfCode
 * File: day02.h
 * Author: Jonas Vanhulst
 * Date: 05/12/2025
 ******************************************************************************/

#ifndef ADVENTOFCODE_DAY02_H
#define ADVENTOFCODE_DAY02_H

/* ============================
   SYSTEM / STANDARD LIBRARY INCLUDES
   ============================ */
#include <vector>

/* ============================
   PROJECT SPECIFIC INCLUDES
   ============================ */
#include "day.h"

/* ============================
   NAMESPACE WITH CLASS
   ============================ */
namespace AoC_2025 {
    class day02 final : public day {
    public:
        day02() = default; // Default constructor

        ~day02() override = default; // Default destructor

        void welcome() override; // Function that prints into the terminal

        std::string solvePartOne(const std::string &input) override; // Solving the first part of the puzzle

        std::string solvePartTwo(const std::string &input) override; // Solving the second part of the puzzle
    private:
        long long resultPartOne = 0, resultPartTwo = 0; // Initialising two long long variable to store the final result

        std::vector<std::pair<long long, long long> > numbers;  // Creating a vector to store the numbers as a pair
        std::vector<long long> invalidNumbers;                  // Creating a vector of type long long to hold all the invalid numbers

        static std::vector<std::string> split(const std::string &str, char delimiter); // Function to split a string into pieces

        static std::pair<long long, long long> parseNumbers(const std::string &s);  // Function to parse numbers out of a string
    };
} // AoC_2025

#endif //ADVENTOFCODE_DAY02_H

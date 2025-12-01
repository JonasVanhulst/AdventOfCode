/******************************************************************************
* Project Name: AdventOfCode
 * File: day03.h
 * Author: Jonas Vanhulst
 * Date: 1/12/2025
 ******************************************************************************/

#ifndef ADVENTOFCODE_DAY03_H
#define ADVENTOFCODE_DAY03_H

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
namespace AoC_2024 {
    class day03 final : public day {
    public:
        day03() = default; // Default constructor

        ~day03() override = default; // Default destructor

        void welcome() override; // Function that prints into the terminal

        std::string solvePartOne(const std::string &input) override; // Solving the first part of the puzzle

        std::string solvePartTwo(const std::string &input) override; // Solving the second part of the puzzle

    private:
        static std::vector<std::string> findPattern(const std::string &text); // Function to find the required pattern
        static std::pair<int, int> parseMul(const std::string &s); // Function to parse the numbers out of the pattern
        static std::vector<std::string> findMultiPattern(const std::string &text);

        // Function to find the required pattern
    };
} // AoC_2024

#endif //ADVENTOFCODE_DAY03_H

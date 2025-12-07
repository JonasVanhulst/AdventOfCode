/******************************************************************************
* Project Name: AdventOfCode
 * File: day04.h
 * Author: Jonas Vanhulst
 * Date: 07/12/2025
 ******************************************************************************/

#ifndef ADVENTOFCODE_DAY04_H
#define ADVENTOFCODE_DAY04_H

/* ============================
   SYSTEM / STANDARD LIBRARY INCLUDES
   ============================ */

/* ============================
   PROJECT SPECIFIC INCLUDES
   ============================ */
#include "day.h"

/* ============================
   NAMESPACE WITH CLASS
   ============================ */
namespace AoC_2025 {
    class day04 final : public day {
    public:
        day04() = default; // Default constructor

        ~day04() override = default; // Default destructor

        void welcome() override; // Function that prints into the terminal

        std::string solvePartOne(const std::string &input) override; // Solving the first part of the puzzle

        std::string solvePartTwo(const std::string &input) override; // Solving the second part of the puzzle

    private:
        static std::pair<long long, long long> parseNumbers(const std::string &s);  // Function to parse numbers out of a string
    };
} // AoC_2025

#endif //ADVENTOFCODE_DAY03_H

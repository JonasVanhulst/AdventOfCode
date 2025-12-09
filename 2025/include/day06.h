/******************************************************************************
* Project Name: AdventOfCode
 * File: day06.h
 * Author: Jonas Vanhulst
 * Date: 09/12/2025
 ******************************************************************************/

#ifndef ADVENTOFCODE_DAY06_H
#define ADVENTOFCODE_DAY06_H

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
    class day06 final : public day {
    public:
        day06() = default; // Default constructor

        ~day06() override = default; // Default destructor

        void welcome(int day) override; // Function that prints into the terminal

        std::string solvePartOne(const std::string &input) override; // Solving the first part of the puzzle

        std::string solvePartTwo(const std::string &input) override; // Solving the second part of the puzzle

    private:
        #define COLS 4  // Define the amount of data columns

        long long totalPartOne = 0; // Long long counter for the total
    };
} // AoC_2025

#endif //ADVENTOFCODE_DAY06_H

/******************************************************************************
 * Project Name: AdventOfCode
 * File: day01.h
 * Author: Jonas Vanhulst
 * Date: 1/12/2025
 ******************************************************************************/

#ifndef ADVENTOFCODE_DAY01_H
#define ADVENTOFCODE_DAY01_H

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
    class day01 final : public day {
    public:
        day01() = default; // Default constructor

        ~day01() override = default; // Default destructor

        void welcome(int day) override; // Function that prints into the terminal

        std::string solvePartOne(const std::string &input) override; // Solving the first part of the puzzle

        std::string solvePartTwo(const std::string &input) override; // Solving the second part of the puzzle
    };
} // AoC_2025

#endif //ADVENTOFCODE_DAY01_H

/******************************************************************************
* Project Name: AdventOfCode
 * File: day03.h
 * Author: Jonas Vanhulst
 * Date: 07/12/2025
 ******************************************************************************/

#ifndef ADVENTOFCODE_DAY03_H
#define ADVENTOFCODE_DAY03_H

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
    class day03 final : public day {
    public:
        day03() = default; // Default constructor

        ~day03() override = default; // Default destructor

        void welcome() override; // Function that prints into the terminal

        std::string solvePartOne(const std::string &input) override; // Solving the first part of the puzzle

        std::string solvePartTwo(const std::string &input) override; // Solving the second part of the puzzle
    };
} // AoC_2025

#endif //ADVENTOFCODE_DAY03_H

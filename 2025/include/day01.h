/******************************************************************************
 * Project Name: AdventOfCode
 * File: day01.h
 * Author: Jonas Vanhulst
 * Date: 28/11/2025
 ******************************************************************************/

#ifndef ADVENTOFCODE_DAY01_H
#define ADVENTOFCODE_DAY01_H

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
    class day01 final : public day {
    public:
        day01() = default;  // Default constructor

        ~day01() override = default;    // Default destructor

        void welcome() override;    // Function that prints into the terminal

        std::string solvePartOne(const std::string &input) override;    // Solving the first part of the puzzle

        std::string solvePartTwo(const std::string &input) override;    // Solving the second part of the puzzle

    private:
        const int startPosition = 50;
    };
} // AoC_2025

#endif //ADVENTOFCODE_DAY01_H

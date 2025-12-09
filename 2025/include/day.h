/******************************************************************************
* Project Name: AdventOfCode
 * File: day.h
 * Author: Jonas Vanhulst
 * Date: 28/11/2025
 ******************************************************************************/

#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H

/* ============================
   SYSTEM / STANDARD LIBRARY INCLUDES
   ============================ */
#include <string>

/* ============================
   NAMESPACE WITH CLASS
   ============================ */
namespace AoC_2025 {
    class day {
    public:
        day() = default;    // Default constructor

        virtual ~day() = default;   // Default destructor

        virtual void welcome(int day); // Function that prints into the terminal

        virtual std::string solvePartOne(const std::string &input) = 0; // Solving the first part of the puzzle

        virtual std::string solvePartTwo(const std::string &input) = 0; // Solving the second part of the puzzle
    };
} // AoC_2025

#endif //ADVENTOFCODE_DAY_H

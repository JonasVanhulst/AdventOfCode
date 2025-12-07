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
#include "day03.h"

/**
 * Printing the current day into the terminal
 */
void AoC_2025::day03::welcome() { std::cout << "Welcome to day 03!" << std::endl; }

/**
 * Solving part one of the puzzle
 * @param input
 * @return sum of the puzzle
 */
std::string AoC_2025::day03::solvePartOne(const std::string &input) {
    std::stringstream ss(input);    // Creating the stringstream to get each line
    std::string line;               // Creating a string variable to hold the line data
    int total = 0;                  // Initialising an integer total counter to hold te solution

    // Reading every line
    while (std::getline(ss, line)) {
        if (line.empty()) continue; // If a line is empty then continue

        // Converting the string to intergers
        std::vector<int> d(line.size());
        for (int i = 0; i < line.size(); ++i) d[i] = line[i] - '0';

        // Creating the maximum values
        std::vector<int> suf(line.size());
        suf.back() = d.back();
        for (int j = line.size() - 2; j >= 0; --j) { suf[j] = std::max(d[j], suf[j + 1]); }

        // Searching to the highest possible number in the list
        int best = 0;
        for (int i = 0; i < line.size() - 1; ++i) {
            const int A = d[i];         // First max number
            const int B = suf[i + 1];   // Second max number
            best = std::max(best, A * 10 + B);  // Creating the number
        }

        total += best;  // Counting the total
    }

    // Returning the solution as a string
    return std::to_string(total);
}

/**
 * Solving part two of the puzzle
 * @param input
 * @return sum of the puzzle
 */
std::string AoC_2025::day03::solvePartTwo(const std::string &input) {
    std::stringstream ss(input);    // Creating the stringstream to get each line
    std::string line;               // Creating a string variable to hold the line data
    int total = 0;                  // Initialising an integer total counter to hold te solution

    // Reading every line
    while (std::getline(ss, line)) {
        if (line.empty()) continue; // If a line is empty then continue

        int n = static_cast<int>(line.size());
        int need = std::min(12, n); // Now we take 12 digits for each number
        std::string result;
        result.reserve(need);

        int start = 0;
        while (need > 0) {
            // Getting the last digit we can get to create a valid number
            const int windowEnd = n - need;
            char best = '0';
            int bestPos = start;

            for (int i = start; i <= windowEnd; ++i) {
                if (line[i] > best) {
                    best = line[i];
                    bestPos = i;
                    // If we find a 9 which is the maximum we stop
                    if (best == '9') break;
                }
            }

            result.push_back(best);
            start = bestPos + 1;
            --need;
        }
        // Converting the string to a long long
        total += std::stoll(result);
    }

    // Returning the total as a string
    return std::to_string(total);
}

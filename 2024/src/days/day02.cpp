/******************************************************************************
* Project Name: AdventOfCode
 * File: day02.cpp
 * Author: Jonas Vanhulst
 * Date: 1/12/2025
 ******************************************************************************/

/* ============================
   SYSTEM / STANDARD LIBRARY INCLUDES
   ============================ */
#include <iostream>
#include <sstream>
#include <vector>

/* ============================
   PROJECT SPECIFIC INCLUDES
   ============================ */
#include "day02.h"

/**
 * Printing the current solving day
 */
void AoC_2024::day02::welcome() { std::cout << "Welcome to day 02!" << std::endl; }

/**
 * Solving part one of the puzzle
 * @param input
 * @return sum of the puzzle
 */
std::string AoC_2024::day02::solvePartOne(const std::string &input) {
    std::stringstream ss(input);    // Converting the input to stringstream to handle the mixed string easily
    std::string line;               // Creating a temp line
    int safeCounter = 0;            // Initialising the safe counter

    // Looping through every line
    while (std::getline(ss, line)) {
        if (line.empty()) continue; // If the line is empty continue the process

        std::vector<int> nums;  // Initialising an integer vector to store all the found numbers of each line
        int number = -1;        // Initialising a number with the value of -1 to identify no numbers are found

        // Checking every digit in the founded line
        for (int i = 0; i < line.length(); i++) {
            if (isdigit(line[i])) {
                if (number == -1) number = 0;
                number = number * 10 + (line[i] - '0'); // Checking for numbers longer than 1 digit
            } else {
                if (number != -1) {
                    nums.push_back(number); // Adding the single digits to the vector
                    number = -1;
                }
            }
        }

        if (number != -1) nums.push_back(number);   // Adding every correct number to the vector
        if (nums.size() < 2) continue;

        const int firstDiff = nums[1] - nums[0];    // Checking if it is increasing or decreasing
        if (firstDiff == 0) continue;

        const bool increasing = firstDiff > 0;      // Holding the result into a boolean
        bool safe = true;                           // Initialising a safe counter of type boolean

        // Looping over every number that has been stored in the vector list
        for (int i = 0; i < nums.size() - 1; i++) {
            const int diff = nums[i + 1] - nums[i]; // Calculating the difference

            // Checking the conditions
            if (diff == 0) {
                safe = false;
                break;
            }

            // Checking the conditions
            if (increasing && diff < 0) {
                safe = false;
                break;
            }

            // Checking the conditions
            if (!increasing && diff > 0) {
                safe = false;
                break;
            }

            // Checking the conditions
            if (std::abs(diff) < 1 || std::abs(diff) > 3) {
                safe = false;
                break;
            }
        }

        // With every safe result, increase the counter with one
        if (safe) safeCounter++;
    }

    return std::to_string(safeCounter);
}

/**
 * Solving part two of the puzzle
 * @param input
 * @return sum of the puzzle
 */
std::string AoC_2024::day02::solvePartTwo(const std::string &input) {
    std::stringstream ss(input);    // Converting the input to stringstream to handle the mixed string easily
    std::string line;               // Creating a temp line
    int safeCounter = 0;            // Initialising the safe counter

    // Looping through every line
    while (std::getline(ss, line)) {
        if (line.empty()) continue; // If the line is empty continue the process

        std::vector<int> nums;  // Initialising an integer vector to store all the found numbers of each line
        int number = -1;        // Initialising a number with the value of -1 to identify no numbers are found

        // Checking every digit in the founded line
        for (int i = 0; i < line.length(); i++) {
            if (isdigit(line[i])) {
                if (number == -1) number = 0;
                number = number * 10 + (line[i] - '0'); // Checking for numbers longer than 1 digit
            } else {
                if (number != -1) {
                    nums.push_back(number); // Adding the single digits to the vector
                    number = -1;
                }
            }
        }
        if (number != -1) nums.push_back(number);   // Adding every correct number to the vector

        // 1. If the number is safe, increase the counter
        if (isSafe(nums)) {
            safeCounter++;
            continue;
        }

        // 2. Trying to remove a single digit to make it safe
        bool becameSafe = false;
        for (int i = 0; i < nums.size(); i++) {
            std::vector<int> modified = nums;
            modified.erase(modified.begin() + i);

            if (isSafe(modified)) {
                becameSafe = true;  // Line has been become safe
                break;
            }
        }

        // If the line became safe, then increase the counter
        if (becameSafe) safeCounter++;
    }

    return std::to_string(safeCounter);
}

/**
 * Checking the numbers are safe (increasing or decreasing by 1,2 or 3)
 * @param nums
 * @return safe or not
 */
bool AoC_2024::day02::isSafe(const std::vector<int> &nums) {
    if (nums.size() < 2) return false;

    const int diff = nums[1] - nums[0];
    if (diff == 0) return false;

    // Checking for increasing or decreasing
    const bool increasing = diff > 0;

    // Checking every number in the list
    for (int i = 0; i < nums.size() - 1; i++) {
        const int d = nums[i + 1] - nums[i];

        /* Checking for safety rules */
        if (d == 0) return false;
        if (increasing && d < 0) return false;
        if (!increasing && d > 0) return false;
        if (std::abs(d) < 1 || std::abs(d) > 3) return false;
    }

    return true;
}

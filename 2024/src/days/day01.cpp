/******************************************************************************
* Project Name: AdventOfCode
 * File: day01.cpp
 * Author: Jonas Vanhulst
 * Date: 28/11/2025
 ******************************************************************************/

/* ============================
   SYSTEM / STANDARD LIBRARY INCLUDES
   ============================ */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

/* ============================
   PROJECT SPECIFIC INCLUDES
   ============================ */
#include "2024/include/day01.h"

/**
 * Printing the current day into the terminal
 */
void AoC_2024::day01::welcome() { std::cout << "Welcome to dag 01!" << std::endl; }

/**
 * Solving part one of the puzzle
 * @param input
 * @return sum of the puzzle
 */
std::string AoC_2024::day01::solvePartOne(const std::string &input) {
    /* Clearing the vectors */
    frontNumbers.clear();
    backNumbers.clear();

    /* Reserving space for the vectors */
    frontNumbers.reserve(input.size() / 4);
    backNumbers.reserve(input.size() / 4);

    int current = 0;        // Initialising an integer to hold the current number
    bool inNumber = false;  // Initialising a boolean to define if the number is an integer
    bool leftSide = true;   // Initialising a boolean to define if the number is on the left side or not
    int sum = 0;            // Initialising an integer hold the total sum of the puzzle

    /* Looping through the input string to find the numbers */
    for (const char c: input) {
        /* Checking ig the character is an integer or not */
        if (std::isdigit(c)) {
            current = current * 10 + (c - '0'); // Converting the string number to the correct integer
            inNumber = true;    // Integer found
        } else if (inNumber) {
            /* When an integer is found, this number will be stored on the correct side starting with the left side */
            if (leftSide) { frontNumbers.push_back(current); } else { backNumbers.push_back(current); }

            leftSide = not leftSide;    // Toggling the side
            current = 0;                // Reset the current number
            inNumber = false;           // Deactivating the integer check flag
        }
    }

    /* Checking the last number */
    if (inNumber) {
        /* When an integer is found, this number will be stored on the correct side starting with the left side */
        if (leftSide) { frontNumbers.push_back(current); } else { backNumbers.push_back(current); }
    }

    /* Sorting both vector starting with the smallest number at the first index and the biggest number on the last */
    std::sort(frontNumbers.begin(), frontNumbers.end());
    std::sort(backNumbers.begin(), backNumbers.end());

    /* Calculating the sum, calculating the distance between the numbers at both indexes and store the distance in the sum */
    for (size_t i = 0; i < frontNumbers.size(); ++i) { sum += std::abs(frontNumbers[i] - backNumbers[i]); }

    /* Returning the sum as a string */
    return std::to_string(sum);
};

/**
 * Solving part two of the puzzle
 * @param input
 * @return sum of the puzzle
 */
std::string AoC_2024::day01::solvePartTwo(const std::string &input) {
    /* Clearing the vectors */
    frontNumbers.clear();
    backNumbers.clear();

    /* Reserving space for the vectors */
    frontNumbers.reserve(input.size() / 4);
    backNumbers.reserve(input.size() / 4);

    int current = 0;        // Initialising an integer to hold the current number
    bool inNumber = false;  // Initialising a boolean to define if the number is an integer
    bool leftSide = true;   // Initialising a boolean to define if the number is on the left side or not
    int sum = 0;            // Initialising an integer hold the total sum of the puzzle

    /* Looping through the input string to find the numbers */
    for (const char c: input) {
        /* Checking ig the character is an integer or not */
        if (std::isdigit(c)) {
            current = current * 10 + (c - '0'); // Converting the string number to the correct integer
            inNumber = true;    // Integer found
        } else if (inNumber) {
            /* When an integer is found, this number will be stored on the correct side starting with the left side */
            if (leftSide) { frontNumbers.push_back(current); } else { backNumbers.push_back(current); }

            leftSide = not leftSide;    // Toggling the side
            current = 0;                // Reset the current number
            inNumber = false;           // Deactivating the integer check flag
        }
    }

    /* Checking the last number */
    if (inNumber) { if (leftSide) { frontNumbers.push_back(current); } else { backNumbers.push_back(current); } }

    /* Sorting both vector starting with the smallest number at the first index and the biggest number on the last */
    std::sort(frontNumbers.begin(), frontNumbers.end());
    std::sort(backNumbers.begin(), backNumbers.end());

    /* Checking every number in the lists */
    for (const int number: frontNumbers) {
        int equalCount = 0; // Holding a equal counter
        /* With each equal number, the counter will be changed */
        for (const int backNumber: backNumbers) { if (number == backNumber) { equalCount++; } }
        sum += number * equalCount; // Calculating the sum, by multiplying the current number with the equal counter
    }

    /* Returning the sum as a string */
    return std::to_string(sum);
};
/******************************************************************************
* Project Name: AdventOfCode
 * File: utils.h
 * Author: Jonas Vanhulst
 * Date: 28/11/2025
 ******************************************************************************/

#ifndef ADVENTOFCODE_UTILS_H
#define ADVENTOFCODE_UTILS_H

/* ============================
   SYSTEM / STANDARD LIBRARY INCLUDES
   ============================ */
#include <string>

/* ============================
   NAMESPACE WITH CLASS
   ============================ */
namespace AoC_2024{
    void printYear(int year);   // Function to print the current year

    std::string requiredFilePath(int currentDay, bool isTest = true);   // Function to return the correct filepath based on the current day

    std::string readFile(const std::string &filepath);  // Function to read the given file and return everything as a string
} // AoC_2024

#endif //ADVENTOFCODE_UTILS_H

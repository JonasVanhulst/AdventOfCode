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
namespace AoC_2025{
    void printYear(int year);   // Function to print the current year

    std::string requiredFilePath(int currentDay, bool isTest = true);

    std::string readFile(const std::string &filepath);
} // AoC_2025

#endif //ADVENTOFCODE_UTILS_H

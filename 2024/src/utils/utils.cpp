/******************************************************************************
* Project Name: AdventOfCode
 * File: utils.cpp
 * Author: Jonas Vanhulst
 * Date: 1/12/2025
 ******************************************************************************/

/* ============================
   SYSTEM / STANDARD LIBRARY INCLUDES
   ============================ */
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

/* ============================
   PROJECT SPECIFIC INCLUDES
   ============================ */
#include "utils.h"
#include "inputFiles.h"

/**
 * Printing a nice header with the current advent of code year
 * @param year
 * @return void
 */
void AoC_2024::printYear(const int year) {
    std::cout << "==============================\n";
    std::cout << "      Advent of Code " << year << "\n";
    std::cout << "==============================\n";
}

/**
 *  Function to return the correct file to the system based on the day and type
 * @param currentDay - gives the current day of the exercise
 * @param isTest - gives the command to load the real or test file
 * @return string of the filepath
 */
std::string AoC_2024::requiredFilePath(const int currentDay, const bool isTest) {
    switch (currentDay) {
        case 1: return isTest ? DAY_1_TEST_INPUT : DAY_1_REAL_INPUT;
        case 2: return isTest ? DAY_2_TEST_INPUT : DAY_2_REAL_INPUT;
        case 3: return isTest ? DAY_3_TEST_INPUT : DAY_3_REAL_INPUT;
        case 4: return isTest ? DAY_4_TEST_INPUT : DAY_4_REAL_INPUT;
        case 5: return isTest ? DAY_5_TEST_INPUT : DAY_5_REAL_INPUT;
        case 6: return isTest ? DAY_6_TEST_INPUT : DAY_6_REAL_INPUT;
        case 7: return isTest ? DAY_7_TEST_INPUT : DAY_7_REAL_INPUT;
        case 8: return isTest ? DAY_8_TEST_INPUT : DAY_8_REAL_INPUT;
        case 9: return isTest ? DAY_9_TEST_INPUT : DAY_9_REAL_INPUT;
        case 10: return isTest ? DAY_10_TEST_INPUT : DAY_10_REAL_INPUT;
        case 11: return isTest ? DAY_11_TEST_INPUT : DAY_11_REAL_INPUT;
        case 12: return isTest ? DAY_12_TEST_INPUT : DAY_12_REAL_INPUT;
        case 13: return isTest ? DAY_13_TEST_INPUT : DAY_13_REAL_INPUT;
        case 14: return isTest ? DAY_14_TEST_INPUT : DAY_14_REAL_INPUT;
        case 15: return isTest ? DAY_15_TEST_INPUT : DAY_15_REAL_INPUT;
        case 16: return isTest ? DAY_16_TEST_INPUT : DAY_16_REAL_INPUT;
        case 17: return isTest ? DAY_17_TEST_INPUT : DAY_17_REAL_INPUT;
        case 19: return isTest ? DAY_19_TEST_INPUT : DAY_19_REAL_INPUT;
        case 20: return isTest ? DAY_20_TEST_INPUT : DAY_20_REAL_INPUT;
        case 21: return isTest ? DAY_21_TEST_INPUT : DAY_21_REAL_INPUT;
        case 22: return isTest ? DAY_22_TEST_INPUT : DAY_22_REAL_INPUT;
        case 18: return isTest ? DAY_18_TEST_INPUT : DAY_18_REAL_INPUT;
        case 23: return isTest ? DAY_23_TEST_INPUT : DAY_23_REAL_INPUT;
        case 24: return isTest ? DAY_24_TEST_INPUT : DAY_24_REAL_INPUT;
        case 25: return isTest ? DAY_25_TEST_INPUT : DAY_25_REAL_INPUT;

        default:
            throw std::runtime_error("Invalid day: " + std::to_string(currentDay));
    }
}

/**
 * Function to read the file and return the data as a string buffer
 * @param filepath - the filepath that has the correct day
 * @return string - data buffer
 */
std::string AoC_2024::readFile(const std::string &filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open the file: " + filepath);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

/******************************************************************************
* Project Name: AdventOfCode
 * File: day02.cpp
 * Author: Jonas Vanhulst
 * Date: 05/12/2025
 ******************************************************************************/

/* ============================
   SYSTEM / STANDARD LIBRARY INCLUDES
   ============================ */
#include <iostream>
#include <sstream>

/* ============================
   PROJECT SPECIFIC INCLUDES
   ============================ */
#include "day02.h"

/**
 * Printing the current day into the terminal
 */
void AoC_2025::day02::welcome() { std::cout << "Welcome to day 02!" << std::endl; }

/**
 * Solving part one of the puzzle
 * @param input
 * @return sum of the puzzle
 */
std::string AoC_2025::day02::solvePartOne(const std::string &input) {
    constexpr char delimiter = ','; // Defining the delimiter
    const std::vector<std::string> result = split(input, delimiter);
    // Storing the returned values into the result vector

    numbers.reserve(result.size()); // reserving enough data into the number list
    for (const auto &part: result) { numbers.push_back(parseNumbers(part)); }
    // Now every part in the numbers will be parsed into two values

    // Looping over every number pair in the numbers vector
    for (const auto &number: numbers) {
        for (long long i = number.first; i <= number.second; i++) {
            std::string numberStr = std::to_string(i); // Converting every number to a string
            const size_t strSize = numberStr.size(); // Calculating the size

            // Checking the numbers for the same sequence with 2
            if (strSize % 2 == 0) {
                const std::string pattern = numberStr.substr(0, strSize / 2); // Collecting the pattern to compare

                std::string repeated;
                for (int j = 0; j < 2; ++j) { repeated += pattern; }
                // If it is compared check and if they are the same push the value into the invalid vector
                if (repeated == numberStr) { invalidNumbers.push_back(i); }
            }
        }
    }

    // Adding up every invalid number to get the result
    for (const auto &invalid: invalidNumbers) { resultPartOne += invalid; }

    return std::to_string(resultPartOne);
}

/**
 * Solving part two of the puzzle
 * @param input
 * @return sum of the puzzle
 */
std::string AoC_2025::day02::solvePartTwo(const std::string &input) {
    /* Clearing the vectors and results */
    numbers.clear();
    invalidNumbers.clear();
    resultPartTwo = 0;

    constexpr char delimiter = ','; // Defining the delimiter
    const std::vector<std::string> result = split(input, delimiter);
    // Storing the returned values into the result vector

    numbers.reserve(result.size()); // reserving enough data into the number list
    for (const auto &part: result) { numbers.push_back(parseNumbers(part)); }
    // Now every part in the numbers will be parsed into two values

    // Looping over every number pair in the numbers vector
    for (const auto &number: numbers) {
        for (long long i = number.first; i <= number.second; i++) {
            std::string numberStr = std::to_string(i); // Converting every number to a string
            const size_t strSize = numberStr.size(); // Calculating the size
            // Now we create an extra for loop to get all the possible lengths of sequence length
            for (size_t k = 1; k <= strSize / 2; k++) {
                if (strSize % k == 0) {
                    const size_t repeats = strSize / k;
                    if (repeats < 2) continue; // must repeat at least twice

                    const std::string pattern = numberStr.substr(0, k); // Collecting the pattern to compare

                    std::string repeated;
                    repeated.reserve(strSize);
                    // Collecting the pattern to compare
                    for (size_t j = 0; j < repeats; ++j)
                        repeated += pattern;

                    // If it is compared check and if they are the same push the value into the invalid vector and break for the next one
                    if (repeated == numberStr) {
                        invalidNumbers.push_back(i);
                        break;
                    }
                }
            }
        }
    }
    for (const auto &invalid: invalidNumbers) { resultPartTwo += invalid; }
    return std::to_string(resultPartTwo);
}

/**
 * Function that splits the input based on the delimiter
 * @param str - input string
 * @param delimiter - delimiter character
 * @return tokens of the split string as a string
 */
std::vector<std::string> AoC_2025::day02::split(const std::string &str, const char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (getline(ss, token, delimiter)) { tokens.push_back(token); }
    return tokens;
}

/**
 * Function that parses numbers from a stringlist, first it wil check te separator and then convert it to long long variables
 * @param s
 * @return return the two numbers as a long long pair
 */
std::pair<long long, long long> AoC_2025::day02::parseNumbers(const std::string &s) {
    const auto separator = s.find('-'); // Seperator that is used in the inputfile

    long long a = std::stoll(s.substr(0, separator));
    // Takes the number from start to seperator and converts it to a long long type
    long long b = std::stoll(s.substr(separator + 1));
    // Takes the number from seperator to the end and converts it to a long long type

    return {a, b};
}

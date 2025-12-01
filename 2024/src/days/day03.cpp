/******************************************************************************
* Project Name: AdventOfCode
 * File: day03.cpp
 * Author: Jonas Vanhulst
 * Date: 1/12/2025
 ******************************************************************************/

/* ============================
   SYSTEM / STANDARD LIBRARY INCLUDES
   ============================ */
#include <iostream>
#include <sstream>
#include <regex>

/* ============================
   PROJECT SPECIFIC INCLUDES
   ============================ */
#include "day03.h"

/**
 * Printing the current solving day
 */
void AoC_2024::day03::welcome() { std::cout << "Welcome to day 03!" << std::endl; }

/**
 * Solving part one of the puzzle
 * @param input
 * @return sum of the puzzle
 */
std::string AoC_2024::day03::solvePartOne(const std::string &input) {
    const auto found = findPattern(input); // Collecting the patterns

    std::vector<std::pair<int, int> > result; // Vector pair to store the two numbers

    for (const auto &c: found) {
        result.push_back(parseMul(c)); // Saving the numbers that come from the parser
    }

    long long total = 0;
    for (const auto p: result) {
        total += p.first * p.second; // Multiplying the numbers
    }

    return std::to_string(total); // Returning the total sum
}

/**
 * Solving part two of the puzzle
 * @param input
 * @return sum of the puzzle
 */
std::string AoC_2024::day03::solvePartTwo(const std::string &input) {
    const auto found = findMultiPattern(input); // Collecting the patterns

    std::vector<std::pair<int, int> > result; // Vector pair to store the two numbers

    for (const auto &c: found) {
        result.push_back(parseMul(c)); // Saving the numbers that come from the parser
    }

    long long total = 0;
    for (const auto p: result) {
        total += p.first * p.second; // Multiplying the numbers
    }

    return std::to_string(total); // Returning the total sum
}

/**
 * Function to find a regex pattern from an input
 * @param text
 * @return vector of type string with the multiplexers
 */
std::vector<std::string> AoC_2024::day03::findPattern(const std::string &text) {
    std::vector<std::string> results; // Initialising a vector to store all the patterns

    const std::regex pattern(R"(mul\(([0-9]+),([0-9]+)\))"); // Pattern template
    std::smatch matches; // Creating a match object

    auto searchStart(text.cbegin()); // Starting the regex search

    // If the search found the pattern, save this to the vector
    while (std::regex_search(searchStart, text.cend(), matches, pattern)) {
        results.push_back(matches[0]);
        searchStart = matches.suffix().first;
    }

    return results;
}

/**
 * Function to parse the multiplexers from strings to integers
 * @param s
 * @return integer pair
 */
std::pair<int, int> AoC_2024::day03::parseMul(const std::string &s) {
    const auto start = s.find("("); // Defining the startpoint
    const auto comma = s.find(','); // Defining the holding point
    const auto end = s.find(')'); // Defining the end point

    // Converting the strings to the correct number
    int a = std::stoi(s.substr(start + 1, comma - (start + 1)));
    int b = std::stoi(s.substr(comma + 1, end - (comma + 1)));

    return {a, b};
}

/**
 * Function to find multiple regex patterns in a text
 * @param text
 * @return vector of type string with the multiplexers
 */
std::vector<std::string> AoC_2024::day03::findMultiPattern(const std::string &text) {
    std::vector<std::string> results;

    // One regex that matches either mul(...) or do()/don't()
    const std::regex tokenPattern(R"(mul\(([0-9]+),([0-9]+)\)|do\(\)|don't\(\))");

    bool enabled = true; // Start with doing the instructions
    std::smatch matches; // Creating the match object
    auto searchStart = text.cbegin(); // Starting the search from the beginning

    // If the search found the pattern, save this to the vector
    while (std::regex_search(searchStart, text.cend(), matches, tokenPattern)) {
        std::string token = matches[0];

        // If we find a do we enable the operator
        if (token == "do()") {
            enabled = true;
        } else if (token == "don't()") {
            // If we find a don't we disable the operator
            enabled = false;
        } else if (token.rfind("mul", 0) == 0) {
            // starts with "mul"
            if (enabled) {
                results.push_back(token); // Saving the multiplexers
            }
        }

        // Advance past this match
        searchStart = matches.suffix().first;
    }

    return results;
}

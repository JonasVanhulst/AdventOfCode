/******************************************************************************
* Project Name: AdventOfCode
 * File: day06.cpp
 * Author: Jonas Vanhulst
 * Date: 09/12/2025
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
#include "day06.h"

/**
 * Printing the current day into the terminal
 */
void AoC_2025::day06::welcome(const int day) { std::cout << "Welcome to the Advent of Code 2025 day " << day << "!" << std::endl; }

/**
 * Solving part one of the puzzle
 * @param input
 * @return sum of the puzzle
 */
std::string AoC_2025::day06::solvePartOne(const std::string &input) {
    std::istringstream iss(input);  // Creating the string stream from the input to handle it easily
    std::string line;               // String to hold every line data

    // Dynamic vectors for columns
    std::vector<std::vector<int>> numbers;
    std::vector<char> tokens;

    // Parsing the input and saving the numbers and tokens into the vectors
    while (std::getline(iss, line)) {
        std::istringstream lineStream(line);
        std::string tok;
        int col = 0;
        bool hasNumbers = false;

        while (lineStream >> tok) {
            try {
                int value = std::stoi(tok);
                // Creating the correct amount of storage
                if (col >= numbers.size()) numbers.resize(col + 1);
                numbers[col].push_back(value); // Saving each column
                col++;  // Increasing the column counter
                hasNumbers = true;  // Flagging if a number is detected
            } catch (const std::invalid_argument &) {
                // When there is no integer found we can save the token into the token-vector
                if (!hasNumbers) {
                    // Checking if the current token is a + or *, other tokens are invalid
                    for (char c : tok) {
                        if (c == '+' || c == '*') {
                            if (tokens.size() <= col) tokens.resize(col + 1);
                            tokens[col] = c;
                            col++;
                        }
                    }
                }
            }
        }
    }

    // Calculating the total sum and product form each line
    for (size_t col = 0; col < numbers.size(); col++) {
        char op = (col < tokens.size()) ? tokens[col] : '+';
        switch (op) {
            case '*': {
                // CASE: MULTIPLYING
                long long product = 1;  // Start with one, if we start with zero we are stuck on zero
                for (int value : numbers[col]) {
                    product *= value;   // Multiplying ever number
                }
                totalPartOne += product;    // Adding the product to the total
                break;
            }
            case '+': {
                // CASE: SUM
                long long sum = 0;  // In this case we can start from 0
                for (int value : numbers[col]) {
                    sum += value;   // Calculating the sum of each number
                }
                totalPartOne += sum;    // Adding the sum to the total
                break;
            }
            default:
                break;
        }
    }

    // Returning the total as a string
    return std::to_string(totalPartOne);
}


/**
 * Solving part two of the puzzle
 * @param input
 * @return sum of the puzzle
 */
std::string AoC_2025::day06::solvePartTwo(const std::string &input) {
    return std::to_string(0);
}

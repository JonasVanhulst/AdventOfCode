//
// Created by Vanhuljo on 28/11/2025.
//

#include <iostream>

#include "2025/include/dayFactory.h"

void printYear(const int year) {
    std::cout << "==============================\n";
    std::cout << "      Advent of Code " << year << "\n";
    std::cout << "==============================\n";
}

std::string readFile(const std::string &fileName) {
    return fileName.substr(0, fileName.find(".txt"));
}

int main(int argc, char ** argv) {
    constexpr int year = 2025;
    printYear(year);

    constexpr int day = 1;
    const std::string fileName = "test.txt";

    const auto puzzle = AoC_2025::createDay(day);

    const std::string input = readFile(fileName);

    std::cout << "Part 1: " << puzzle->solvePartOne(input) << std::endl;
    std::cout << "Part 1: " << puzzle->solvePartTwo(input) << std::endl;
}

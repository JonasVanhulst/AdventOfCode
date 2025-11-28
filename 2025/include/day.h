//
// Created by Vanhuljo on 28/11/2025.
//

#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H
#include <string>

namespace AoC_2025 {
    class day {
        public:
            virtual ~day() = default;
            virtual std::string solvePartOne(const std::string &input) = 0;
            virtual std::string solvePartTwo(const std::string &input) = 0;
    };
} // AoC_2025

#endif //ADVENTOFCODE_DAY_H
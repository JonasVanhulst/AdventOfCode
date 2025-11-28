//
// Created by Vanhuljo on 28/11/2025.
//

#include "dayFactory.h"

#include <stdexcept>

#include "day01.h"
#include "day02.h"

namespace AoC_2024 {
    std::unique_ptr<day> createDay(const int currentDay) {
        switch (currentDay) {
            case 1: return std::make_unique<day01>();
            case 2: return std::make_unique<day02>();
            default: throw std::runtime_error("Unknown day");
        }
    }
} // AoC_2024

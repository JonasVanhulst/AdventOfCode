/******************************************************************************
* Project Name: AdventOfCode
 * File: dayFactory.cpp
 * Author: Jonas Vanhulst
 * Date: 1/12/2025
 ******************************************************************************/

/* ============================
   SYSTEM / STANDARD LIBRARY INCLUDES
   ============================ */
#include <memory>
#include <stdexcept>

/* ============================
   PROJECT SPECIFIC INCLUDES
   ============================ */
#include "day.h"
#include "day01.h"
#include "day02.h"
#include "day03.h"
#include "day05.h"
#include "day06.h"

/* ============================
   NAMESPACE
   ============================ */
namespace AoC_2025 {
    /**
     * Function to create the correct day object call to start the day
     * @param currentDay
     * @return correct class to handle the day exercise
     */
    std::unique_ptr<day> createDay(const int currentDay) {
        switch (currentDay) {
            case 1: return std::make_unique<day01>();
            case 2: return std::make_unique<day02>();
            case 3: return std::make_unique<day03>();
            case 5: return std::make_unique<day05>();
            case 6: return std::make_unique<day06>();
            default: throw std::runtime_error("Unknown day");
        }
    }
} // AoC_2025

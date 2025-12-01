/******************************************************************************
* Project Name: AdventOfCode
 * File: dayFactory.h
 * Author: Jonas Vanhulst
 * Date: 1/12/2025
 ******************************************************************************/

#ifndef ADVENTOFCODE_DAYFACTORY_H
#define ADVENTOFCODE_DAYFACTORY_H

/* ============================
   SYSTEM / STANDARD LIBRARY INCLUDES
   ============================ */
#include <memory>

/* ============================
   PROJECT SPECIFIC INCLUDES
   ============================ */
#include "day.h"

/* ============================
   NAMESPACE WITH CLASS
   ============================ */
namespace AoC_2025 {
    std::unique_ptr<day> createDay(int currentDay);
} // AoC_2025

#endif //ADVENTOFCODE_DAYFACTORY_H

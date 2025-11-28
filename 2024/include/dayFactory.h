//
// Created by Vanhuljo on 28/11/2025.
//

#ifndef ADVENTOFCODE_DAYFACTORY_H
#define ADVENTOFCODE_DAYFACTORY_H

#include <memory>
#include "day.h"

namespace AoC_2024 {
    std::unique_ptr<day> createDay(int currentDay);
} // AoC_2024

#endif //ADVENTOFCODE_DAYFACTORY_H

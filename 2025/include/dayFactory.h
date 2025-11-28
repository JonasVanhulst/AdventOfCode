//
// Created by Vanhuljo on 28/11/2025.
//

#ifndef ADVENTOFCODE_DAYFACTORY_H
#define ADVENTOFCODE_DAYFACTORY_H

#pragma once
#include <memory>
#include "day.h"

namespace AoC_2025 {
    std::unique_ptr<day> createDay(int currentDay);
}

#endif //ADVENTOFCODE_DAYFACTORY_H
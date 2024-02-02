#ifndef GEAR_RATIOS_H
#define GEAR_RATIOS_H

#include "adventofcode2023.h"

class Gear_Ratios : public AdventOfCode2023 {
public:
    Gear_Ratios(int dayNumber) : AdventOfCode2023(dayNumber) {}

    void process_exercise(const QString &filePath) override;

    int process_task_one(const QString &line) override;

    int process_task_two(const QString &line) override;
};

#endif // GEAR_RATIOS_H

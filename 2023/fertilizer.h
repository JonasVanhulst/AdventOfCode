#ifndef FERTILIZER_H
#define FERTILIZER_H

#include "adventofcode2023.h"

class Fertilizer : public AdventOfCode2023
{
public:
    Fertilizer(int dayNumber) : AdventOfCode2023(dayNumber) {}

    void process_exercise(const QString &filePath) override;

    int process_task_one(const QString &line) override;

    int process_task_two(const QString &line) override;
};

#endif // FERTILIZER_H


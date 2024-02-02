#ifndef CUBE_CONUNDRUM_H
#define CUBE_CONUNDRUM_H

#include "adventofcode2023.h"

class Cube_Conundrum : public AdventOfCode2023 {
public:
    Cube_Conundrum(int dayNumber) : AdventOfCode2023(dayNumber) {}

    void process_exercise(const QString &filePath) override;

    int process_task_one(const QString &line) override;

    int process_task_two(const QString &line) override;
};

#endif // CUBE_CONUNDRUM_H

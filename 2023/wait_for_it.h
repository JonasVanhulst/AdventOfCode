#ifndef WAIT_FOR_IT_H
#define WAIT_FOR_IT_H

#include "adventofcode2023.h"

class Wait_For_It : public AdventOfCode2023
{
public:
    Wait_For_It(int dayNumber) : AdventOfCode2023(dayNumber) {}

    void process_exercise(const QString &filePath) override;

    int process_task_one(const QString &line) override;

    int process_task_two(const QString &line) override;
};

#endif // WAIT_FOR_IT_H


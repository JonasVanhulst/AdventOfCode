#ifndef SCRATCHCARDS_H
#define SCRATCHCARDS_H

#include "adventofcode2023.h"
#include <QSet>

class Scratchcards : public AdventOfCode2023
{
public:
    Scratchcards(int dayNumber) : AdventOfCode2023(dayNumber) {}

    void process_exercise(const QString &filePath) override;

    int process_task_one(const QString &line) override;

    int process_task_two(const QString &line) override;

private:
    QMap<int, int> cards;
};

#endif // SCRATCHCARDS_H


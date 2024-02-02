#ifndef ADVENTOFCODE2023_H
#define ADVENTOFCODE2023_H

#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QFileDevice>
#include <QMap>

using namespace std;
using std::string;

class AdventOfCode2023 {
protected:
    int result_task_one, result_task_two, dayNumber;

public:
    AdventOfCode2023(int dayNumber) : result_task_one(0), result_task_two(0), dayNumber(dayNumber) {}

    virtual void process_exercise(const QString &filePath) = 0;

    virtual int process_task_one(const QString &line) = 0;

    virtual int process_task_two(const QString &line) = 0;

    int getResultTaskOne() const { return result_task_one; }

    int getResultTaskTwo() const { return result_task_two; }

    void printResults() const;
};

#endif // ADVENTOFCODE2023_H

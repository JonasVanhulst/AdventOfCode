#ifndef TREBUCHET_H
#define TREBUCHET_H

#include "adventofcode2023.h"

using namespace std;
using std::string;

class Trebuchet : public AdventOfCode2023 {
private:
    typedef enum {
        one = 1,
        two = 2,
        three = 3,
        four = 4,
        five = 5,
        six = 6,
        seven = 7,
        eight = 8,
        nine = 9
    } numbersAsString;

    QMap <QString, numbersAsString> charToNumbers = {
                                                    {"one",   one},
                                                    {"two",   two},
                                                    {"three", three},
                                                    {"four",  four},
                                                    {"five",  five},
                                                    {"six",   six},
                                                    {"seven", seven},
                                                    {"eight", eight},
                                                    {"nine",  nine},
                                                    };
public:
    Trebuchet(int dayNumber) : AdventOfCode2023(dayNumber) {}

    void process_exercise(const QString &filePath) override;

    int process_task_one(const QString &line) override;

    int process_task_two(const QString &line) override;
};

#endif // TREBUCHET_H

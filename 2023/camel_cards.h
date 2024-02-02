#ifndef CAMEL_CARDS_H
#define CAMEL_CARDS_H

#include "adventofcode2023.h"

class Camel_Cards : public AdventOfCode2023
{
private:
    int cardValue, count = 0;
    bool founding = false;
    QString camelCard;
    int pairs = 0;
    int threeOfAKind = 0;
    int fourOfAKind = 0;
    bool hasOnePair, hasTwoPar, hasStraight, hasThreeOfAKind, hasFourOfAKind = false;

    //A, K, Q, J, T, 9, 8, 7, 6, 5, 4, 3, or 2.
    typedef enum {
        A = 14,
        K = 13,
        Q = 12,
        J = 11,
        T = 10,
    } numbersAsString;

    QMap <QString, numbersAsString> charToNumbers = {
                                                    {"A", A},
                                                    {"K", K},
                                                    {"Q", Q},
                                                    {"J", J},
                                                    {"T", T}
                                                    };

public:
    Camel_Cards(int dayNumber) : AdventOfCode2023(dayNumber) {}

    void process_exercise(const QString &filePath) override;

    int process_task_one(const QString &line) override;

    int process_task_two(const QString &line) override;
};

#endif // CAMEL_CARDS_H



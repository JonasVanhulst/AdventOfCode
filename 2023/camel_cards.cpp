#include "camel_cards.h"

void Camel_Cards::process_exercise(const QString &filePath) {
    QFile file_task_one(filePath);
    QFile file_task_two(filePath);

    if (!file_task_one.open(QIODevice::ReadOnly | QIODevice::Text)) {
        cerr << "Error opening file: " << file_task_one.errorString().toStdString() << endl;
        return;
    }

    if (!file_task_two.open(QIODevice::ReadOnly | QIODevice::Text)) {
        cerr << "Error opening file: " << file_task_two.errorString().toStdString() << endl;
        return;
    }

    QTextStream first(&file_task_one);
    QTextStream second(&file_task_two);

    while (!first.atEnd()) {
        QString line = first.readLine();
        process_task_one(line);
    };

    while (!second.atEnd()) {
        QString line = second.readLine();
        process_task_two(line);
    }

    file_task_one.close();
    file_task_two.close();
}

int Camel_Cards::process_task_one(const QString &line) {

    QString camelCard;

    int pairs = 0;
    int threeOfAKind = 0;
    int fourOfAKind = 0;
    bool hasOnePair, hasTwoPar, hasStraight, hasThreeOfAKind, hasFourOfAKind = false;

    QMap<QChar, int> charCount;
    QMap<QChar, int> rankCount;

    QList<QString> onePairCards;
    QList<QString> twoPairCards;
    QList<int> OnePair;

    QStringList setElements = line.split(" ", Qt::SkipEmptyParts);

    camelCard = setElements.takeFirst();
    cardValue = setElements.takeLast().toInt();

    cout << camelCard.toStdString() << endl;

    for (const QChar &card : camelCard) {
        QChar rank = card.toUpper();
        rankCount[rank]++;
    }

    for (const int count : rankCount.values()) {
        if (count == 2) {
            pairs++;
        } else if (count == 3) {
            threeOfAKind++;
        } else if (count == 4) {
            fourOfAKind++;
        }
    }

    if (pairs == 2) {
        hasTwoPar = true;
        //cout << "Two pair : " << camelCard.toStdString() << endl;
        twoPairCards.append(camelCard);
    } else if (pairs == 1) {
        hasOnePair = true;
        //cout << "One pair : " << camelCard.toStdString() << endl;
        onePairCards.append(camelCard);
        OnePair.append(cardValue);
    } else if (threeOfAKind == 1) {
        hasThreeOfAKind = true;
        //cout << "Three Of A Kind : " << camelCard.toStdString() << endl;
    } else if (fourOfAKind == 1) {
        hasFourOfAKind = true;
        //cout << "Four Of A Kind : " << camelCard.toStdString() << endl;
    }

    QList<QChar> sortedRanks = rankCount.keys().toVector().toList();
    std::sort(sortedRanks.begin(), sortedRanks.end());

    for (int i = 0; i < sortedRanks.size() - 1; ++i) {
        if (sortedRanks[i].toLatin1() + 1 != sortedRanks[i + 1].toLatin1()) {
            hasStraight = false;
            break;
        }
        hasStraight = true;
    }

    if (hasStraight) {
        cout << "Straight" << endl;
    } else if (!hasStraight && !hasFourOfAKind && !hasThreeOfAKind && !hasOnePair && !hasTwoPar){
        cout <<  "HighCard" << endl;
    }
 int onePairResult, counter1 = 0;

    if (hasTwoPar){
        cout << "Two pairs cards: ";
        for (const QString& card : twoPairCards) {
            cout << card.toStdString() << " ";
        }
        cout << endl;
    }
    if(hasOnePair){
        cout << "One pairs cards: ";
        for (const QString& card : onePairCards) {
            for(const int& value : OnePair){
                cout << card.toStdString() << " " << value << " ";
                counter1++;
                cout << counter1;
            }
        }
        if (counter1 == 1){
            onePairResult = counter1 * cardValue;
        } else if (counter1 >= 2){
            onePairResult = 1233334;
        }
        cout << endl;
    }

    result_task_one = onePairResult;
    return result_task_one;
}

int Camel_Cards::process_task_two(const QString &line) {

    return result_task_two;
}


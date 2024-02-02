#include "scratchcards.h"

void Scratchcards::process_exercise(const QString &filePath) {
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

int Scratchcards::process_task_one(const QString &line) {

    int points = 0;

    QStringList setElements = line.split(": ").at(1).split(" | ");

    int cardId = line.split(": ").at(0).split(" ", Qt::SkipEmptyParts).at(1).toInt();

    QStringList subSetElements1 = setElements.at(0).split(" ", Qt::SkipEmptyParts);
    QStringList subSetElements2 = setElements.at(1).split(" ", Qt::SkipEmptyParts);

    QSet<int> set1;
    QSet<int> set2;

    foreach (const QString &str, subSetElements1) {
        set1.insert(str.toInt());
    }

    foreach (const QString &str, subSetElements2) {
        set2.insert(str.toInt());
    }

    QSet<int> commonElements = set1.intersect(set2);

    foreach (const int &element, commonElements) {
        if (set1.contains(element) && set2.contains(element)) {
            points++;
        }
    }

    if (points > 0) {
        result_task_one += pow(2, points - 1);
    }

    return result_task_one;
}
int Scratchcards::process_task_two(const QString &line) {
    QTextStream ss(line.toUtf8());
    QString trash;
    int n;

    // Card 1:
    ss >> trash >> n >> trash;
    cards[n]++;

    QSet<int> winning;
    QString winningString;
    ss >> winningString;
    // Skip '|'
    ss.read(1);
    QTextStream winningStream(&winningString);
    while (!winningStream.atEnd()) {
        winningStream >> n;
        winning.insert(n);
    }

    int matches;

    QStringList numbers = ss.readLine().split(' ', Qt::SkipEmptyParts);
    for (const QString& num : numbers) {
        bool ok;
        int currentNumber = num.toInt(&ok);
        if (ok) {
            matches += winning.contains(currentNumber);
        }
    }

    for (int i = 1; i <= matches; i++) {
        int currentCard = n + i;
        cards[currentCard] += cards[currentCard - 1];
    }

    for (const auto &pair : cards) {
        result_task_two += pair;
    }

    return result_task_two;
}

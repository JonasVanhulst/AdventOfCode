#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QSet>
#include <QVector>

using namespace std;

int cardPoints = 0;

int process_exercise_one(const QString &line);
int process_exercise_two(const QString &line);
string readingCopyFile(int copyId);


int main() {
    QString filePathOne = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day4_Example_1.txt";
    QString filePathTwo = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day4_Example_2.txt";


    cout << "Advent Of Coding" << endl;
    cout << endl;

    QFile file(filePathTwo);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return -1;
    QTextStream in(&file);

    cout << endl;

    while (!in.atEnd()) {
        QString line = in.readLine();
        process_exercise_two(line);
    }

    file.close();

    cout << "The card points of this game = " << cardPoints << endl;

    return 0;
}

int process_exercise_one(const QString &line) {
    cout << line.toStdString() << endl;

    QStringList setElements = line.split(": ").at(1).split(" | ");

    int cardId = line.split(": ").at(0).split(" ", Qt::SkipEmptyParts).at(1).toInt();
    cout << "Card id = " << cardId << endl;

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

    cout << "Common elements in Set 2 from Set 1: ";

    foreach (const int &element, commonElements) {
        cout << element << " ";
    }

    int points = 0;

    foreach (const int &element, commonElements) {
        if (set1.contains(element) && set2.contains(element)) {
            points++;
        }
    }

    if (points > 0) {
        cardPoints += pow(2, points - 1);
    }

    cout << endl;

    return cardPoints;
}

int process_exercise_two(const QString &line) {

        cout << line.toStdString() << endl;

        QStringList setElements = line.split(": ").at(1).split(" | ");

        int cardId = line.split(": ").at(0).split(" ", Qt::SkipEmptyParts).at(1).toInt();
        cout << "Card id = " << cardId << endl;

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

        cout << "Common elements in Set 2 from Set 1: ";

        foreach (const int &element, commonElements) {
            cout << element << " ";
        }

        int points = 0;
        int copyId = 0;

        foreach (const int &element, commonElements) {
            if (set1.contains(element) && set2.contains(element)) {
                points++;
            }
        }

        for (int i = 1; i <= points; i++) {
            cout << endl << "copy of card" << i + cardId << endl;
            copyId = i + cardId;
            readingCopyFile(copyId);
        }

        cout << endl;


        return cardPoints;
    }

string readingCopyFile(int copyId){
    int i = 1;

    QString copyFilePath = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day4_Example_2_copy.txt";
    QFile copyFile(copyFilePath);

    if (!copyFile.open(QIODevice::ReadOnly | QIODevice::Text))
        cout << "File wasn't founc" << endl;

    QTextStream copyIn(&copyFile);

    while (!copyIn.atEnd()){
        QString files = copyIn.readLine();
        if (i == copyId){
            cout <<  "Line " << i << ":" <<files.toStdString() << endl;
            return files.toStdString();
        }
        i++;
    }
}




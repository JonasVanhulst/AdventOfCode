#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QFileDevice>
#include <QMap>
using namespace std;

typedef enum{
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

QMap<QString, numbersAsString> charToNumbers = {
    {"one", one},
    {"two", two},
    {"three", three},
    {"four", four},
    {"five", five},
    {"six", six},
    {"seven", seven},
    {"eight", eight},
    {"nine", nine},
};

int sum = 0;
QString Result;

int process_exercise_one(const QString& line);
int process_exercise_two(const QString& line);

int main()
{
    QString filePathOne = "/home/jonas/dev/qt-workspace/Day1/numbers.txt";
    QString filePathTwo = "/home/jonas/dev/qt-workspace/Day1/secondNumbersAsChars.txt";

    cout << "Advent Of Coding" << endl;
    cout << endl;

    QFile file(filePathTwo);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return -1;

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        process_exercise_two(line);
    }

    file.close();

    cout << "The sum = " << sum << endl;

    return 0;
}

int process_exercise_two(const QString& line)
{
    QString numbers, words, combinedNumbers;

    for (int i = 0; i < line.size(); i++) {
        QChar checker = line.at(i);

        if (checker.isLetterOrNumber()) {
            words.append(checker);
        }
    }

    if (!words.isEmpty()) {
        QString updatedString;

        for (int i = 0; i < words.size(); i++) {
            QChar checker = words.at(i);

            if (checker.isDigit()) {
                updatedString.append(checker);
            } else {
                foreach (const QString& word, charToNumbers.keys()) {
                    if (words.mid(i).startsWith(word)) {
                        int value = charToNumbers.value(word);
                        updatedString.append(QString::number(value));
                    }
                }
            }
        }

        words = updatedString;

        combinedNumbers = updatedString.at(0).toLatin1() + updatedString.at(updatedString.size() - 1);
        cout << combinedNumbers.toStdString() << endl;
        sum += combinedNumbers.toInt();
    }
    return sum;
}


int process_exercise_one(const QString& line)
{
    QString numbers, combinedNumbers;

    for (int i = 0; i < line.size(); i++) {
        QChar checker = line.at(i);

        if (checker.isDigit()) {
            numbers.append(checker);
        }
    }

    if (!numbers.isEmpty()) {
        combinedNumbers = numbers.at(0).toLatin1() + numbers.at(numbers.size() - 1);
        cout << combinedNumbers.toStdString()  << endl;
        sum += combinedNumbers.toInt();

    }
    cout << endl;

    return sum;
}



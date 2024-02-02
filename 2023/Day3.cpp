#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QFileDevice>
#include <QMap>

using namespace std;
using std::string;

int IDsum = 0,  power = 0;

int process_exercise_one(const QString &line);

int process_exercise_two(const QString &line);

int main() {
    QString filePathOne = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day3_Example_1.txt";
    QString filePathTwo = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day3_Example_2.txt";

    cout << "Advent Of Coding" << endl;
    cout << endl;

    QFile file(filePathOne);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return -1;

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        process_exercise_one(line);
    }

    file.close();

    cout << "The sum = " << power << endl;

    return 0;
}

int process_exercise_one(const QString &line) {
    cout << line.toStdString() << endl;

  }

int process_exercise_two(const QString &line) {

}



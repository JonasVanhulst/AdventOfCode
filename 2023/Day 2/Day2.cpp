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
    QString filePathOne = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day2_Example_1.txt";
    QString filePathTwo = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day2_Example_2.txt";

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

    cout << "The sum of valid id's = " << power << endl;

    return 0;
}

int process_exercise_one(const QString &line) {
    int red = 12, green = 13, blue = 14;
    bool flag =  true;

    cout << line.toStdString() << endl;

    QStringList setElements = line.split(": ").at(1).split("; ");

    int gameId = line.split(": ").at(0).split(' ').at(1).toInt();
    cout << "Game id = " << gameId << endl;

    for (int i = 0; i < setElements.size(); i++) {
        cout << "Set " << i + 1 << ": ";

        QStringList subSetElements = setElements.at(i).split(", ");

        for (int j = 0; j < subSetElements.size(); j++) {

            cout << endl << "subSetElements = " << subSetElements.at(j).toStdString() << endl;
            QStringList value = subSetElements.at(j).split(" ");
            cout << value.at(0).toStdString() << "->" << value.at(1).toStdString() << endl;
            if (value.at(1) == "blue" && value.at(0).toInt() > 14) {
                    flag = false;
            }
            if (value.at(1) == "red" && value.at(0).toInt() > 12) {
                    flag = false;
            }
            if (value.at(1) == "green" && value.at(0).toInt() > 13 ) {
                    flag = false;
            }
        }
        cout << endl;
    }

    if (flag == true){
            IDsum += gameId;
    }

    return IDsum;
}

int process_exercise_two(const QString &line) {
    int minRed = 0, minGreen = 0, minBlue = 0;
    bool flag =  true;

    cout << line.toStdString() << endl;

    QStringList setElements = line.split(": ").at(1).split("; ");

    int gameId = line.split(": ").at(0).split(' ').at(1).toInt();
    cout << "Game id = " << gameId << endl;

    for (int i = 0; i < setElements.size(); i++) {
        cout << "Set " << i + 1 << ": ";

        QStringList subSetElements = setElements.at(i).split(", ");

        for (int j = 0; j < subSetElements.size(); j++) {

            cout << endl << "subSetElements = " << subSetElements.at(j).toStdString() << endl;
            QStringList value = subSetElements.at(j).split(" ");
            cout << value.at(0).toStdString() << "->" << value.at(1).toStdString() << endl;
            if (value.at(1) == "blue" && value.at(0).toInt() > minBlue) {
                minBlue = value.at(0).toInt();
            }
            if (value.at(1) == "red" && value.at(0).toInt() > minRed) {
                minRed = value.at(0).toInt();
            }
            if (value.at(1) == "green" && value.at(0).toInt() > minGreen) {
                minGreen = value.at(0).toInt();
            }
        }
        cout << endl;
    }

    power += (minRed * minBlue * minGreen);

    return power;
}




#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QSet>


using namespace std;

int location = 0;

int process_exercise_one(const QString &line);
int process_exercise_two(const QString &line);
string readingCopyFile(int copyId);


int main() {
    QString filePathOne = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day5_Example_1.txt";
    QString filePathTwo = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day5_Example_2.txt";


    cout << "Advent Of Coding" << endl;
    cout << endl;

    QFile file(filePathOne);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return -1;
    QTextStream in(&file);

    cout << endl;

    while (!in.atEnd()) {
        QString line = in.readLine();
        process_exercise_one(line);
    }

    file.close();

    cout << endl << "The lowest location of each seed = " << location << endl;

    return 0;
}

int process_exercise_one(const QString &line) {
    cout << line.toStdString() << endl;

    QStringList setElements = line.split(":");

    QSet<int> set1;


    foreach (const QString &str, setElements) {
        set1.insert(str.toInt());
    }

    QSet<int> commonElements = set1;

    foreach (const int &element, commonElements) {
        cout << "seeds => " << element << " ";
    }

    return location;
}

int process_exercise_two(const QString &line) {


    return location;
}




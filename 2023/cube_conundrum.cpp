#include "cube_conundrum.h"

void Cube_Conundrum::process_exercise(const QString &filePath) {
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

int Cube_Conundrum::process_task_one(const QString &line) {

    int red = 12, green = 13, blue = 14;
    bool flag = true;

    QStringList setElements = line.split(": ").at(1).split("; ");

    int gameId = line.split(": ").at(0).split(' ').at(1).toInt();

    for (int i = 0; i < setElements.size(); i++) {

        QStringList subSetElements = setElements.at(i).split(", ");

        for (int j = 0; j < subSetElements.size(); j++) {
            QStringList value = subSetElements.at(j).split(" ");
            if (value.at(1) == "blue" && value.at(0).toInt() > 14) {
                flag = false;
            }
            if (value.at(1) == "red" && value.at(0).toInt() > 12) {
                flag = false;
            }
            if (value.at(1) == "green" && value.at(0).toInt() > 13) {
                flag = false;
            }
        }
    }

    if (flag == true) {
        result_task_one += gameId;
    }

    return result_task_one;
}

int Cube_Conundrum::process_task_two(const QString &line) {

    int minRed = 0, minGreen = 0, minBlue = 0;
    bool flag = true;

    QStringList setElements = line.split(": ").at(1).split("; ");

    int gameId = line.split(": ").at(0).split(' ').at(1).toInt();

    for (int i = 0; i < setElements.size(); i++) {

        QStringList subSetElements = setElements.at(i).split(", ");

        for (int j = 0; j < subSetElements.size(); j++) {
            QStringList value = subSetElements.at(j).split(" ");
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
    }

    result_task_two += (minRed * minBlue * minGreen);

    return result_task_two;
}

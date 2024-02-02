#include "fertilizer.h"

void Fertilizer::process_exercise(const QString &filePath) {
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

int Fertilizer::process_task_one(const QString &line) {

    return result_task_one;
}

int Fertilizer::process_task_two(const QString &line) {

    return result_task_two;
}


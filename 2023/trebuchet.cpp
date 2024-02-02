#include "trebuchet.h"

void Trebuchet::process_exercise(const QString &filePath) {
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

int Trebuchet::process_task_one(const QString &line) {
    QString numbers, combinedNumbers;

    for (int i = 0; i < line.size(); i++) {
        QChar checker = line.at(i);

        if (checker.isDigit()) {
            numbers.append(checker);
        }
    }

    if (!numbers.isEmpty()) {
        combinedNumbers = numbers.at(0).toLatin1() + numbers.at(numbers.size() - 1);
        result_task_one += combinedNumbers.toInt();

    }
    return result_task_one;
}

int Trebuchet::process_task_two(const QString &line) {
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
                foreach(
                    const QString &word, charToNumbers.keys()) {
                    if (words.mid(i).startsWith(word)) {
                        int value = charToNumbers.value(word);
                        updatedString.append(QString::number(value));
                    }
                }
            }
        }

        words = updatedString;

        combinedNumbers = updatedString.at(0).toLatin1() + updatedString.at(updatedString.size() - 1);
        result_task_two += combinedNumbers.toInt();
    }

    return result_task_two;
}

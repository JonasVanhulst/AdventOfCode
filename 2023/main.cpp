#include "trebuchet.h"
#include "cube_conundrum.h"
#include "gear_ratios.h"
#include "scratchcards.h"
#include "fertilizer.h"
#include "wait_for_it.h"
#include "camel_cards.h"

int main() {
    QString filePathDay1 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day1_Example_1.txt";
    QString filePathDay2 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day2_Example_1.txt";
    QString filePathDay3 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day3_Example_1.txt";
    QString filePathDay4 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day4_Example_2_copy.txt";
    QString filePathDay5 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day5_Example_1.txt";
    QString filePathDay6 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day6_Example_1.txt";
    QString filePathDay7 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day7_Example_1.txt";
   // QString filePathDay8 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day8_Example_1.txt";
   // QString filePathDay9 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day9_Example_1.txt";
   // QString filePathDay10 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day10_Example_1.txt";
   // QString filePathDay11 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day11_Example_1.txt";
   // QString filePathDay12 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day12_Example_1.txt";
   // QString filePathDay13 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day13_Example_1.txt";
   // QString filePathDay14 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day14_Example_1.txt";
   // QString filePathDay15 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day15_Example_1.txt";
   // QString filePathDay16 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day16_Example_1.txt";
   // QString filePathDay17 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day17_Example_1.txt";
   // QString filePathDay18 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day18_Example_1.txt";
   // QString filePathDay19 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day19_Example_1.txt";
   // QString filePathDay20 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day20_Example_1.txt";
   // QString filePathDay21 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day21_Example_1.txt";
   // QString filePathDay22 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day22_Example_1.txt";
   // QString filePathDay23 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day23_Example_1.txt";
   // QString filePathDay24 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day24_Example_1.txt";
   // QString filePathDay25 = "/home/jonas/dev/qt-workspace/AdventOfCode2023/AdventOfCode_Day25_Example_1.txt";

    cout << "              _                 _      ____   __    _____          _ _               ___   ___ ___  ____   " << endl;
    cout << "     /\\      | |               | |    / __ \\ / _|  / ____|        | (_)             |__ \\ / _ \\__ \\|___ \\  " << endl;
    cout << "    /  \\   __| |_   _____ _ __ | |_  | |  | | |_  | |     ___   __| |_ _ __   __ _     ) | | | | ) | __) | " << endl;
    cout << "   / /\\ \\ / _` \\ \\ / / _ \\ '_ \\| __| | |  | |  _| | |    / _ \\ / _` | | '_ \\ / _` |   / /| | | |/ / |__ <  " << endl;
    cout << "  / ____ \\ (_| |\\ V /  __/ | | | |_  | |__| | |   | |___| (_) | (_| | | | | | (_| |  / /_| |_| / /_ ___) | " << endl;
    cout << " /_/    \\_\\__,_| \\_/ \\___|_| |_|\\__|  \\____/|_|    \\_____\\___/ \\__,_|_|_| |_|\\__, | |____|\\___/____|____/  " << endl;
    cout << "                                                                              __/ |                           " << endl;
    cout << "                                                                             |___/                            " << endl;

    Trebuchet day1(1);
    day1.process_exercise(filePathDay1);
    day1.printResults();

    Cube_Conundrum day2(2);
    day2.process_exercise(filePathDay2);
    day2.printResults();

    Gear_Ratios day3(3);
    day3.process_exercise(filePathDay3);
    day3.printResults();

    Scratchcards day4(4);
    day4.process_exercise(filePathDay4);
    day4.printResults();

    Fertilizer day5(5);
    day5.process_exercise(filePathDay5);
    day5.printResults();

    Wait_For_It day6(6);
    day6.process_exercise(filePathDay6);
    day6.printResults();

    Camel_Cards day7(7);
    day7.process_exercise(filePathDay7);
    day7.printResults();
    return 0;
}

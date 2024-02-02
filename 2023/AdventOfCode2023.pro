QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    #Day1.cpp \
    #Day2.cpp \
    #Day3.cpp \
    #Day4.cpp \
    adventofcode2023.cpp \
    camel_cards.cpp \
    cube_conundrum.cpp \
    fertilizer.cpp \
    gear_ratios.cpp \
    main.cpp \
    scratchcards.cpp \
    trebuchet.cpp \
    wait_for_it.cpp



HEADERS += \
    adventofcode2023.h \
    camel_cards.h \
    cube_conundrum.h \
    fertilizer.h \
    gear_ratios.h \
    scratchcards.h \
    trebuchet.h \
    wait_for_it.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    AdventOfCode_Day1_Example_1.txt \
    AdventOfCode_Day1_Example_2.txt \
    AdventOfCode_Day2_Example_1.txt \
    AdventOfCode_Day2_Example_2.txt \
    AdventOfCode_Day3_Example_1.txt \
    AdventOfCode_Day3_Example_2.txt \
    AdventOfCode_Day4_Example_1.txt \
    AdventOfCode_Day4_Example_2.txt \
    AdventOfCode_Day4_Example_2_copy.txt \
    AdventOfCode_Day5_Example_1.txt \
    AdventOfCode_Day6_Example_1.txt \
    AdventOfCode_Day7_Example_1.txt

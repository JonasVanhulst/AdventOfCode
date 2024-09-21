#include <iostream>
#include <string>
#include <fstream> // Handling files
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream inFile;
    string line, lines;
    vector<int> inputFile;
    inFile.open("Input1.txt");

    if (!inFile)
    {
        std::cout << "Unable to open file" << std::endl;
        exit(EXIT_FAILURE);
    }

    int number = 0, increaseCounter = 0, getNumber = 0;

    getline(inFile, line);
    number = stoi(line);

    while (!inFile.eof())
    {
        getline(inFile, line);
        getNumber = stoi(line);

        if (getNumber >= number)
        {
            increaseCounter++;
            number = getNumber;
        }
        else
        {
            number = getNumber;
        }
    }

    std::cout << "Part one = " << increaseCounter << std::endl;
    // std::cout << "Part two = " << calorieList.at(0) + calorieList.at(1) + calorieList.at(2) << std::endl;

    return 0;
}

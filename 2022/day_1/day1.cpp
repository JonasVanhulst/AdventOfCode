#include <iostream>
#include <string>
#include <fstream> // Handling files
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream inFile;
    string line;
    inFile.open("input.txt");

    if (!inFile)
    {
        std::cout << "Unable to open file" << std::endl;
        exit(EXIT_FAILURE);
    }

    int calories = 0, prev = 0, highestCalories = 0, firstElf = 0, secondElf = 0, thirdElf = 0;
    vector<int> calorieList;

    while (!inFile.eof())
    {
        getline(inFile, line);

        if (line == "")
        {
            calories = 0;
        }
        else
        {
            calories += stoi(line);
        }

        calorieList.push_back(calories);
    }

    std::sort(calorieList.begin(), calorieList.end(), greater<int>()); // Sorting the vector using greater<int>() function

    std::cout << "Part one = " << calorieList.at(0) << std::endl;
    std::cout << "Part two = " << calorieList.at(0) + calorieList.at(1) + calorieList.at(2) << std::endl;

    return 0;
}

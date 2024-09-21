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
    vector<int> inputFile;
    vector<int> numberList;
    inFile.open("Input1.txt");

    if (!inFile)
    {
        std::cout << "Unable to open file" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Read file line by line and convert to integers
    while (getline(inFile, line))
    {
        try
        {
            inputFile.push_back(stoi(line)); // Convert string to int
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid line: " << line << std::endl;
        }
    }

    inFile.close(); // Close file after reading

    // Calculate sums of consecutive triplets in the inputFile
    for (size_t i = 0; i + 2 < inputFile.size(); i++)
    {
        int numbers = inputFile.at(i) + inputFile.at(i + 1) + inputFile.at(i + 2);
        numberList.push_back(numbers);
    }

    int increaseCounter = 0;

    // Print the results
    for (size_t i = 1; i < numberList.size(); i++)
    {
        if (numberList.at(i - 1) < numberList.at(i))
        {
            increaseCounter++;
            cout << "numbers " << i << " is " << numberList.at(i) << " (increased)" << endl;
        }
        else
        {
            cout << "numbers " << i << " is " << numberList.at(i) << " (no increase)" << endl;
        }
    }

    std::cout << "Total increases: " << increaseCounter << std::endl;

    return 0;
}

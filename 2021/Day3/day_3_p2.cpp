#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Counting the most common bit
char mostCommonBit(const vector<string> &numbers, int position, char tieBreaker)
{
    int countOnes = 0, countZeroes = 0;
    for (const string &number : numbers)
    {
        if (number[position] == '1')
        {
            countOnes++;
        }
        else
        {
            countZeroes++;
        }
    }
    return (countOnes >= countZeroes) ? tieBreaker : (tieBreaker == '1' ? '0' : '1');
}

// Counting the least common bit
char leastCommonBit(const vector<string> &numbers, int position, char tieBreaker)
{
    int countOnes = 0, countZeroes = 0;
    for (const string &number : numbers)
    {
        if (number[position] == '1')
        {
            countOnes++;
        }
        else
        {
            countZeroes++;
        }
    }
    return (countZeroes <= countOnes) ? tieBreaker : (tieBreaker == '0' ? '1' : '0');
}

// Finding the oxygen
string findRating(const vector<string> &numbers, bool findMostCommon)
{
    vector<string> candidates = numbers;
    int numBits = candidates[0].size();

    for (int i = 0; i < numBits; i++)
    {
        char commonBit;
        if (findMostCommon)
        {
            commonBit = mostCommonBit(candidates, i, '1');
        }
        else
        {
            commonBit = leastCommonBit(candidates, i, '0');
        }

        // Storing the filtered numbers
        vector<string> filtered;
        for (const string &number : candidates)
        {
            if (number[i] == commonBit)
            {
                filtered.push_back(number);
            }
        }
        candidates = filtered;

        if (candidates.size() == 1)
        {
            break;
        }
    }
    return candidates[0];
}

int main()
{
    ifstream inFile("input3.txt");
    if (!inFile)
    {
        std::cout << "Unable to open file" << std::endl;
        exit(EXIT_FAILURE);
    }

    vector<string> diagnosticReport;
    string line;
    while (getline(inFile, line))
    {
        diagnosticReport.push_back(line);
    }
    inFile.close();

    string oxygenRatingBinary = findRating(diagnosticReport, true);
    string co2RatingBinary = findRating(diagnosticReport, false);

    // Converting binary to integers
    int oxygenRatingDecimal = stoi(oxygenRatingBinary, nullptr, 2);
    int co2RatingDecimal = stoi(co2RatingBinary, nullptr, 2);

    // Calculating the rating by multiplying the oxygen with the co2
    int lifeSupportRating = oxygenRatingDecimal * co2RatingDecimal;

    cout << "Life support rating: " << lifeSupportRating << endl;

    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

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

    // Collecting all the data
    while (getline(inFile, line))
    {
        diagnosticReport.push_back(line);
    }

    inFile.close();

    int numBits = diagnosticReport[0].size();
    vector<int> bitCount(numBits, 0);

    // Counting bits
    for (const string &binaryNum : diagnosticReport)
    {
        for (int i = 0; i < numBits; i++)
        {
            if (binaryNum[i] == '1')
            {
                bitCount[i]++;
            }
        }
    }

    string gammaRate = "";
    string epsilonRate = "";

    // Calculating the gamma rate and epsilon rate
    int halfSize = diagnosticReport.size() / 2;
    for (int count : bitCount)
    {
        if (count > halfSize)
        {
            gammaRate += '1';
            epsilonRate += '0';
        }
        else
        {
            gammaRate += '0';
            epsilonRate += '1';
        }
    }

    // Converting the variables from string to int
    int gammaDecimal = stoi(gammaRate, nullptr, 2);
    int epsilonDecimal = stoi(epsilonRate, nullptr, 2);

    // Multiplying the gamma with epsilon
    int powerConsumption = gammaDecimal * epsilonDecimal;

    cout << "Power Consumption Task One: " << powerConsumption << endl;

    return 0;
}

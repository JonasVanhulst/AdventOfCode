#include <iostream>
#include <string>
#include <fstream> // Handling files
#include <vector>
#include <algorithm>

using namespace std;

int numVal, sum = 0;

int checkScoreLowercase(char letter)
{
    string alphaLower = "abcdefghijklmnopqrstuvwxyz";
    string text(1, letter);

    cout << text << endl;

    for (unsigned int y = 0; y < text.size(); y++)
    {
        for (unsigned int w = 0; w < alphaLower.size(); w++)
        {
            if (text[y] == alphaLower[w])
            {
                numVal = (int)(alphaLower[w] - 'a' + 1);
                sum += numVal;
            }
        }
    }
    return sum;
}

int checkScoreUppercase(char letter)
{
    string alphaUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string text(1, letter);

    cout << text << endl;

    for (unsigned int y = 0; y < text.size(); y++)
    {
        for (unsigned int w = 0; w < alphaUpper.size(); w++)
        {
            if (text[y] == alphaUpper[w])
            {
                numVal = (int)(alphaUpper[w] - 'A' + 27);
                sum += numVal;
            }
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    ifstream inFile;
    string line1, line2, line3;

    inFile.open("input3.txt");
    int score = 0;

    if (!inFile)
    {
        std::cout << "Unable to open file" << std::endl;
        exit(EXIT_FAILURE);
    }

    while (!inFile.eof())
    {
        getline(inFile, line1);
        getline(inFile, line2);
        getline(inFile, line3);

        bool foundCommonChar = false;
        char letter1, letter2, letter3, commonChar = '\0';

        for (size_t i = 0; i < line1.length(); i++)
        {
            for (size_t j = 0; j < line2.length(); j++)
            {
                for (size_t k = 0; k < line3.length(); k++)
                {
                    char letter1 = line1.at(i);
                    char letter2 = line2.at(j);
                    char letter3 = line3.at(k);

                    if (letter1 == letter2 && letter2 == letter3)
                    {
                        commonChar = letter1;
                        foundCommonChar = true;
                        break; // Found common character, no need to continue further
                    }
                }
                if (foundCommonChar)
                    break;
            }
            if (foundCommonChar)
                break;
        }

        if (foundCommonChar)
        {
            if (islower(commonChar))
            {
                score = checkScoreLowercase(commonChar);
            }
            else
            {
                score = checkScoreUppercase(commonChar);
            }
            cout << "Common letter is " << commonChar << " with score: " << score << endl;
        }
    }

    std::cout << "Part two = " << score << std::endl;

    return 0;
}

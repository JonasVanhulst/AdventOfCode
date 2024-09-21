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
    string line;
    inFile.open("input3.txt");
    int score = 0;

    if (!inFile)
    {
        std::cout << "Unable to open file" << std::endl;
        exit(EXIT_FAILURE);
    }

    while (!inFile.eof())
    {
        getline(inFile, line);

        char letter1, letter2, commonChar;
        string half = line.substr(0, line.length() / 2);
        string otherHalf = line.substr(line.length() / 2);

        for (size_t i = 0; i < half.length(); i++)
        {
            for (size_t j = 0; j < otherHalf.length(); j++)
            {
                letter1 = half.at(i);
                letter2 = otherHalf.at(j);

                if (letter1 == letter2)
                {
                    if (letter1 != '\0')
                    {
                        commonChar = letter1;
                    }
                }
            }
            if (i == (line.length() / 2) - 1)
            {
                if (islower(commonChar))
                {
                    score = checkScoreLowercase(commonChar);
                    cout << "commonLetter is " << commonChar << " with score: " << score << endl;
                }
                else
                {
                    score = checkScoreUppercase(commonChar);
                    cout << "commonLetter is " << commonChar << " with score: " << score << endl;
                }
            }
        }
    }

    std::cout << "Part one = " << score << std::endl;

    return 0;
}

#include <iostream>
#include <string>
#include <fstream> // Handling files

using namespace std;

// A for Rock, B for Paper, and C for Scissors.
// X for Rock, Y for Paper, and Z for Scissors.

int main(int argc, char const *argv[])
{
    ifstream file2;
    string line;
    file2.open("input2.txt");

    if (!file2)
    {
        std::cout << "Unable to open file" << std::endl;
        exit(EXIT_FAILURE);
    }

    int playerScore = 0, jokeScore = 0;

    while (!file2.eof())
    {
        getline(file2, line);

        if (line.at(0) == 'A')
        {
            switch (line.at(2))
            {
            case 'X':
                playerScore += 4;
                jokeScore += 3;
                break;
            case 'Y':
                playerScore += 8;
                jokeScore += 4;
                break;
            case 'Z':
                playerScore += 3;
                jokeScore += 8;
                break;
            }
        }
        else if (line.at(0) == 'B')
        {
            switch (line.at(2))
            {
            case 'X':
                playerScore += 1;
                jokeScore += 1;
                break;
            case 'Y':
                playerScore += 5;
                jokeScore += 5;
                break;
            case 'Z':
                playerScore += 9;
                jokeScore += 9;
                break;
            }
        }
        else if (line.at(0) == 'C')
        {
            switch (line.at(2))
            {
            case 'X':
                playerScore += 7;
                jokeScore += 2;
                break;
            case 'Y':
                playerScore += 2;
                jokeScore += 6;
                break;
            case 'Z':
                playerScore += 6;
                jokeScore += 7;
                break;
            }
        }
    }

    std::cout << "Part one = " << playerScore << std::endl;
    std::cout << "Part two = " << jokeScore << std::endl;

    return 0;
}

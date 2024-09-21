#include <iostream>
#include <string>
#include <fstream> // Handling files
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * @param start1, end1, start2, end2
 * @return bool
 */
bool isContained(int start1, int end1, int start2, int end2)
{
    return (start1 <= start2 && end1 >= end2) || (start2 <= start1 && end2 >= end1);
}

bool isOverlapped(int start1, int end1, int start2, int end2)
{
    return start1 <= end2 && end1 >= start2;
}

int main(int argc, char const *argv[])
{
    ifstream inFile;
    inFile.open("Input4.txt");

    if (!inFile)
    {
        std::cout << "Unable to open file" << std::endl;
        exit(EXIT_FAILURE);
    }

    int count = 0, countOverlap = 0;
    string line;

    while (!inFile.eof())
    {
        getline(inFile, line);

        int head1, end1, head2, end2;
        char separator1, separator2, comma;

        istringstream ss(line); // Very useful function for this exercise

        // Getting the first section
        ss >> head1 >> separator1 >> end1 >> comma;
        // After the comma getting the second section
        ss >> head2 >> separator2 >> end2;

        if (isContained(head1, end1, head2, end2))
        {
            count++;
        }

        if (isOverlapped(head1, end1, head2, end2))
        {
            countOverlap++;
        }
    }

    cout << "Part One : " << count << endl;
    cout << "Part Two : " << countOverlap << endl;
    return 0;
}

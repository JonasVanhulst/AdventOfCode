#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>

using namespace std;

int findMarker(const string &data, int markerLength)
{
    for (size_t i = 0; i <= data.size() - markerLength; i++)
    {
        string substring = data.substr(i, markerLength);
        unordered_set<char> uniqueChars(substring.begin(), substring.end());
        if (uniqueChars.size() == markerLength)
        {
            return i + markerLength;
        }
    }
    return -1;
}

int main()
{
    ifstream inFile("Input6.txt");
    if (!inFile)
    {
        cerr << "Unable to open file" << endl;
        return EXIT_FAILURE;
    }

    string line;
    getline(inFile, line);

    inFile.close();

    if (line.empty())
    {
        cerr << "File is empty or could not read line" << endl;
        return EXIT_FAILURE;
    }

    // Change marker length from 4 tot 14 for part 1 tot 2
    int markerLength = 14;
    int position = findMarker(line, markerLength);

    if (position != -1)
    {
        cout << "Marker position " << position << endl;
    }
    else
    {
        cout << "No marker found" << endl;
    }

    return 0;
}

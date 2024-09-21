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
    int number = 0, vertical = 0, horizontal = 0, depth = 0, aim = 0;
    inFile.open("input2.txt");

    if (!inFile)
    {
        std::cout << "Unable to open file" << std::endl;
        exit(EXIT_FAILURE);
    }

    while (getline(inFile, line))
    {
        size_t pos = line.find_last_of(' '); // Find the last space
        if (pos != string::npos)
        {
            // Extract the number after the last space
            string num_str = line.substr(pos + 1);
            int num = stoi(num_str); // Convert string to integer

            if (line.find("forward") == 0) // Check if the line starts with "forward"
            {
                horizontal += num;
                depth += aim * num; // Increase depth by aim * num
            }
            else if (line.find("up") == 0) // Check if the line starts with "up"
            {
                vertical -= num; // Subtract for "up"
                aim -= num;      // Decrease aim
            }
            else if (line.find("down") == 0) // Check if the line starts with "down"
            {
                vertical += num; // Add for "down"
                aim += num;      // Decrease aim
            }
            else
            {
                cout << "Invalid command: " << line << endl;
            }
        }
    }

    std::cout << "Part One - Horizontal: " << horizontal << ", Vertical: " << vertical << " solution is " << horizontal * vertical << std::endl;

    inFile.close(); // Don't forget to close the file

    std::cout << "Final Horizontal Position Part Two: " << horizontal << std::endl;
    std::cout << "Final Depth Part Two: " << depth << std::endl;
    std::cout << "Result Part Two (Horizontal * Depth): " << horizontal * depth << std::endl;

    return 0;
}

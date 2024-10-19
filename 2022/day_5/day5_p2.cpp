#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

#define NUMBER_OF_STACKS 9

int main()
{
    ifstream inFile("Input5.txt");
    if (!inFile)
    {
        cout << "Unable to open file" << endl;
        return EXIT_FAILURE;
    }

    vector<string> lines;
    string line;

    while (getline(inFile, line))
    {
        if (line.empty())
        {
            break;
        }
        lines.push_back(line);
    }

    // Creating the stacks for be able to move letters
    vector<stack<char>> stacks(NUMBER_OF_STACKS); // Number of stacks

    for (int i = lines.size() - 1; i >= 0; i--)
    {
        for (size_t j = 0; j < lines[i].size(); j++)
        {
            if (lines[i][j] != ' ' && lines[i][j] != '[' && lines[i][j] != ']')
            {
                stacks[j / 4].push(lines[i][j]);
            }
        }
    }

    while (getline(inFile, line))
    {
        if (line.empty())
        {
            continue;
        }

        int count, from, to;
        stringstream ss(line);
        ss >> ws >> line >> count >> ws >> line >> from >> ws >> line >> to;

        // *** Updated section starts here ***
        // To maintain order, we need a temporary stack or vector to hold the crates
        stack<char> tempStack;

        // Pop 'count' crates from the 'from' stack and push them into tempStack
        for (int i = 0; i < count; i++)
        {
            if (!stacks[from - 1].empty())
            {
                tempStack.push(stacks[from - 1].top());
                stacks[from - 1].pop();
            }
        }

        // Now, push the crates from tempStack to the 'to' stack (this keeps the order)
        while (!tempStack.empty())
        {
            stacks[to - 1].push(tempStack.top());
            tempStack.pop();
        }
        // *** Updated section ends here ***
    }

    for (size_t i = 0; i < stacks.size(); i++)
    {
        if (!stacks[i].empty())
        {
            cout << stacks[i].top();
        }
        else
        {
            cout << "Stack " << (i + 1) << ": empty" << endl;
        }
    }

    inFile.close();
    return 0;
}

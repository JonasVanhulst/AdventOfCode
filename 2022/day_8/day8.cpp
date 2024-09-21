#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream inFile("Input8.txt");
    if (!inFile)
    {
        cout << "Unable to open file" << endl;
        return EXIT_FAILURE;
    }

    vector<vector<int>> grid;
    string line;

    while (getline(inFile, line))
    {
        vector<int> row;
        for (char ch : line)
        {
            if (isdigit(ch))
            {
                row.push_back(ch - '0');
            }
        }
        grid.push_back(row);
    }
    inFile.close();

    int t = 0;

    for (int r = 0; r < grid.size(); r++)
    {
        for (int c = 0; c < grid[r].size(); c++)
        {
            int k = grid[r][c];
            bool visible = false;

            // Checking left
            bool canSeeLeft = true;
            for (int left = 0; left < c; left++)
            {
                if (grid[r][left] >= k)
                {
                    canSeeLeft = false;
                    break;
                }
            }

            // Checking right
            bool canSeeRight = true;
            for (int right = c + 1; right < grid[r].size(); right++)
            {
                if (grid[r][right] >= k)
                {
                    canSeeRight = false;
                    break;
                }
            }

            // Checking up
            bool canSeeUp = true;
            for (int up = 0; up < r; up++)
            {
                if (grid[up][c] >= k)
                {
                    canSeeUp = false;
                    break;
                }
            }

            // Checking down
            bool canSeeDown = true;
            for (int down = r + 1; down < grid.size(); down++)
            {
                if (grid[down][c] >= k)
                {
                    canSeeDown = false;
                    break;
                }
            }

            // Counting the trees
            if (canSeeLeft || canSeeRight || canSeeUp || canSeeDown)
            {
                t++;
            }
        }
    }

    cout << t << endl;

    return 0;
}

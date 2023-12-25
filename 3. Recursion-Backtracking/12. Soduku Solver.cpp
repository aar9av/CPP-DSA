#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> grid(9, vector<int>(9));

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool valid(int x, int y, int val)
{
    for (int i = 0; i < 9; i++)
        if (grid[x][i] == val || grid[i][y] == val || grid[x / 3 * 3 + i / 3][y / 3 * 3 + i / 3] == val)
            return 0;
    return 1;
}

bool solveSudoku()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (grid[i][j] == 0)
            {
                for (int val = 1; val <= 9; val++)
                    if (valid(i, j, val))
                    {
                        grid[i][j] = val;
                        if (solveSudoku())
                            return 1;
                        else
                            grid[i][j] = 0;
                    }
                return 0;
            }
    return 1;
}

int main()
{
    fastIO();
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> grid[i][j];

    if (solveSudoku())
    {
        cout << "True" << endl;
        for (auto &i : grid)
        {
            for (auto &j : i)
                cout << j << " ";
            cout << endl;
        }
    }
    else
        cout << "False" << endl;
    return 0;
}
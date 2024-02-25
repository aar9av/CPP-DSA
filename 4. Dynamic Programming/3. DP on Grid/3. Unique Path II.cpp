#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define it(x) x.begin(), x.end()
#define endl char(10)
using namespace std;
int mod = 1e9 + 7;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int uniquePathsWithObstacles(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    if (i == grid.size() || j == grid[0].size())
        return 0;
    if (grid[i][j] == 1)
        return 0;
    if (i == grid.size() - 1 && j == grid[0].size() - 1)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = uniquePathsWithObstacles(grid, i + 1, j, dp) + uniquePathsWithObstacles(grid, i, j + 1, dp);
}

int solve(vector<vector<int>> &grid)
{
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    return uniquePathsWithObstacles(grid, 0, 0, dp);
}

main()
{
    fastIO();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n);
    for (int i = 0; i < n; ++i)
    {
        vector<int> temp(m);
        for (int j = 0; j < m; ++j)
            cin >> temp[j];
        grid[i] = temp;
    }
    cout << solve(grid);
    return 0;
}
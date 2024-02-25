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

int minPathSum(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    if (i == grid.size() - 1 && j == grid[0].size() - 1)
        return dp[i][j] = grid[i][j];
    if (i == grid.size() || j == grid[0].size())
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = grid[i][j] + min(minPathSum(grid, i + 1, j, dp), minPathSum(grid, i, j + 1, dp));
}

int solve(vector<vector<int>> &grid)
{
    if (grid.size() == 1 && grid[0].size() == 1)
        return grid[0][0];
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    return minPathSum(grid, 0, 0, dp);
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
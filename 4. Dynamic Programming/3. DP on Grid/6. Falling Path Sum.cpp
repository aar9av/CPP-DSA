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

int minFallingPathSum(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp)
{
    if (i == matrix.size())
        return 0;
    if (j == -1 || j == matrix[0].size())
        return INT_MAX;
    if (dp[i][j] != INT_MAX)
        return dp[i][j];
    int res = INT_MAX;
    for (int t = j - 1; t <= j + 1; ++t)
        res = min(res, minFallingPathSum(matrix, i + 1, t, dp));
    return dp[i][j] = res + matrix[i][j];
}

int solve(vector<vector<int>> &matrix)
{
    int res = INT_MAX;
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
    for (int i = 0; i < matrix[0].size(); ++i)
        res = min(res, minFallingPathSum(matrix, 0, i, dp));
    return res;
}

main()
{
    fastIO();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; ++i)
    {
        vector<int> temp(m);
        for (int j = 0; j < m; ++j)
            cin >> temp[j];
        matrix[i] = temp;
    }
    cout << solve(matrix);
    return 0;
}
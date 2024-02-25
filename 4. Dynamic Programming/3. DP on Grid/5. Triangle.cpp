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

int minPathSum(vector<vector<int>> &triangle, int i, int j, vector<vector<int>> &dp)
{
    if (i == triangle.size() - 1)
        return triangle[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = triangle[i][j] + min(minPathSum(triangle, i + 1, j, dp), minPathSum(triangle, i + 1, j + 1, dp));
}

int solve(vector<vector<int>> &triangle)
{
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
    return minPathSum(triangle, 0, 0, dp);
}

main()
{
    fastIO();
    int n;
    cin >> n;
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; ++i)
    {
        vector<int> temp(i + 1);
        for (int j = 0; j < i + 1; ++j)
            cin >> temp[j];
        triangle[i] = temp;
    }
    cout << solve(triangle);
    return 0;
}
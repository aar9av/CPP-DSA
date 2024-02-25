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

int unique_paths(int m, int n, int i, int j, vector<vector<int>> &dp)
{
    if (i == m - 1 && j == n - 1)
        return 1;
    if (i == m || j == n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = unique_paths(m, n, i + 1, j, dp) + unique_paths(m, n, i, j + 1, dp);
}

int solve(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return unique_paths(m, n, 0, 0, dp);
}

main()
{
    fastIO();
    int m, n;
    cin >> m >> n;
    cout << solve(m, n);
    return 0;
}
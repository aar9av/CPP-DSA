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

int max_chocolates(vector<vector<int>> &chocolates, int i, int j1, int j2, vector<vector<vector<int>>> &dp)
{
    if (i == chocolates.size())
        return 0;
    if (j1 == chocolates[i].size() || j1 == -1)
        return 0;
    if (j2 == chocolates[i].size() || j2 == -1)
        return 0;
    if (j1 == j2)
        return 0;
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int res = 0;
    for(int c1=j1-1; c1<=j1+1; ++c1)
        for (int c2 = j2 - 1; c2 <= j2 + 1; ++c2)
            res = max(res, chocolates[i][j1] + chocolates[i][j2] + max_chocolates(chocolates, i+1, c1, c2, dp));
    return dp[i][j1][j2] = res;
}

int solve(vector<vector<int>> &chocolates)
{
    vector<vector<vector<int>>> dp(chocolates.size(), vector<vector<int>>(chocolates[0].size(), vector<int>(chocolates[0].size(), -1)));
    return max_chocolates(chocolates, 0, 0, chocolates[0].size() - 1, dp);
}

main()
{
    fastIO();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> chocolates(n);
    for (int i = 0; i < n; ++i)
    {
        vector<int> temp(m);
        for (int j = 0; j < m; ++j)
            cin >> temp[j];
        chocolates[i] = temp;
    }
    cout << solve(chocolates);
    return 0;
}
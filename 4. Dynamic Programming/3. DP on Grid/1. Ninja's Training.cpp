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

int max_points(vector<vector<int>> &points, int idx, int prev, vector<vector<int>> &dp)
{
    if (idx == points.size())
        return 0;
    if (dp[idx][prev] != -1)
        return dp[idx][prev];
    int res = 0;
    for (int i = 0; i < 3; ++i)
        if (i != prev)
            res = max(res, points[idx][i] + max_points(points, idx + 1, i, dp));
    return dp[idx][prev] = res;
}

int solve(vector<vector<int>> &points)
{
    vector<vector<int>> dp(points.size(), vector<int>(3, -1));
    int res = 0;
    for (int i = 0; i < 3; ++i)
        res = max(res, max_points(points, 0, i, dp));
    return res;
}

main()
{
    fastIO();
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    for (int i = 0; i < n; ++i)
        cin >> points[i][0] >> points[i][1] >> points[i][2];
    cout << solve(points);
    return 0;
}
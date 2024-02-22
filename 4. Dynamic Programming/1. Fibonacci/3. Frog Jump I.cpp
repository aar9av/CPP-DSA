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

int min_energy(vector<int> &heights, int idx, vector<int> &dp)
{
    if (idx == 0)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    int res = INT_MAX;
    if (idx - 1 >= 0)
        res = min(res, min_energy(heights, idx - 1, dp) + abs(heights[idx] - heights[idx - 1]));
    if (idx - 2 >= 0)
        res = min(res, min_energy(heights, idx - 2, dp) + abs(heights[idx] - heights[idx - 2]));
    return dp[idx] = res;
}

int solve(vector<int> &heights)
{
    vector<int> dp(heights.size() + 1, -1);
    return min_energy(heights, heights.size() - 1, dp);
}

main()
{
    fastIO();
    int n;
    cin >> n;
    vector<int> heights(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> heights[i];
    cout << solve(heights);
    return 0;
}
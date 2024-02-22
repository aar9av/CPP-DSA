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

int min_energy(vector<int> &heights, int max_jump, int idx, vector<int> &dp)
{
    if (idx == 0)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    int res = INT_MAX;
    for (int i = 1; i <= max_jump; ++i)
        if (idx - i >= 0)
            res = min(res, min_energy(heights, max_jump, idx - i, dp) + abs(heights[idx] - heights[idx - i]));
    return dp[idx] = res;
}

int solve(vector<int> &heights, int max_jump)
{
    vector<int> dp(heights.size() + 1, -1);
    return min_energy(heights, max_jump, heights.size() -1, dp);
}

main()
{
    fastIO();
    int n, max_jump;
    cin >> n >> max_jump;
    vector<int> heights(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> heights[i];
    cout << solve(heights, max_jump);
    return 0;
}
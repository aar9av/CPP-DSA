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

int knapsack(vector<int> &wt, vector<int> &val, int max_wt, int idx, vector<vector<int>> &dp)
{
    if (max_wt == 0 || idx < 0)
        return 0;
    if (dp[max_wt][idx] != -1)
        return dp[max_wt][idx];
    int res = knapsack(wt, val, max_wt, idx - 1, dp);
    if (max_wt - wt[idx] >= 0)
        res = max(res, val[idx] + knapsack(wt, val, max_wt - wt[idx], idx - 1, dp));
    return dp[max_wt][idx] = res;
}

int solve(vector<int> &wt, vector<int> &val, int max_wt)
{
    vector<vector<int>> dp(max_wt + 1, vector<int>(wt.size(), -1));
    return knapsack(wt, val, max_wt, wt.size() - 1, dp);
}

main()
{
    fastIO();
    int n, max_wt;
    cin >> n >> max_wt;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; ++i)
        cin >> wt[i];
    for (int i = 0; i < n; ++i)
        cin >> val[i];
    cout << solve(wt, val, max_wt);
    return 0;
}
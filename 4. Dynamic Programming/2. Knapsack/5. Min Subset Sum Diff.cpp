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

int min_diff(vector<int> &v, int tsum, int sum, int idx, vector<vector<int>> &dp)
{
    if (idx < 0)
        return abs(tsum - 2 * sum);
    if (dp[sum][idx] != -1)
        return dp[sum][idx];
    int res = min_diff(v, tsum, sum, idx - 1, dp);
    res = min(res, min_diff(v, tsum, sum - v[idx], idx - 1, dp));
    return dp[sum][idx] = res;
}

int solve(vector<int> &v)
{
    int sum = accumulate(v.begin(), v.end(), 0);
    vector<vector<int>> dp(sum + 1, vector<int>(v.size(), -1));
    return min_diff(v, sum, sum, v.size() - 1, dp);
}

main()
{
    fastIO();
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cout << solve(v);
    return 0;
}
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

int subset_sum(vector<int> &v, int sum, int idx, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (idx < 0)
        return 0;
    if (dp[sum][idx] != -1)
        return dp[sum][idx];
    bool res = subset_sum(v, sum, idx - 1, dp);
    if (sum - v[idx] >= 0)
        res |= subset_sum(v, sum - v[idx], idx - 1, dp);
    return dp[sum][idx] = res;
}

bool solve(vector<int> &v)
{
    int sum = accumulate(v.begin(), v.end(), 0);
    if(sum%2)
        return 0;
    sum /= 2;
    vector<vector<int>> dp(sum + 1, vector<int>(v.size(), -1));
    return subset_sum(v, sum, v.size() - 1, dp);
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
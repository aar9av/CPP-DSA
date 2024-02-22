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

int subset_count(vector<int> &v, int sum, int idx, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (idx < 0)
        return 0;
    if (dp[sum][idx] != -1)
        return dp[sum][idx];
    long long res = subset_count(v, sum, idx - 1, dp);
    if (sum - v[idx] >= 0)
        res += subset_count(v, sum - v[idx], idx - 1, dp);
    return dp[sum][idx] = res % mod;
}

int solve(vector<int> &v, int sum)
{
    sort(v.begin(), v.end());
    vector<vector<int>> dp(sum + 1, vector<int>(v.size(), -1));
    return subset_count(v, sum, v.size() - 1, dp);
}

main()
{
    fastIO();
    int n, sum;
    cin >> n >> sum;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cout << solve(v, sum);
    return 0;
}
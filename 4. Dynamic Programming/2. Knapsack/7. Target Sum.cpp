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

int count_target_sum(vector<int> &v, int sum, int idx, vector<vector<int>> &dp)
{
    if (idx < 0)
        return sum == 0 ? 1 : 0;
    if (dp[sum][idx] != -1)
        return dp[sum][idx];
    long long res = count_target_sum(v, sum, idx - 1, dp);
    if (sum - v[idx] >= 0)
        res += count_target_sum(v, sum - v[idx], idx - 1, dp);
    return dp[sum][idx] = res % mod;
}

int solve(vector<int> &v, int target)
{
    int sum = accumulate(v.begin(), v.end(), 0);
    if ((sum - target) % 2 || sum < target)
        return 0;
    sum = (sum - target) / 2;
    vector<vector<int>> dp(sum + 1, vector<int>(v.size(), -1));
    return count_target_sum(v, sum, v.size() - 1, dp);
}

main()
{
    fastIO();
    int n, target;
    cin >> n >> target;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cout << solve(v, target);
    return 0;
}
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

int min_coins(vector<int> &coins, int amount, int idx, vector<vector<int>> &dp)
{
    if(amount == 0)
        return 0;
    if(idx < 0)
        return mod;
    if (dp[amount][idx] != -1)
        return dp[amount][idx];
    long long res = min_coins(coins, amount, idx - 1, dp);
    if (amount - coins[idx] >= 0)
        res = min(res, 1 + min_coins(coins, amount - coins[idx], idx, dp));
    return dp[amount][idx] = res;
}

int solve(vector<int> &coins, int amount)
{
    vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), -1));
    int res = min_coins(coins, amount, coins.size() - 1, dp);
    return res == mod ? -1 : res;
}

main()
{
    fastIO();
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i)
        cin >> coins[i];
    cout << solve(coins, amount);
    return 0;
}
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

int max_profit(vector<int> &price, int len, int idx, vector<vector<int>> &dp)
{
    if (len == 0 || idx < 0)
        return 0;
    if (dp[len][idx] != -1)
        return dp[len][idx];
    int res = max_profit(price, len, idx - 1, dp);
    if (len - idx - 1 >= 0)
        res = max(res, price[idx] + max_profit(price, len - idx - 1, idx, dp));
    return dp[len][idx] = res;
}

int solve(vector<int> &price)
{
    vector<vector<int>> dp(price.size() + 1, vector<int>(price.size(), -1));
    return max_profit(price, price.size(), price.size() - 1, dp);
}

main()
{
    fastIO();
    int n;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; ++i)
        cin >> price[i];
    cout << solve(price);
    return 0;
}
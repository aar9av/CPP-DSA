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

int rob(vector<int> &house, int idx, vector<int> &dp)
{
    if (idx <= 1)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    int res = rob(house, idx - 2, dp) + house[idx - 2];
    if (idx - 3 >= 0)
        res = max(res, rob(house, idx - 3, dp) + house[idx - 3]);
    return dp[idx] = res;
}

int solve(vector<int> &house)
{
    vector<int> dp(house.size() + 2, -1);
    return rob(house, house.size() + 1, dp);
}

main()
{
    fastIO();
    int n;
    cin >> n;
    vector<int> house(n);
    for (int i = 0; i < n; ++i)
        cin >> house[i];
    cout << solve(house);
    return 0;
}
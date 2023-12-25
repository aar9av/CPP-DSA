#include <bits/stdc++.h>
using namespace std;

int dp[305][5010];

int cnt(vector<int> &c, int sum, int idx)
{
    if (sum == 0)
        return 1;
    if (idx < 0)
        return 0;
    if (dp[idx][sum] != -1)
        return dp[idx][sum];
    int res = 0;
    for (int i = 0; sum - i >= 0; i += c[idx])
        res += cnt(c, sum - i, idx - 1);
    return dp[idx][sum] = res;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, amt;
    cin >> n >> amt;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    vector<vector<int>> dp(n+1,vector<int> (amt+1));
    for(int i=0;i<=n;i++)
        dp[0][i]=1;
    for(int i=1)
    cout << cnt(coins, amt, coins.size() - 1);
    return 0;
}
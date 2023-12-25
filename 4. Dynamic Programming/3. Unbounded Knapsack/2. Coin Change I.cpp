#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, amt;
    cin >> n >> amt;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    vector<int> dp(amt + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amt; i++)
        for (int j = 0; j < n && i - coins[j] >= 0; j++)
            dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
    cout << (dp[amt]<0?-1:dp[amt]);
    return 0;
}
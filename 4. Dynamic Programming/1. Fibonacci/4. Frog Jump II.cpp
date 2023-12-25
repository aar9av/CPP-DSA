#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> h[i + 1];
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= k; j++)
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
    cout << dp[n];
    return 0;
}
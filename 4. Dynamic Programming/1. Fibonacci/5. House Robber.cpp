#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> h[i + 1];
    vector<int> dp(n + 1, 0);
    dp[1] = h[1];
    for (int i = 2; i <= n; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + h[i]);
    cout << dp[n];
    return 0;
}
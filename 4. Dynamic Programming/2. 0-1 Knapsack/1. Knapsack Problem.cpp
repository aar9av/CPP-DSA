#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, wt;
    cin >> n >> wt;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    w.insert(w.begin(), 0);
    v.insert(v.begin(), 0);
    vector<vector<int>> dp(n + 1, vector<int>(wt + 1, 0));
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < wt + 1; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - w[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
        }
    cout << dp[n][wt];
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a.insert(a.begin(), 0);
    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum % 2)
    {
        cout << "0";
        return 0;
    }
    sum /= 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, 0));
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - a[i] >= 0)
                dp[i][j] = dp[i][j] | dp[i - 1][j - a[i]];
        }
    cout << dp[n][sum];
    return 0;
}
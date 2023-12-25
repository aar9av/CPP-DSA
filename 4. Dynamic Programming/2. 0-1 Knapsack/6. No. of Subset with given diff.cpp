#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, diff;
    cin >> n >> diff;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0);
    a.insert(a.begin(), 0);
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
    int res = 0;
    for (int i = 0; i < sum + 1; i++)
        if (dp[n][i] && abs(sum - 2 * i) == diff)
            res++;
    cout << (res%2?res/2+1:res/2);
    return 0;
}
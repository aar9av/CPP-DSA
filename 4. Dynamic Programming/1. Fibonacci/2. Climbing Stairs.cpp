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

int count_ways(int n, vector<int> &dp)
{
    if (n <= 2)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = (count_ways(n - 1, dp) + count_ways(n - 2, dp)) % mod;
}

int solve(int n)
{
    vector<int> dp(n + 1, -1);
    return count_ways(n, dp);
}

main()
{
    fastIO();
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}
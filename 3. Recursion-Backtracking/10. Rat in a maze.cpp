#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<bool>> grid;
vector<vector<bool>> vis;
vector<string> res;
string s = "";

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void dfs(int y = 0, int x = 0)
{
    if (x < 0 || y < 0)
        return;
    if (x == m || y == n)
        return;

    if (grid[y][x] == 0)
        return;

    if (vis[y][x])
        return;

    vis[y][x] = 1;
    if (x == m - 1 && y == n - 1)
    {
        res.push_back(s);
        vis[y][x] = 0;
        return;
    }

    s += 'L';
    dfs(y, x - 1);
    s.erase(s.size() - 1, 1);
    s += 'U';
    dfs(y - 1, x);
    s.erase(s.size() - 1, 1);
    s += 'D';
    dfs(y + 1, x);
    s.erase(s.size() - 1, 1);
    s += 'R';
    dfs(y, x + 1);
    s.erase(s.size() - 1, 1);
    vis[y][x] = 0;
}

int main()
{
    fastIO();
    cin >> n >> m;
    vector<bool> t(m, 0);
    for (int i = 0; i < n; i++)
    {
        vis.push_back(t);
        vector<bool> v;
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        grid.push_back(v);
    }

    dfs();
    sort(res.begin(), res.end());
    for (auto &i : res)
        cout << i << endl;
    return 0;
}
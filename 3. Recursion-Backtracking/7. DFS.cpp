#include <iostream>
#include <vector>
using namespace std;

vector<int> res;
vector<bool> vis;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void dfs(vector<vector<int>> &g, int node = 0)
{
    if (vis[node])
        return;
    vis[node] = 1;
    res.push_back(node);
    for (auto child : g[node])
        dfs(g, child);
}

int main()
{
    fastIO();
    int v, e;
    cin >> v >> e;
    vector<vector<int>> g(v);
    for (int i = 0; i < e; i++)
    {
        int s, d;
        cin >> s >> d;
        g[s].push_back(d);
    }

    for (int i = 0; i < v; i++)
        vis.push_back(0);
    dfs(g);

    for (auto &it : res)
        cout << it << " ";
    return 0;
}
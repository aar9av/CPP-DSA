#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> b;
string w;
vector<vector<bool>> vis;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool dfs(int x, int y, int i = 0)
{
    if (i == w.size())
        return 1;

    if (x < 0 || y < 0)
        return 0;
    if (x == b.size() || y == b[0].size())
        return 0;

    if (vis[x][y])
        return 0;

    if (b[x][y] != w[i])
        return 0;

    vis[x][y] = 1;

    if (dfs(x, y - 1, i + 1))
        return 1;
    if (dfs(x - 1, y, i + 1))
        return 1;
    if (dfs(x + 1, y, i + 1))
        return 1;
    if (dfs(x, y + 1, i + 1))
        return 1;

    vis[x][y] = 0;
    return 0;
}

int main()
{
    fastIO();
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    b = board;
    cin >> w;
    vector<vector<bool>> v(n, vector<bool>(m, 0));
    vis = v;

    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[i].size(); j++)
            if (dfs(i, j))
            {
                cout << "1";
                return 0;
            }
    cout << "0";
    return 0;
}

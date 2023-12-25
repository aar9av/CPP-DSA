#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
vector<bool> col, d1, d2;
vector<int> t;
int n;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void nQueen(int y = 0)
{
    if (y == n)
    {
        res.push_back(t);
        return;
    }
    for (int x = 0; x < n; x++)
    {
        if (col[x] || d1[x + y] || d2[x - y + n - 1])
            continue;
        col[x] = d1[x + y] = d2[x - y + n - 1] = 1;
        t.push_back(x + 1);
        nQueen(y + 1);
        col[x] = d1[x + y] = d2[x - y + n - 1] = 0;
        t.pop_back();
    }
}

int main()
{
    fastIO();
    n = 5;
    vector<bool> temp(n, 0);
    col = d1 = d2 = temp;
    nQueen();

    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
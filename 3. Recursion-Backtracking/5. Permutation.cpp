#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
vector<bool> vis;
vector<int> temp;

void permut(vector<int> &a)
{
    if (temp.size() == a.size())
    {
        res.push_back(temp);
        return;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        temp.push_back(a[i]);
        permut(a);
        vis[i] = 0;
        temp.pop_back();
    }
}

int main()
{
    vector<int> a = {1, 2, 3};
    for (int i = 0; i < a.size(); i++)
        vis.push_back(0);
    permut(a);
    for (auto &i : res)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
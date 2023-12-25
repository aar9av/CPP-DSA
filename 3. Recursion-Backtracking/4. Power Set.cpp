#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
vector<int> temp;

void powerSet(vector<int> &a, int i = 0)
{
    if (i == a.size())
    {
        res.push_back(temp);
        return;
    }
    powerSet(a, i + 1);
    temp.push_back(a[i]);
    powerSet(a, i + 1);
    temp.pop_back();
}

int main()
{
    vector<int> a = {1, 2, 3};
    powerSet(a);
    for (auto &i : res)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
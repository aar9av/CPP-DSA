#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> res;

void toh(int n, int s = 1, int h = 2, int d = 3)
{
    if (!n)
        return;
    toh(n - 1, s, d, h);
    res.push_back({s, d});
    toh(n - 1, h, s, d);
}

int main()
{
    int n = 4;
    toh(n);
    cout << "Number of steps: " << (1 << n) - 1 << endl;
    for (auto &it : res)
        cout << it.first << " " << it.second << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

vector<vector<string>> res;
vector<string> temp;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool isPal(string s)
{
    for (int i = 0; i < s.size() / 2; i++)
        if (s[i] != s[s.size() - 1 - i])
            return 0;
    return 1;
}

void partition(string s, int idx = 0)
{
    if (idx == s.size())
    {
        res.push_back(temp);
        return;
    }
    for (int i = idx; i < s.size(); i++)
        if (isPal(s.substr(idx, i - idx + 1)))
        {
            temp.push_back(s.substr(idx, i - idx + 1));
            partition(s, i + 1);
            temp.pop_back();
        }
}

int main()
{
    fastIO();
    string s;
    cin >> s;
    partition(s);

    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
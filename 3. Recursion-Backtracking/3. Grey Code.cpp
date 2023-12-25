#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

vector<int> greyCode(int n)
{
    if (n == 1)
        return {0, 1};
    vector<int> res = greyCode(n - 1), rev = res;
    reverse(rev.begin(), rev.end());
    for (auto &it : rev)
        res.push_back(it + (1 << n - 1));
    return res;
}

vector<string> greyCodeStr(int n)
{
    vector<int> res = greyCode(n);
    vector<string> strRes;
    for (auto &it : res)
        strRes.push_back(bitset<32>(it).to_string());
    for (auto &it : strRes)
        it.erase(0, 32 - n);
    return strRes;
}

int main()
{
    int n = 4;
    vector<string> res = greyCodeStr(n);
    for (auto &it : res)
        cout << it << endl;
    return 0;
}
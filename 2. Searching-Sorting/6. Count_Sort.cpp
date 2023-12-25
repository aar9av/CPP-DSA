#include <iostream>
#include <vector>
#include <map>
using namespace std;

void print(vector<int> &a)
{
    for (auto &it : a)
        cout << it << " ";
}

void countSort(vector<int> &a)
{
    // Swap 2 adjacent element if they are in wrong order
    map<int, int> freq;
    for (auto &it : a)
        freq[it]++;
    a.clear();
    for (auto &it : freq)
        while (it.second--)
            a.push_back(it.first);
}

int main()
{
    vector<int> a = {9, 1, 5, 3, 6, 0, 4, 2, 7, 8};
    countSort(a);
    print(a);
    return 0;
}
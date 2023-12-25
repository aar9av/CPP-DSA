#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> &a, int key)
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] == key)
            return i;
    return -1;
}

int main()
{
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 5;
    cout << linearSearch(a, key);
    return 0;
}
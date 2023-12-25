#include <iostream>
#include <vector>
using namespace std;

bool ok(vector<int> &a, int key, int mid)
{
    // This function is customizable for predicate functions.
    return a[mid] >= key;
}

int binarySearch(vector<int> &a, int key)
{
    // This function returns the key index if found otherwise its insert position
    int s = 0, e = a.size() - 1, res;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (ok(a, key, mid))
        {
            res = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return res;
}

int main()
{
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 2;
    cout << binarySearch(a, key);
    return 0;
}
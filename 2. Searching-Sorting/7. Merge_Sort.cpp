#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &a)
{
    for (auto &it : a)
        cout << it << " ";
}

void merge(vector<int> &a, int l, int mid, int r)
{
    // merge the 2 array
    vector<int> res;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r)
        res.push_back(a[i] < a[j] ? a[i++] : a[j++]);
    while (i <= mid)
        res.push_back(a[i++]);
    while (j <= r)
        res.push_back(a[j++]);
    for (int i = l; i <= r; i++)
        a[i] = res[i - l];
}

void mergeSort(vector<int> &a, int l, int r)
{
    // Split the array into 2 until arr.size()==1 then merge it in sorted order
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, mid, r);
}

int main()
{
    vector<int> a = {9, 1, 5, 3, 6, 0, 4, 2, 7, 8};
    mergeSort(a, 0, a.size() - 1);
    print(a);
    return 0;
}
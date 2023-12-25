#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &a)
{
    for (auto &it : a)
        cout << it << " ";
}

int partition(vector<int> &a, int l, int r)
{
    // Search pivot element and place all small element to its left side and vice versa
    int pvt=a[l],i=r;
    for(int j=r;j>l;j--)
        if(a[j]>pvt)
            swap(a[i--],a[j]);
    swap(a[i],a[l]);
    return i;
}

void quickSort(vector<int> &a, int l, int r)
{
    // Select a pivot element and place it in its correct position
    if (l >= r)
        return;
    int pvt = partition(a,l,r);
    quickSort(a, l, pvt-1);
    quickSort(a, pvt + 1, r);
}

int main()
{
    vector<int> a = {9, 1, 5, 3, 6, 0, 4, 2, 7, 8};
    quickSort(a, 0, a.size() - 1);
    print(a);
    return 0;
}
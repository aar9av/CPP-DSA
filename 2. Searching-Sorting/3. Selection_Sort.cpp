#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &a)
{
    for (auto &it : a)
        cout << it << " ";
}

void selectionSort(vector<int> &a)
{
    // Find the min element and swap it with first element
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]);
}

int main()
{
    vector<int> a = {9, 1, 5, 3, 6, 0, 4, 2, 7, 8};
    selectionSort(a);
    print(a);
    return 0;
}
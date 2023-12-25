#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &a)
{
    for (auto &it : a)
        cout << it << " ";
}

void insertionSort(vector<int> &a)
{
    // Insert an element from unsorted array to its correct position
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key)
            a[j + 1] = a[j--];
        a[j + 1] = key;
    }
}

int main()
{
    vector<int> a = {9, 1, 5, 3, 6, 0, 4, 2, 7, 8};
    insertionSort(a);
    print(a);
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &a)
{
    for (auto &it : a)
        cout << it << " ";
}

void bubbleSort(vector<int> &a)
{
    // Swap 2 adjacent element if they are in wrong order
    int n = a.size();
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
    print(a);
}

int main()
{
    vector<int> a = {9, 1, 5, 3, 6, 0, 4, 2, 7, 8};
    bubbleSort(a);
    return 0;
}
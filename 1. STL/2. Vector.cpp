#include <iostream>
#include <vector>
using namespace std;

void v()
{
    // VECTOR

    // Initialization
    vector<bool> v1(10, 0);
    vector<int> v2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Access values
    for (auto &it : v2)
        cout << it << " ";
    cout << endl;

    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl;

    for (auto i = v2.begin(); i < v2.end(); i++)
        cout << v2[i - v2.begin()] << " ";
    cout << endl;

    // Add or remove value
    v1.push_back(1);
    v2.pop_back();

    // To delete all values
    v1.clear();
    cout << v1.empty() << endl;

    // To delete at specific position
    v2.erase(v2.begin() + 0);
    v2.erase(v2.begin(), v2.begin() + 3);

    // To insert a value at specific position
    v1.insert(v1.begin() + 5, 1);
}

int main()
{
    v();
    return 0;
}
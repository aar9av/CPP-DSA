#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

void st()
{
    // SET

    // Stores unique value in sorted order
    set<char> s;
    // Stores unique value in random order
    unordered_set<char> us;
    // Can stores duplicate value in sorted order
    multiset<char> ms;
    // Can stores duplicate value in random order
    unordered_multiset<char> ums;

    // Count frequency characters in a string
    string str = "Hello";
    for (auto it : str)
        s.insert(it);
    for (auto it : s)
        cout << it << endl;

    // Check if a value exist or not
    cout << s.count('z') << endl;
}

void mp()
{
    // MAP

    // Stores unique key in sorted order
    map<char, int> m;
    // Stores unique key in random order
    unordered_map<char, int> um;
    // Can stores duplicate key in sorted order
    multimap<char, int> mm;
    // Can stores duplicate key in random order
    unordered_multimap<char, int> umm;

    // Count frequency characters in a string
    string str = "Hello";
    for (auto it : str)
        m[it]++;
    for (auto it : m)
        cout << it.first << " " << it.second << endl;

    // Check if a key exist or not
    cout << m.count('l') << endl;
}

int main()
{
    mp();
    st();
    return 0;
}
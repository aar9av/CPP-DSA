#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void stringOperations()
{
    // Bitset: Find binary of a number
    int n = 1023;
    bitset<16> binary(n);
    string bin = bitset<16>(n).to_string();
    cout << binary << " " << bin << endl;

    // Next Permutation
    string str = "abc";
    do
    {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));

    // SubString
    cout << str.substr(0, 2) << endl;

    // Seperate words in a line
    string s;
    getline(cin, s);
    string word;
    istringstream iss(s);
    while (getline(iss, word, ' '))
        cout << word << endl;
}

bool comp(string a, string b)
{
    // Customizable function according to condition
    // Rteurn "True" if there is no need to swap
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

void sortOperations(vector<string> &v)
{
    // Sort in accending order
    sort(v.begin(), v.end());

    // Sort in decending order
    sort(v.begin(), v.end(), greater<string>());

    // Sort in given condition Eg. Sort string by length and then by alphabetical order
    sort(v.begin(), v.end(), comp);
}

void arrayOperations(vector<string> &v)
{
    // Find an element
    cout << find(v.begin(), v.end(), "z") - v.begin() << endl;

    // Lower Bound: Return first array element pointer whose value is atleast x
    cout << lower_bound(v.begin(), v.end(), "z") - v.begin() << endl;

    // Upper Bound: Return first array element pointer whose value is larger than x
    cout << upper_bound(v.begin(), v.end(), "z") - v.begin() << endl;

    // Reverse a vector
    reverse(v.begin(), v.end());
}

int main()
{
    vector<string> v = {"a", "ab", "abc", "ccc", "x", "dsa", "ys", "z"};

    arrayOperations(v);
    sortOperations(v);
    stringOperations();

    return 0;
}
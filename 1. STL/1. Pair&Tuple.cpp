#include <iostream>
#include <tuple>
using namespace std;

void p()
{
    // PAIR

    // Initialization
    pair<int, string> p(1, "a");

    p = {2, "b"};

    p = make_pair(3, "c");

    p.first = 4;
    p.second = "d";

    // Access Values
    cout << "Pair Values: " << p.first << " " << p.second << endl;
}

void t()
{
    // tuple

    // Initialization
    auto t = make_tuple(1, 1.1, "a");

    t = {2, 2.2, "b"};

    // Get size of tuple
    cout << "Size of Tuple: " << tuple_size<decltype(t)>::value << endl;

    // Access Values
    cout << "Tuple Values: " << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
}

int main()
{

    p();
    t();
    return 0;
}
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void sort(stack<int> &stk)
{
    if (stk.size() == 1)
        return;
    int pvt = stk.top();
    stk.pop();
    sort(stk);
    vector<int> v;
    while (!stk.empty() && stk.top() > pvt)
    {
        v.push_back(stk.top());
        stk.pop();
    }
    stk.push(pvt);
    for (int i = v.size() - 1; i >= 0; i--)
        stk.push(v[i]);
}

int main()
{
    stack<int> stk;
    for (int i = 0; i < 5; i++)
        stk.push(2 * i % 5);

    sort(stk);
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    return 0;
}
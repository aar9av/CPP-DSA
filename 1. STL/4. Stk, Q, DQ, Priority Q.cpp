#include <iostream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

void pq()
{
    // PRIORITY QUEUE
    // MAX HHEAP
    priority_queue<int> minH;

    minH.push(1);
    minH.push(3);
    minH.push(2);
    while (!minH.empty())
    {
        cout << minH.top() << endl;
        minH.pop();
    }

    // MIN HEAP
    priority_queue<int, vector<int>, greater<int>> maxH;

    maxH.push(1);
    maxH.push(3);
    maxH.push(2);
    while (!maxH.empty())
    {
        cout << maxH.top() << endl;
        maxH.pop();
    }
}

void deq()
{
    // DOUBLE ENDED QUEUE
    deque<int> dq;

    dq.push_front(1);
    dq.push_back(2);
    if (!dq.empty())
        cout << dq.front() << " " << dq.back() << endl;
    cout << dq.at(0) << endl;
    dq.pop_front();
    dq.pop_back();
}

void q()
{
    // QUEUE
    queue<int> q;

    q.push(1);
    if (!q.empty())
        cout << q.front() << " " << q.back() << endl;
    q.pop();
}

void stk()
{
    // STACK
    stack<int> s;

    s.push(1);
    if (!s.empty())
        cout << s.top() << endl;
    s.pop();
}

int main()
{
    stk();
    q();
    deq();
    pq();
    return 0;
}

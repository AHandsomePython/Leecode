#include<iostream>
#include <queue>
#include <functional>

using namespace std;

struct MyCompare
{
    bool operator()(const int& a, const int& b) const
    {
        return a > b; // a>b返回true
    }
};

int main()
{
    priority_queue<int, vector<int>, MyCompare> pq;
    pq.push(1);
    pq.push(3);
    pq.push(2);
    while (!pq.empty()) {
        cout << pq.top() << " "; //小顶堆
        pq.pop();
    }
    return 0;
}

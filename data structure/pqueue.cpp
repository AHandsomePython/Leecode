#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> pq;
    pq.push(1);
    pq.push(3);
    pq.push(2);
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    // 默认大顶堆
    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // =========================
    // 1. Max Heap (Default)
    // =========================

    priority_queue<int> pq;

    // push()
    pq.push(10);
    pq.push(30);
    pq.push(20);

    // emplace()
    pq.emplace(40);

    // top()
    cout << "Max Heap Top: " << pq.top() << endl;

    // size()
    cout << "Size: " << pq.size() << endl;

    // empty()
    cout << "Is priority queue empty? " << pq.empty() << endl;

    // pop()
    pq.pop();

    cout << "Top after pop: " << pq.top() << endl;


    // =========================
    // 2. Min Heap (Reverse Order)
    // =========================

    priority_queue<int, vector<int>, greater<int>> pqMin;

    // push()
    pqMin.push(10);
    pqMin.push(30);
    pqMin.push(20);

    // emplace()
    pqMin.emplace(5);

    // top()
    cout << "\nMin Heap Top: " << pqMin.top() << endl;

    // size()
    cout << "Size: " << pqMin.size() << endl;

    // empty()
    cout << "Is priority queue empty? " << pqMin.empty() << endl;

    // pop()
    pqMin.pop();

    cout << "Top after pop: " << pqMin.top() << endl;


    // =========================
    // 3. Swap
    // =========================

    priority_queue<int> pq2;

    pq2.push(100);
    pq2.push(200);

    pq.swap(pq2);

    cout << "\nMax Heap top after swap: " << pq.top() << endl;

    return 0;
}
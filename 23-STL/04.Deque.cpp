#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;

    // Add element at the front
    dq.push_front(10);

    // Add element at the back
    dq.push_back(20);

    // Add element at the front using emplace
    dq.emplace_front(5);

    // Add element at the back using emplace
    dq.emplace_back(30);

    // Display deque
    cout << "Deque: ";

    for (auto it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
    // Delete element from the front
    dq.pop_front();

    // Delete element from the back
    dq.pop_back();

    // Deque is now {10, 20}, so valid indexes are 0 and 1
    cout << "Element at index 1: " << dq[1] << endl;

    // Display after deletion
    cout << "After pop operations: ";
    for (auto it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}
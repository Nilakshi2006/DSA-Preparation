#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l;

    // Add element at the front
    l.push_front(10);

    // Add element at the back
    l.push_back(20);

    // Add element at the front using emplace
    l.emplace_front(5);

    // Add element at the back using emplace
    l.emplace_back(30);

    // Display list
    cout << "List: ";
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    // Delete element from the front
    l.pop_front();

    // Delete element from the back
    l.pop_back();

    // Display after deletion
    cout << "After pop operations: ";
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}
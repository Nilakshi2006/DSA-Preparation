#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    // push()
    q.push(10);
    q.push(20);
    q.push(30);

    // emplace()
    q.emplace(40);

    // front()
    cout << "Front element: " << q.front() << endl;

    // back()
    cout << "Back element: " << q.back() << endl;

    // size()
    cout << "Size: " << q.size() << endl;

    // empty()
    cout << "Is queue empty? " << q.empty() << endl;

    // pop()
    q.pop();

    cout << "Front after pop: " << q.front() << endl;

    // swap()
    queue<int> q2;

    q2.push(100);
    q2.push(200);

    q.swap(q2);

    cout << "Front of queue after swap: " << q.front() << endl;

    return 0;
}
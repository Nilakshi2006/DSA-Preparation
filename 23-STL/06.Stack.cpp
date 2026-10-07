#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;

    // push()
    st.push(10);
    st.push(20);
    st.push(30);

    // emplace()
    st.emplace(40);

    // top()
    cout << "Top element: " << st.top() << endl;

    // size()
    cout << "Size: " << st.size() << endl;

    // empty()
    cout << "Is stack empty? " << st.empty() << endl;

    // pop()
    st.pop();

    cout << "Top after pop: " << st.top() << endl;

    // swap()
    stack<int> st2;

    st2.push(100);
    st2.push(200);

    st.swap(st2);

    cout << "Top of stack after swap: " << st.top() << endl;

    return 0;
}




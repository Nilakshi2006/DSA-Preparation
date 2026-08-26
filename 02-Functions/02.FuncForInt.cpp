#include <iostream>
using namespace std;
int hello()
{
    cout << "Hello" << endl;
    return 9;
}
int main()
{
    int val = hello();
    cout << "Value is:" << val << endl;

    return 0;
}
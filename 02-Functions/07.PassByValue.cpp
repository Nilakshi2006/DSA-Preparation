#include <iostream>
using namespace std;
int sum(int a, int b)
{
    // These values of ab and b not being updated
    a = a + 10;
    b = b + 10;
    return (a + b);
}
int main()
{

    int a = 3;
    int b = 4;
    cout << sum(a, b) << endl;
    cout << a << endl;
    cout << b << endl;

    return 0;
}
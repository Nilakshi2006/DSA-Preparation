#include <iostream>
using namespace std;
int x = 10; // global
void fun()
{
    cout << x << endl;
}
int main()
{
    fun();
    cout << x << endl;

    return 0;
}
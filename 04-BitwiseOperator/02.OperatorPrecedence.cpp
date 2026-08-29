#include <iostream>
using namespace std;

int main()
{
    // General
    cout << (5 - 2 * 6) << endl;
    // if want to give priority f lower
    cout << ((5 - 2) * 6) << endl;
    // Same priority operator(check associativity)
    cout << (4 * 5 % 2) << endl;
    return 0;
}
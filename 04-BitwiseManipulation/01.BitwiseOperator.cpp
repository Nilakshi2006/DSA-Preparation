#include <iostream>
using namespace std;

int main()
{

    int a = 4, b = 8;
    // Bitwise AND
    cout << (a & b) << endl;
    // Bitwise OR
    cout << (a | b) << endl;
    //  Bitwise XOR
    cout << (a ^ b) << endl;
    // Bitwise Left Shift(here 2 is how many bits u want to shift)
    cout << (a << 2) << endl;
    // Bitwise Right Shift
    cout << (a >> 1) << endl;
    return 0;
}
#include <iostream>
using namespace std;
int decToBin(int dec)
{
    int ans = 0, pow = 1; // pow=1=>10^0
    while (dec > 0)
    {
        int rem = dec % 2;
        dec = dec / 2;
        ans = ans + (rem * pow);
        pow = pow * 10;
    }
    return ans;
}
int main()
{
    int dec = 50;
    cout << decToBin(dec);

    return 0;
}
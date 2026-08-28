#include <iostream>
using namespace std;
int BintoDec(int bin)
{
    int ans = 0, pow = 1;
    while (bin > 0)
    {
        int rem = bin % 10;
        ans += rem * pow;
        bin /= 10;
        pow = 2 * pow;
    }
    return ans;
}
int main()
{
    int bin = 1010;
    cout << BintoDec(bin);

    return 0;
}
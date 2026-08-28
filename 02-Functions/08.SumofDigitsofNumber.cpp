#include <iostream>
using namespace std;
int sumofDigits(int num)
{
    int digitSum = 0;
    while (num > 0)
    {
        int lastDigit = num % 10; // to get last digit of number
        num = num / 10;           // to delete last digit from number
        digitSum = digitSum + lastDigit;
    }
    return digitSum;
}
int main()
{
    cout << sumofDigits(203);

    return 0;
}
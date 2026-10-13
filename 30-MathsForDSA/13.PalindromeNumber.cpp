
#include <iostream>
#include <climits>
using namespace std;

bool isPalindrome(int x) {
    int org = x;
    int rev = 0;

    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    while (x != 0) {
        int lastDig = x % 10;

        if (rev > INT_MAX / 10 || rev < INT_MIN / 10) {
            return false;
        }

        rev = (rev * 10) + lastDig;
        x = x / 10;
    }

    return org == rev;
}

int main() {
    int x = 121;

    if (isPalindrome(x)) {
        cout << x << " is a palindrome";
    } else {
        cout << x << " is not a palindrome";
    }

    return 0;
}

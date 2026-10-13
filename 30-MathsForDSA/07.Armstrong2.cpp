
#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int n) {
    int original = n;
    int rev = 0;

    while (n > 0) {
        int rem = n % 10;
        rev += pow(rem, 3);
        n = n / 10;
    }

    return rev == original;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isArmstrong(n)) {
        cout << "Armstrong number";
    } else {
        cout << "Not an Armstrong number";
    }

    return 0;
}

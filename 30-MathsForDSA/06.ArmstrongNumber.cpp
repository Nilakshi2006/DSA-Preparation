
#include <iostream>
using namespace std;

bool armStrong(int n) {
    int copy = n;
    int sum = 0;

    while (n != 0) {
        int digit = n % 10;
        sum += digit * digit * digit;
        n = n / 10;
    }

    return sum == copy;
}

int main() {
    int n = 153;

    if (armStrong(n)) {
        cout << "Number is Armstrong";
    } else {
        cout << "Number is not Armstrong";
    }

    return 0;
}

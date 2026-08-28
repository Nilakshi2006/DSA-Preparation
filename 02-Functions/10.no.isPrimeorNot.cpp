#include <iostream>
using namespace std;

// Function to check prime
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPrime(num)) {
        cout << num << " is a Prime Number";
    } else {
        cout << num << " is Not a Prime Number";
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int n = 1234;
    int rev = 0;

    while (n > 0) {
        int lastdig = n % 10;
        rev = rev * 10 + lastdig;
        n = n / 10;
    }

    cout << "Reversed number = " << rev;

    return 0;
}

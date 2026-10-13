
#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n) {
    vector<bool> isPrime(n, true);
    int count = 0;

    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;

            for (int j = i * 2; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return count;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Number of primes less than " << n
         << " = " << countPrimes(n) << endl;

    return 0;
}

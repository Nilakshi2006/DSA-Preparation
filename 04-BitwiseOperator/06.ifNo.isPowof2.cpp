// //Using loop
// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     if (n <= 0) {
//         cout << "Not a Power of 2";
//         return 0;
//     }

//     while (n > 1) {
//         if (n % 2 != 0) {
//             cout << "Not a Power of 2";
//             return 0;
//         }
//         n = n / 2;
//     }

//     cout << "Power of 2";
//     return 0;
// }


//Using Bitwise Operator
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n > 0 && (n & (n - 1)) == 0)
        cout << "Power of 2";
    else
        cout << "Not a Power of 2";

    return 0;
}
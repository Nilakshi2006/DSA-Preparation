#include <iostream>
using namespace std;

int main()
{

    int n = 4;
    for (int i = 0; i < n; i++)
    {
        // space
        for (int s = 0; s < n - i - 1; s++)
        {
            cout << " ";
        }
        // left side
        for (int j = 1; j <= i + 1; j++)
        {
            cout << j;
        }
        // right side
        for (int k = i; k > 0; k--)
        {
            cout << k;
        }
        cout << endl;
    }

    return 0;
}

// Output
//     1
//    121
//   12321
//  1234321
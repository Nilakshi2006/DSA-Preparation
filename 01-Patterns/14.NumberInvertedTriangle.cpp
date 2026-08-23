#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s < i; s++)
        {
            cout << " ";
        }
        for (int j = n; j > i; j--)
        {
            cout << i + 1;
        }

        cout << endl;
    }

    return 0;
}

// Output
// 1111
//  222
//   33
//    4
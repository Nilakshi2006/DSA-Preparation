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
        char ch=i+'A';
        for (int j = n; j > i; j--)
        {
            cout << ch;
        }

        cout << endl;
    }

    return 0;
}

// Output
// AAAA
//  BBB
//   CC
//    D
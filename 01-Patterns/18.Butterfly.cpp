#include <iostream>
using namespace std;

int main()
{
    int n = 4;

    // Upper Half
    for (int i = 0; i < n; i++)
    {
        // Left Stars
        for (int j = 0; j <= i; j++)
            cout << "*";

        // Spaces
        for (int s = 0; s < 2 * (n - i - 1); s++)
            cout << " ";

        // Right Stars
        for (int j = 0; j <= i; j++)
            cout << "*";

        cout << endl;
    }

    // Lower Half
    for (int i = n - 1; i >= 0; i--)
    {
        // Left Stars
        for (int j = 0; j <= i; j++)
            cout << "*";

        // Spaces
        for (int s = 0; s < 2 * (n - i - 1); s++)
            cout << " ";

        // Right Stars
        for (int j = 0; j <= i; j++)
            cout << "*";

        cout << endl;
    }

    return 0;
}
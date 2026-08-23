#include <iostream>
using namespace std;

int main()
{
    int n = 4;

    // Upper half
    for (int i = 0; i < n; i++)
    {
        // Spaces
        for (int s = 0; s < n - i - 1; s++)
            cout << " ";

        // Hollow part
        for (int j = 0; j < 2 * i + 1; j++)
        {
            if (j == 0 || j == 2 * i)
                cout << "*";
            else
                cout << " ";
        }

        cout << endl;
    }

    // Lower half
    for (int i = n - 2; i >= 0; i--)
    {
        for (int s = 0; s < n - i - 1; s++)
            cout << " ";

        for (int j = 0; j < 2 * i + 1; j++)
        {
            if (j == 0 || j == 2 * i)
                cout << "*";
            else
                cout << " ";
        }

        cout << endl;
    }

    return 0;
}
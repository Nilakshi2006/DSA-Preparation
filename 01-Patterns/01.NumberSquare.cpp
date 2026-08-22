// #include <iostream>
// using namespace std;

// int main()
// {
//     int n = 4;
//     for (int i = 0; i < n; i++)
//     {
//         int num = 1;
//         for (int j = 0; j < n; j++)
//         {
//             cout << num;
//             num++;
//         }

//         cout << endl;
//     }
//     return 0;
// }

// or
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 4;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}
// Output
//  1234
//  1234
//  1234
//  1234
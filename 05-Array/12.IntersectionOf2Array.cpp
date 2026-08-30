#include <iostream>
using namespace std;

int main()
{
    int arr1[] = {2, 4, 6};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Intersection: ";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j])
            {
                cout << arr1[i] << " ";
                break;
            }
        }
    }

    return 0;
}
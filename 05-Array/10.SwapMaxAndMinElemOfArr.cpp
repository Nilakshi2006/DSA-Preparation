#include <iostream>
using namespace std;

int main()
{
    int arr[] = {9, 3, 4, 5, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int minIndex = 0;
    int maxIndex = 0;

    // Find index of minimum and maximum element
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }

        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }

    // Swap the elements in the array
    swap(arr[minIndex], arr[maxIndex]);

    cout << "Array after swapping min and max values: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
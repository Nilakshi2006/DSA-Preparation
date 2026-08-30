#include <iostream>
using namespace std;

int main()
{

    int size;
    cout << "Enter the size of Array: ";
    cin >> size;
    int arr[size];

    cout << "Enter the " << size << " Elements of Array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int small = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < small)
        {
            small = arr[i];
        }
    }
    cout << "Smallest element in Array is: " << small;

    return 0;
}
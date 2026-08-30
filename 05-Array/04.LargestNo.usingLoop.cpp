#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "Enter the size of Array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the " << n << " Elements of Array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    cout << "Largest element if arr is: " << largest;

    return 0;
}
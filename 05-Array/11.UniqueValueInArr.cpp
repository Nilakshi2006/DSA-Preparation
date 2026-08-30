#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2, 3, 4, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int freq[10] = {0};

    // Step 1: Count frequency
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    // Step 2: Print the unique element
    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]] == 1)
        {
            cout << "Unique element is: " << arr[i] << endl;
            break;   // Stop after finding the first unique element
        }
    }

    return 0;
}
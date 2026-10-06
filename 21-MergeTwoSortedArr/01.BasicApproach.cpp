#include <iostream>
using namespace std;

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};

    int n = 4;
    int m = 4;

    int arr3[n + m];

    int i = 0, j = 0, k = 0;
//i for arr1,j for arr2,k for arr3

    // Compare elements of both arrays
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }

    // Copy remaining elements of arr1
    while (i < n) {
        arr3[k++] = arr1[i++];
    }

    // Copy remaining elements of arr2
    while (j < m) {
        arr3[k++] = arr2[j++];
    }

    // Print merged array
    cout << "Merged array: ";

    for (int i = 0; i < n + m; i++) {
        cout << arr3[i] << " ";
    }

    return 0;
}
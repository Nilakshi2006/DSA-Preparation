#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};

    // Pointer points to first element
    int *ptr = arr;

    cout << "Initial Value: " << *ptr << endl;
    // Output: Initial Value: 10

    // 1. Increment Pointer
    ptr++;
    cout << "After Increment (ptr++): " << *ptr << endl;
    // Output: After Increment (ptr++): 20

    // 2. Decrement Pointer
    ptr--;
    cout << "After Decrement (ptr--): " << *ptr << endl;
    // Output: After Decrement (ptr--): 10

    // 3. Pointer Addition
    ptr = ptr + 3;
    cout << "After Adding 3 (ptr + 3): " << *ptr << endl;
    // Output: After Adding 3 (ptr + 3): 40

    // 4. Pointer Subtraction
    ptr = ptr - 2;
    cout << "After Subtracting 2 (ptr - 2): " << *ptr << endl;
    // Output: After Subtracting 2 (ptr - 2): 20

    // 5. Subtract Two Pointers
    int *ptr1 = &arr[4];   // Points to 50
    int *ptr2 = &arr[1];   // Points to 20

    cout << "Pointer Difference (ptr1 - ptr2): " << ptr1 - ptr2 << endl;
    // Output: Pointer Difference (ptr1 - ptr2): 3

    // 6. Pointer Comparison
    if (ptr1 == ptr2)
        cout << "Pointers are Equal" << endl;
    else
        cout << "Pointers are Not Equal" << endl;
    // Output: Pointers are Not Equal

    if (ptr1 > ptr2)
        cout << "ptr1 is after ptr2" << endl;
    // Output: ptr1 is after ptr2

    if (ptr2 < ptr1)
        cout << "ptr2 is before ptr1" << endl;
    // Output: ptr2 is before ptr1

    return 0;
}
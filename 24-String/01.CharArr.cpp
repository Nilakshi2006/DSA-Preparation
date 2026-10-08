#include <iostream>
#include <cstring>
using namespace std;

int main() {

    // 1. Declaration
    char arr[100];

    // 2. Initialization
    char name[] = "Nilakshi";

    // 3. Assigning character by character
    char city[20] = {'D', 'e', 'l', 'h', 'i', '\0'};

    // 4. Assigning a string during declaration
    char college[50] = "Rayat Bahra University";

    // 5. Taking input without spaces
    cout << "Enter your name: ";
    cin >> arr;

    cout << "Name: " << arr << endl;

    // 6. Taking complete input WITH spaces
    cin.ignore();

    cout << "Enter your full name: ";
    cin.getline(arr, 100);

    cout << "Full name: " << arr << endl;

    // 7. Length of character array
    cout << "Length: " << strlen(arr) << endl;

    // 8. Loop through character array
    cout << "Characters: ";

    for(int i = 0; arr[i] != '\0'; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    // 9. Access individual character
    cout << "First character: " << arr[0] << endl;

    // 10. Compare two character arrays
    char str1[] = "Hello";
    char str2[] = "Hello";

    if(strcmp(str1, str2) == 0) {
        cout << "Both strings are same" << endl;
    }

    // 11. Copy one character array into another
    char str3[20];

    strcpy(str3, str1);

    cout << "Copied string: " << str3 << endl;

    // 12. Concatenate two character arrays
    char a[50] = "Hello ";
    char b[] = "World";

    strcat(a, b);

    cout << "After concatenation: " << a << endl;

    return 0;
}
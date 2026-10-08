#include <iostream>
#include <string>
using namespace std;

int main() {

    // 1. Initialization
    string str1 = "Hello";

    // 2. Empty string
    string str2;

    // 3. Another way of initialization
    string str3("World");

    // 4. Assigning a string
    str2 = "C++";

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    // 5. Taking input without spaces
    string name;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Name: " << name << endl;

    // 6. Taking complete input WITH spaces
    cin.ignore();

    cout << "Enter your full name: ";
    getline(cin, name);

    cout << "Full name: " << name << endl;

    // 7. Length
    cout << "Length: " << name.length() << endl;

    // 8. size() also gives length
    cout << "Size: " << name.size() << endl;

    // 9. Access characters
    cout << "First character: " << name[0] << endl;

    // 10. Loop using index
    cout << "Characters: ";

    for(int i = 0; i < name.length(); i++) {
        cout << name[i] << " ";
    }

    cout << endl;

    // 11. Loop using range-based for loop
    cout << "Characters using range loop: ";

    for(char ch : name) {
        cout << ch << " ";
    }

    cout << endl;

    // 12. Addition / Concatenation
    string first = "Hello";
    string second = "World";

    string result = first + " " + second;

    cout << "Combined: " << result << endl;

    // 13. Append
    first += " C++";

    cout << "After += : " << first << endl;

    // 14. Compare two strings
    string a = "Hello";
    string b = "Hello";

    if(a == b) {
        cout << "Both strings are same" << endl;
    }

    // 15. Compare using !=
    if(a != second) {
        cout << "Strings are different" << endl;
    }

    // 16. Add one character
    a.push_back('!');

    cout << "After push_back: " << a << endl;

    // 17. Remove last character
    a.pop_back();

    cout << "After pop_back: " << a << endl;

    // 18. Access first and last character
    cout << "First: " << a.front() << endl;
    cout << "Last: " << a.back() << endl;

    // 19. Substring
    string text = "Programming";

    cout << "Substring: " << text.substr(0, 4) << endl;

    // 20. Find
    cout << "Position of 'gram': "
         << text.find("gram") << endl;

    return 0;
}
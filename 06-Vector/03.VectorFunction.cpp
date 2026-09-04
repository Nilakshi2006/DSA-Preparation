#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr;

    arr.push_back(24);   // Add element at the end
    arr.push_back(80);
    arr.push_back(30);

    arr.pop_back();      // Remove last element (30)

    cout << "First Element: " << arr.front() << endl;  // 24
    cout << "Last Element: " << arr.back() << endl;    // 80

    cout << "Element at index 1: " << arr.at(1) << endl; // 80

    cout << "Vector Elements: ";
    for (int value : arr)
    {
        cout << value << " ";
    }

    cout << endl;
    cout << "Size of Vector is: " << arr.size() << endl;

    return 0;
}
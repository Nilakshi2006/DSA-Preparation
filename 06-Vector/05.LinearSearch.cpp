#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);

    int n = arr.size();

    int key;
    cout << "Enter the value of key: ";
    cin >> key;

    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at index " << i << endl;
            break;
        }
    }

    if (i == n)
    {
        cout << "Element is not present in the array." << endl;
    }

    return 0;
}
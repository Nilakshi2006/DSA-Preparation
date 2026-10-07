#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Comparator function
bool comp(int a, int b)
{
    return a > b;   // descending order
}

int main()
{
    // =====================================
    // 1. Array + sort(arr, arr + n)
    // =====================================

    int arr[] = {5, 2, 8, 1, 3};
    int n = 5;

    sort(arr, arr + n);

    cout << "Array after ascending sort: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;


    // =====================================
    // 2. Vector + sort(begin, end)
    // =====================================

    vector<int> v = {50, 20, 40, 10, 30};

    sort(v.begin(), v.end());

    cout << "Vector after ascending sort: ";

    for (int x : v)
    {
        cout << x << " ";
    }

    cout << endl;


    // =====================================
    // 3. Sorting using comparator
    // =====================================

    int arr2[] = {5, 2, 8, 1, 3};

    sort(arr2, arr2 + 5, comp);

    cout << "Array after descending sort: ";

    for (int i = 0; i < 5; i++)
    {
        cout << arr2[i] << " ";
    }

    cout << endl;


    // =====================================
    // 4. Using greater<int>
    // =====================================

    vector<int> v2 = {10, 40, 20, 50, 30};

    sort(v2.begin(), v2.end(), greater<int>());

    cout << "Vector descending using greater: ";

    for (int x : v2)
    {
        cout << x << " ";
    }

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    // =====================================
    // 1. Sort pair
    // =====================================

    vector<pair<int, int>> v = {
        {1, 50},
        {2, 20},
        {3, 40},
        {4, 10}
    };

    // Default sorting:
    // First element is compared first,
    // then second element if first is same.

    sort(v.begin(), v.end());

    cout << "Sorted pairs: ";

    for (auto p : v)
    {
        cout << "(" << p.first << "," << p.second << ") ";
    }

    cout << endl;


    // =====================================
    // 2. Sort pair according to second value
    // =====================================

    sort(v.begin(), v.end(),
        [](pair<int, int> a, pair<int, int> b)
        {
            return a.second < b.second;
        });

    cout << "Sorted by second value: ";

    for (auto p : v)
    {
        cout << "(" << p.first << "," << p.second << ") ";
    }

    cout << endl;


    // =====================================
    // 3. reverse()
    // =====================================

    vector<int> arr = {1, 2, 3, 4, 5};

    reverse(arr.begin(), arr.end());

    cout << "After reverse: ";

    for (int x : arr)
    {
        cout << x << " ";
    }

    cout << endl;


    // =====================================
    // 4. next_permutation()
    // =====================================

    vector<int> nums = {1, 2, 3};

    next_permutation(nums.begin(), nums.end());

    cout << "Next permutation: ";

    for (int x : nums)
    {
        cout << x << " ";
    }

    cout << endl;


    // =====================================
    // 5. max() and min()
    // =====================================

    int a = 10;
    int b = 20;

    cout << "Maximum: " << max(a, b) << endl;
    cout << "Minimum: " << min(a, b) << endl;


    // =====================================
    // 6. max_element()
    // =====================================

    vector<int> arr2 = {10, 50, 20, 80, 30};

    auto maxIt = max_element(arr2.begin(), arr2.end());

    cout << "Maximum element: " << *maxIt << endl;


    // =====================================
    // 7. min_element()
    // =====================================

    auto minIt = min_element(arr2.begin(), arr2.end());

    cout << "Minimum element: " << *minIt << endl;


    // =====================================
    // 8. swap()
    // =====================================

    int x = 10;
    int y = 20;

    swap(x, y);

    cout << "After swap: x = "
         << x << ", y = " << y << endl;


    // =====================================
    // 9. binary_search()
    // =====================================

    vector<int> sortedArr = {10, 20, 30, 40, 50};

    bool found = binary_search(sortedArr.begin(),sortedArr.end(),30);

    if (found)
        cout << "30 found" << endl;
    else
        cout << "30 not found" << endl;


    // =====================================
    // 10. count()
    // =====================================

    vector<int> arr3 = {1, 2, 2, 3, 2, 4};

    cout << "Count of 2: "
         << count(arr3.begin(), arr3.end(), 2)
         << endl;


    // =====================================
    // 11. Count set bits
    // =====================================

    int num = 13;

    cout << "Number of set bits in "
         << num << ": "
         << __builtin_popcount(num)
         << endl;


    // For long long:
    long long num2 = 13;

    cout << "Set bits in long long: "
         << __builtin_popcountll(num2)
         << endl;


    return 0;
}
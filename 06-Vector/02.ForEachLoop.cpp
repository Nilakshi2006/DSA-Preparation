#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> num = {1, 2, 3, 4};
    // val is the value stored at each index
    for (int val : num)
    {
        cout << val<<" ";
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // syntax
    //  vector<int>vec;   //default size=0

    // Storing values
    //     vector<int>vec={1,2,3};
    //     cout<<vec[1];

    // Intialising all index with val 0
    vector<int> vec(3, 0); // size-3 val at each index-0
    cout << vec[2];

    return 0;
}
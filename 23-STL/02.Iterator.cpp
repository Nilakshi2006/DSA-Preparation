#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    // begin() points to the first element
    cout << "First Element: " << *(arr.begin()) << endl;

    // end() points one PAST the last element.
    // Never dereference it. Use it only as a stopping point.

    // Forward traversal
    vector<int>::iterator it;
    for (it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Backward traversal
    vector<int>::reverse_iterator rit;
    for (rit = arr.rbegin(); rit != arr.rend(); rit++)
    {
        cout << *rit << " ";
    }
    cout << endl;

    return 0;
}
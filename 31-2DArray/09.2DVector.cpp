
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 1. Initialization of a 2D vector (3 rows, 3 columns)
    vector<vector<int>> vec = {
        {1, 2, 3},
        {4, 5, 6, 10}, //Dynamic size -rows and cols need not to be same
        {7, 8, 9}
    };

    // 2. Defining a 2D vector of size 2x3 with all values as 0
    vector<vector<int>> vec2(2, vector<int>(3, 0));

    // 3. Accessing a specific element (row 1, column 2)
    cout << "Specific element: " << vec[1][2] << endl;

    // 4. Updating a specific element
    vec[1][2] = 10;

    // 5. Printing all elements using nested loops
    cout << "2D Vector elements:" << endl;

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    // 6. Printing the second vector
    cout << "Second vector:" << endl;

    for (int i = 0; i < vec2.size(); i++) {
        for (int j = 0; j < vec2[i].size(); j++) {
            cout << vec2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();

        int r = 0;
        int c = n - 1;

        while (r < m && c >= 0) {
            if (target == mat[r][c]) {
                return true;
            }
            else if (target < mat[r][c]) {
                c--;
            }
            else {
                r++;
            }
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> mat = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int target;
    cout << "Enter target: ";
    cin >> target;

    if (obj.searchMatrix(mat, target)) {
        cout << "Target found" << endl;
    }
    else {
        cout << "Target not found" << endl;
    }

    return 0;
}

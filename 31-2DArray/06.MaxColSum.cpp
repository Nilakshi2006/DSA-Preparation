
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int maxColSum(int mat[][2], int rows, int cols) {
    int maxSum = INT_MIN;

    for (int j = 0; j < cols; j++) {
        int colSum = 0;

        for (int i = 0; i < rows; i++) {
            colSum += mat[i][j];
        }

        maxSum = max(maxSum, colSum);
    }

    return maxSum;
}

int main() {
    int matrix[2][2] = {{1, 2}, {3, 4}};

    int rows = 2;
    int cols = 2;

    cout << maxColSum(matrix, rows, cols);

    return 0;
}

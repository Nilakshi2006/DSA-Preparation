
#include <iostream>
using namespace std;

int diagonalSum(int mat[][3], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Primary diagonal
            if (i == j) {
                sum += mat[i][j];
            }
            // Secondary diagonal
            else if (i + j == n - 1) {
                sum += mat[i][j];
            }
        }
    }

    return sum;
}

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Diagonal Sum: " << diagonalSum(matrix, 3);

    return 0;
}

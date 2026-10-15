
#include <iostream>
using namespace std;

int diagonalSum(int mat[][3], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += mat[i][i];              // Primary diagonal
        sum += mat[i][n - 1 - i];      // Secondary diagonal
    }

    // Avoid counting the center element twice for odd n
    if (n % 2 != 0) {
        sum -= mat[n / 2][n / 2];
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

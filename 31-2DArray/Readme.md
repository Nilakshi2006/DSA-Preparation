# 🚀 DSA Journey — Chapter 31: 2D Arrays and 2D Vectors (C++)

Chapter 31 of my Data Structures & Algorithms journey. 💻

Topic: working with **2D arrays (matrices)** and **2D vectors** in C++: initializing, traversing, taking input, searching, row and column sums, and the diagonal sum in two ways.

---

## 📂 Programs Covered

| #  | File Name                    | Concept                                      |
| -- | ---------------------------- | -------------------------------------------- |
| 01 | `01.IntializingMatrix.cpp`   | Declare, initialize, access and update       |
| 02 | `02.LoopsOn2DArray.cpp`      | Print a matrix with nested loops             |
| 03 | `03.TakingInput.cpp`         | Take matrix input and print it               |
| 04 | `04.LinearSearch.cpp`        | Search a key in a matrix, return `{row, col}` |
| 05 | `05.MaxRowSum.cpp`           | Maximum row sum                              |
| 06 | `06.MaxColSum.cpp`           | Maximum column sum                           |
| 07 | `07.BasicDiagonoalSum.cpp`   | Diagonal sum with nested loops, `O(n²)`      |
| 08 | `08.OptimalDiagonalSum.cpp`  | Diagonal sum in a single loop, `O(n)`        |
| 09 | `09.2DVector.cpp`            | 2D vectors, including different row sizes    |

## 📁 Folder Structure

```text
31-2DArray/

│── output/
│── 01.IntializingMatrix.cpp
│── 02.LoopsOn2DArray.cpp
│── 03.TakingInput.cpp
│── 04.LinearSearch.cpp
│── 05.MaxRowSum.cpp
│── 06.MaxColSum.cpp
│── 07.BasicDiagonoalSum.cpp
│── 08.OptimalDiagonalSum.cpp
│── 09.2DVector.cpp

└── Readme.md
```

---

## 💻 Concepts Used

2D Arrays, Nested Loops, Row and Column Traversal, Row-Major Order, `pair`, `INT_MIN`, 2D Vectors, Time and Space Complexity.

---

## 🧱 2D Array Basics

A 2D array is an array of arrays. `matrix[i][j]` is the element in row `i` and column `j`.

```cpp
int matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

matrix[2][2] = 4;          // update
cout << matrix[2][2];      // access
```

| Operation        | Code                                          |
| ---------------- | --------------------------------------------- |
| Declare          | `int matrix[4][3];`                           |
| Initialize       | `int m[2][2] = {{1, 2}, {3, 4}};`             |
| Access / Update  | `matrix[i][j]`                                |
| Rows / Columns   | stored in `rows` and `cols`                   |

Traverse with a nested loop. The outer loop picks the row, the inner loop picks the column:

```cpp
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}
```

Taking input uses the same loops with `cin >> matrix[i][j];`.

When passing a 2D array to a function, the **column size must be given**: `int mat[][2]`. The compiler needs it to find where each row starts.

---

## 🔎 Linear Search in a Matrix

Check every element. When the key is found, return its position as a `pair`. If it is never found, return `{-1, -1}`.

```cpp
pair<int, int> linearSearch(int mat[][2], int rows, int cols, int key) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == key) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
```

### 🔍 Dry Run (`{{1, 2}, {3, 4}}`, `key = 3`)

```text
i = 0, j = 0 → 1 == 3? no
i = 0, j = 1 → 2 == 3? no
i = 1, j = 0 → 3 == 3? yes → return {1, 0}

Position = 1,0
```

---

## ➕ Max Row Sum and Max Column Sum

**Row sum:** the outer loop is the row, the inner loop adds across the columns. Reset `rowSum` to `0` for every row, and update `maxSum` after the inner loop.

**Column sum:** swap the loops. The outer loop is the column, the inner loop adds down the rows.

```cpp
int maxRowSum(int mat[][2], int rows, int cols) {
    int maxSum = INT_MIN;

    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += mat[i][j];
        }
        maxSum = max(maxSum, rowSum);
    }
    return maxSum;
}
```

`maxSum` starts at `INT_MIN`, not `0`, so the answer is still right when every sum is negative.

### 🔍 Dry Run (`{{1, 2}, {3, 4}}`)

```text
Row sums:    row 0 = 1 + 2 = 3   | row 1 = 3 + 4 = 7   → max = 7
Column sums: col 0 = 1 + 3 = 4   | col 1 = 2 + 4 = 6   → max = 6
```

---

## ⚡ Diagonal Sum

The primary diagonal is where `i == j`. The secondary diagonal is where `i + j == n - 1`. In an odd-sized matrix, both diagonals share the center element, so it must be counted only once.

### Approach 1: Nested Loops, `O(n²)`

Visit every cell. Use `else if` for the secondary diagonal so the center is not added twice.

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (i == j) {
            sum += mat[i][j];
        } else if (i + j == n - 1) {
            sum += mat[i][j];
        }
    }
}
```

### Approach 2: Single Loop, `O(n)`

Each row has exactly one primary and one secondary diagonal element, so there is no need to visit the other cells. Add both, then subtract the center once if `n` is odd.

```cpp
for (int i = 0; i < n; i++) {
    sum += mat[i][i];              // primary
    sum += mat[i][n - 1 - i];      // secondary
}

if (n % 2 != 0) {
    sum -= mat[n / 2][n / 2];      // center counted twice
}
```

### 🔍 Dry Run (`{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}`, `n = 3`)

```text
i = 0 → mat[0][0] + mat[0][2] = 1 + 3 = 4   → sum = 4
i = 1 → mat[1][1] + mat[1][1] = 5 + 5 = 10  → sum = 14
i = 2 → mat[2][2] + mat[2][0] = 9 + 7 = 16  → sum = 30

n is odd → subtract center mat[1][1] = 5   → sum = 25

Diagonal Sum = 25
```

---

## 🧵 2D Vector

A 2D vector is a vector of vectors. It grows dynamically, and **each row can have a different size**.

```cpp
// Initialization with values
vector<vector<int>> vec = {
    {1, 2, 3},
    {4, 5, 6, 10},     // rows need not be the same size
    {7, 8, 9}
};

// 2 rows, 3 columns, all values 0
vector<vector<int>> vec2(2, vector<int>(3, 0));

vec[1][2] = 10;        // update
```

Loop with the size of each row, because rows can differ:

```cpp
for (int i = 0; i < vec.size(); i++) {
    for (int j = 0; j < vec[i].size(); j++) {
        cout << vec[i][j] << " ";
    }
    cout << endl;
}
```

| Feature        | 2D Array              | 2D Vector                    |
| -------------- | --------------------- | ---------------------------- |
| Size           | Fixed at compile time | Can change at runtime        |
| Row sizes      | Same for every row    | Can differ per row           |
| Function param | Needs column size     | `vector<vector<int>>&`       |
| Row length     | Stored separately     | `vec[i].size()`              |

---

## 🧪 Output

**01.IntializingMatrix.cpp**

```text
4
```

**02.LoopsOn2DArray.cpp**

```text
1 2 
3 4 
```

**03.TakingInput.cpp**

```text
1 2 3 4
1 2 
3 4 
```

**04.LinearSearch.cpp**

```text
1,0
```

**05.MaxRowSum.cpp**

```text
7
```

**06.MaxColSum.cpp**

```text
6
```

**07.BasicDiagonoalSum.cpp** and **08.OptimalDiagonalSum.cpp**

```text
Diagonal Sum: 25
```

**09.2DVector.cpp**

```text
Specific element: 6
2D Vector elements:
1 2 3 
4 5 10 10 
7 8 9 
Second vector:
0 0 0 
0 0 0 
```

---

## 📈 Complexity

| Program                | Time          | Space  |
| ---------------------- | ------------- | ------ |
| Traversal / Input      | `O(rows * cols)` | `O(1)` |
| Linear Search          | `O(rows * cols)` | `O(1)` |
| Max Row / Column Sum   | `O(rows * cols)` | `O(1)` |
| Diagonal Sum (nested)  | `O(n²)`       | `O(1)` |
| Diagonal Sum (optimal) | `O(n)`        | `O(1)` |

Every cell is visited once in the traversal programs. The optimal diagonal sum touches only `2n` cells.

---

## ⚠️ Common Mistakes

| Mistake                                       | Correct Approach                                                |
| --------------------------------------------- | --------------------------------------------------------------- |
| Swapping `i` and `j`                          | `i` is the row and `j` is the column, so use `mat[i][j]`        |
| Passing `int mat[][]` to a function           | The column size is required: `int mat[][3]`                     |
| Starting `maxSum` at `0`                      | Start at `INT_MIN`, so negative sums are handled                |
| Not resetting `rowSum` for each row           | Declare it inside the outer loop                                |
| Counting the center twice in the diagonal sum | Use `else if`, or subtract the center once when `n` is odd      |
| Using `rows` as the limit for every loop      | Rows use `rows`, columns use `cols`                             |
| Accessing `mat[rows][...]` or `mat[...][cols]` | Valid indexes are `0` to `rows - 1` and `0` to `cols - 1`      |
| Using `vec[0].size()` for every row           | In a 2D vector, use `vec[i].size()` for each row                |

---

## 🎓 Interview Tip

Be ready to explain:

* How a 2D array is stored in memory (row-major order)
* Why the column size is required when passing a 2D array to a function
* Why the diagonal sum can be done in `O(n)` instead of `O(n²)`
* Why the center element is subtracted only when `n` is odd
* The difference between a 2D array and a 2D vector
* Why `maxSum` starts at `INT_MIN`

A simple explanation:

> "A 2D array is an array of rows, and I traverse it with a nested loop where `i` is the row and `j` is the column. For the diagonal sum I add `mat[i][i]` and `mat[i][n - 1 - i]` in one loop and subtract the center once if `n` is odd, so it takes `O(n)` time."

---

## 🌱 What This Chapter Builds

Matrix Traversal, Nested Loop Control, Row and Column Thinking, Index Pattern Recognition, Optimizing Brute Force, Working with 2D Vectors.

> **"Rows go across, columns go down, and `i` always comes first."** 💻
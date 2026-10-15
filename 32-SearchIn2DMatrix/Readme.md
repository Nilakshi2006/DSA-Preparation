# 🚀 DSA Journey — Chapter 32: Search in a 2D Matrix (C++)

Chapter 32 of my Data Structures & Algorithms journey. 💻

Topic: searching a sorted 2D matrix. Two variations, two different sort rules, two different approaches.

---

## 📂 Programs Covered

| #  | File Name            | Concept                                                      |
| -- | -------------------- | ------------------------------------------------------------ |
| 01 | `01.Variation-I.cpp` | Fully sorted matrix: binary search on rows, then in the row  |
| 02 | `02.Variation2.cpp`  | Row-wise and column-wise sorted: staircase search, `O(m + n)` |

## 📁 Folder Structure

```text
32-SearchIn2DMatrix/

│── 01.Variation-I.cpp
│── 02.Variation2.cpp

└── Readme.md
```

---

## 💻 Concepts Used

2D Vectors, Binary Search, Row Elimination, Staircase Search, Time and Space Complexity.

---

## 🧱 The Two Variations

| Property                    | Variation I                         | Variation 2                      |
| --------------------------- | ----------------------------------- | -------------------------------- |
| Each row                    | Sorted left to right                | Sorted left to right             |
| Each column                 | Not guaranteed on its own           | Sorted top to bottom             |
| First element of a row      | Greater than last element of the previous row | No such rule           |
| Approach                    | Binary search twice                 | Staircase from top-right         |
| Time                        | `O(log m + log n)`                  | `O(m + n)`                       |
| Space                       | `O(1)`                              | `O(1)`                           |

---

## 🔎 Variation I: Binary Search on Rows, then in the Row

Because the first element of every row is larger than the last element of the row above, the rows themselves are in sorted order.

1. Binary search over rows to find the row where `matrix[row][0] <= target <= matrix[row][n - 1]`.
2. Binary search inside that row.

```cpp
while (startRow <= endRow) {
    int midRow = startRow + (endRow - startRow) / 2;

    if (target >= matrix[midRow][0] && target <= matrix[midRow][n - 1]) {
        return searchInRow(matrix, target, midRow);
    }
    else if (target >= matrix[midRow][n - 1]) {
        startRow = midRow + 1;      // target is in a lower row
    }
    else {
        endRow = midRow - 1;        // target is in an upper row
    }
}
return false;
```

If the target lies inside a row's range, it can only be in that row, so the row search decides the answer.

### 🔍 Dry Run (`{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}`, `target = 3`)

```text
startRow = 0, endRow = 2 → midRow = 1
  3 in [10, 20]? no → 3 < 10 → endRow = 0

startRow = 0, endRow = 0 → midRow = 0
  3 in [1, 7]? yes → searchInRow(row 0)

  start = 0, end = 3 → mid = 1 → matrix[0][1] = 3 == 3 → true

Target found
```

---

## ⚡ Variation 2: Staircase Search

Rows and columns are both sorted, but a row does not start after the previous row ends, so binary search on rows does not work. Start at the **top-right** corner.

That element is the largest in its row and the smallest in its column. Every comparison removes a full row or a full column:

* `target == mat[r][c]` → found
* `target < mat[r][c]` → everything below in this column is larger, so move left (`c--`)
* `target > mat[r][c]` → everything to the left in this row is smaller, so move down (`r++`)

```cpp
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
```

The top-left corner does not work. It is the smallest in both its row and column, so both directions increase and there is no way to choose.

### 🔍 Dry Run (`{{1, 4, 7, 11}, {2, 5, 8, 12}, {3, 6, 9, 16}, {10, 13, 14, 17}}`, `target = 5`)

```text
r = 0, c = 3 → 11 → 5 < 11 → c = 2
r = 0, c = 2 → 7  → 5 < 7  → c = 1
r = 0, c = 1 → 4  → 5 > 4  → r = 1
r = 1, c = 1 → 5  → 5 == 5 → true

Target found
```

---

## 🧪 Output

**01.Variation-I.cpp**

```text
Enter target: 3
Target found
```

```text
Enter target: 13
Target not found
```

**02.Variation2.cpp**

```text
Enter target: 5
Target found
```

```text
Enter target: 15
Target not found
```

---

## 📈 Complexity

| Program      | Time              | Space  |
| ------------ | ----------------- | ------ |
| Variation I  | `O(log m + log n)` | `O(1)` |
| Variation 2  | `O(m + n)`        | `O(1)` |

Variation I halves the rows, then halves the columns. Variation 2 moves one step per iteration, and each step discards a row or a column, so it runs at most `m + n` times.

---

## ⚠️ Common Mistakes

| Mistake                                              | Correct Approach                                                       |
| ---------------------------------------------------- | ---------------------------------------------------------------------- |
| Using row binary search on Variation 2               | Rows do not follow each other in sorted order there, so use the staircase |
| Starting the staircase at the top-left               | Start at top-right (or bottom-left) so each move has a clear direction |
| Using `(start + end) / 2`                            | Use `start + (end - start) / 2` to avoid overflow                      |
| Searching a row when the target is outside its range | Check `matrix[row][0]` and `matrix[row][n - 1]` first                  |
| Forgetting the equal case when moving rows           | Handle `==` in the range check first, so the row branch is safe        |
| Using `r <= m` or `c <= n - 1` as loop limits        | Valid indexes are `0` to `m - 1` and `0` to `n - 1`                    |
| Not handling an empty matrix                         | Check `matrix.empty()` before `matrix[0]` if the input is not guaranteed non-empty |

---

## 🎓 Interview Tip

Be ready to explain:

* Why Variation I allows binary search on rows
* Why Variation 2 does not
* Why the staircase starts at the top-right corner
* Why each staircase step eliminates a full row or column
* The time complexity of both approaches
* An alternative for Variation I: treat the matrix as a flattened sorted array of `m * n` elements and binary search once, with `row = mid / n` and `col = mid % n`

A simple explanation:

> "If the whole matrix is sorted, I binary search the rows and then the row, so it takes `O(log m + log n)`. If only rows and columns are sorted, I start at the top-right. If the target is smaller I move left, if it is larger I move down, and each step removes a row or a column, so it takes `O(m + n)`."

---

## 🌱 What This Chapter Builds

Binary Search on a 2D Structure, Using Sorted Properties, Row and Column Elimination, Choosing the Right Starting Point, Matching the Approach to the Constraints.

> **"Sorted rows give you binary search. Sorted rows and columns give you a staircase."** 💻
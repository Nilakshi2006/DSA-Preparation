# 🚀 DSA Journey — Chapter 21: Merge Two Sorted Arrays (C++)

Chapter 21 of my Data Structures & Algorithms journey. 💻

Problem: merge two sorted arrays into one sorted array. I solved it in two ways: using a **separate result array** and **in-place merging from the back**.

---

## 📂 Programs Covered

| #  | File Name                   | Concept                                      |
| -- | --------------------------- | -------------------------------------------- |
| 01 | `01.BasicApproach.cpp`      | Two pointers, merge into a new array         |
| 02 | `02.OptimizedApproach.cpp`  | Three pointers, merge into `nums1` from back |

## 📁 Folder Structure

```text
21-MergeTwoSortedArr/

│── output/
│── 01.BasicApproach.cpp
│── 02.OptimizedApproach.cpp

└── README.md
```

---

## 💻 Concepts Used

Arrays, Vectors, Loops, Two/Three Pointers, Merging, In-place Algorithms, Time and Space Complexity.

---

## 🔨 1. Basic Approach (Extra Array)

Compare the front elements of both arrays and copy the smaller one into a third array.

```cpp
int i = 0, j = 0, k = 0;
// i for arr1, j for arr2, k for arr3

while (i < n && j < m) {
    if (arr1[i] < arr2[j]) arr3[k++] = arr1[i++];
    else                   arr3[k++] = arr2[j++];
}

while (i < n) arr3[k++] = arr1[i++];   // leftover of arr1
while (j < m) arr3[k++] = arr2[j++];   // leftover of arr2
```

Simple and fast, but needs `O(n + m)` extra space.

### 🔍 Dry Run (`arr1 = {1, 3, 5, 7}`, `arr2 = {2, 4, 6, 8}`)

```text
1 vs 2 → take 1   arr3 = 1
3 vs 2 → take 2   arr3 = 1 2
3 vs 4 → take 3   arr3 = 1 2 3
5 vs 4 → take 4   arr3 = 1 2 3 4
5 vs 6 → take 5   arr3 = 1 2 3 4 5
7 vs 6 → take 6   arr3 = 1 2 3 4 5 6
7 vs 8 → take 7   arr3 = 1 2 3 4 5 6 7
i == n → copy leftover 8
```

---

## ⚡ 2. Optimized Approach (In-place, From the Back)

`nums1` already has empty space at the end (filled with `0`s) to hold `nums2`.

Fill `nums1` from the **back**, so no unread element is overwritten.

```cpp
void mergeArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int idx = m + n - 1;
    int i = m - 1;
    int j = n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) nums1[idx--] = nums1[i--];
        else                     nums1[idx--] = nums2[j--];
    }

    while (j >= 0) nums1[idx--] = nums2[j--];   // leftover of nums2
}
```

No loop is needed for leftover `nums1` elements. They are already in place.

### 🔍 Dry Run (`nums1 = {1, 3, 5, 0, 0, 0}`, `nums2 = {2, 4, 6}`)

```text
5 vs 6 → place 6   1 3 5 0 0 6
5 vs 4 → place 5   1 3 5 0 5 6
3 vs 4 → place 4   1 3 5 4 5 6
3 vs 2 → place 3   1 3 3 4 5 6
1 vs 2 → place 2   1 2 3 4 5 6
j < 0 → stop (1 is already in place)
```

---

## 🧪 Output

```text
Merged array: 1 2 3 4 5 6 7 8     (Basic)
Merged array: 1 2 3 4 5 6         (Optimized)
```

---

## 📈 Complexity

| Approach  | Time         | Space        |
| --------- | ------------ | ------------ |
| Basic     | `O(n + m)`   | `O(n + m)`   |
| Optimized | `O(m + n)`   | `O(1)`       |

---

## 🆚 Quick Comparison

| Feature         | Basic                 | Optimized                |
| --------------- | --------------------- | ------------------------ |
| Idea            | Merge front to back   | Merge back to front      |
| Extra array     | Yes                   | No                       |
| Direction       | Left → Right          | Right → Left             |
| Leftover loops  | Both arrays           | Only `nums2`             |
| Best for        | Easy to understand    | Interviews (in-place)    |

---

## ⚠️ Common Mistakes

| Mistake                                      | Correct Approach                                      |
| -------------------------------------------- | ----------------------------------------------------- |
| Merging `nums1` from the front               | Go from the back, or unread values get overwritten    |
| Starting `idx` at `m + n`                    | Start at `m + n - 1`                                  |
| Forgetting the leftover loop for `nums2`     | Copy remaining `nums2` elements                       |
| Adding a leftover loop for `nums1`           | Not needed, they are already in place                 |
| Forgetting `k++` / `idx--`                   | Move the write pointer every time                     |
| `int arr3[n + m]` with non-const sizes       | This is a compiler extension; use `vector` for portability |

---

## 🎓 Interview Tip

Be ready to explain:

* Why the basic approach needs extra space
* Why merging from the back avoids overwriting
* Why leftover `nums1` elements need no copying
* Time and space complexity of both

A simple explanation:

> "I use three pointers, one at the end of each array's data and one at the last slot of `nums1`. I place the larger value at the last slot and move left. This merges in `O(m + n)` time and `O(1)` space."

---

## 🌱 What This Chapter Builds

Two-Pointer Technique, Merging Logic, In-place Thinking, Back-to-Front Traversal, Space Optimization.

> **"If the front is occupied, fill from the back."** 💻
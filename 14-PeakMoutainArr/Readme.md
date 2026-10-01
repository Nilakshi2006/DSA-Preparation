# 🚀 DSA Journey – Chapter 14: Peak Index in a Mountain Array (C++)

Welcome to **Chapter 14** of my **Data Structures & Algorithms (DSA)** journey! 💻⚡

In this chapter, I solved **Peak Index in a Mountain Array** using Binary Search.

A mountain array strictly increases up to a peak and then strictly decreases. Instead of scanning the whole array in `O(n)`, Binary Search finds the peak in `O(log n)` by checking which side of the mountain the middle element is on.

This is a **LeetCode Easy** problem and a good starting point for Binary Search on patterns.

---

## 📚 Program Covered

| # | File Name | Concept |
|---|-----------|---------|
| 01 | `01.BinarySearchApproach.cpp` | Find the peak index of a mountain array using Binary Search. |

---

# 🎯 Concepts I Learned

### Mountain Array

- Values strictly increase up to a peak, then strictly decrease.
- The peak is never the first or last element.
- Every element before the peak is on the **increasing slope**.
- Every element after the peak is on the **decreasing slope**.

### Binary Search on Slope

- Compare `arr[mid]` with its neighbours to find the slope.
- On the increasing slope → the peak is on the right.
- On the decreasing slope → the peak is on the left (or at `mid`).
- Discard half of the array every iteration.

---

# 💻 Language Used

- **C++**

### Concepts Used

- Arrays
- Vectors
- Binary Search
- Iteration (`while`)
- Conditional Statements
- Time and Space Complexity

---

# 📂 Folder Structure

```text
14-PeakMoutainArr/
│── output/
│── 01.BinarySearchApproach.cpp
└── README.md
```

---

# 📍 Program — Peak Index in a Mountain Array

## Objective

Return the index of the peak element in a mountain array in `O(log n)` time.

---

## 🧠 Algorithm

1. Initialize `st = 1` and `end = n - 1`.
2. Find the middle index.
3. If `arr[mid - 1] < arr[mid] > arr[mid + 1]`, `mid` is the peak → return it.
4. Else if `arr[mid - 1] < arr[mid]`, we are on the increasing slope → `st = mid + 1`.
5. Else we are on the decreasing slope → `end = mid - 1`.
6. Repeat until the peak is found.

---

## 💻 Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int n = arr.size();
    int st = 1, end = n - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        else if (arr[mid - 1] < arr[mid]) {
            st = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {0, 2, 5, 3, 1};

    cout << "Peak index: " << peakIndexInMountainArray(arr);

    return 0;
}
```

---

## 🔍 Dry Run

### Example Array

```text
arr = [0, 2, 5, 3, 1]
```

| Step | Start | End | Mid | Value at Mid | Action |
|------|-------|-----|-----|--------------|--------|
| 1 | 1 | 4 | 2 | 5 | `2 < 5 > 3` → Peak found ✅ Return `2` |

### Longer Example

```text
arr = [0, 1, 2, 3, 4, 2, 1]
```

| Step | Start | End | Mid | Value at Mid | Action |
|------|-------|-----|-----|--------------|--------|
| 1 | 1 | 6 | 3 | 3 | `2 < 3 < 4` → Increasing slope → `st = 4` |
| 2 | 4 | 6 | 5 | 2 | `4 > 2` → Decreasing slope → `end = 4` |
| 3 | 4 | 4 | 4 | 4 | `3 < 4 > 2` → Peak found ✅ Return `4` |

---

## 💡 Visual Understanding

```text
Index:   0   1   2   3   4
Value: [ 0,  2,  5,  3,  1 ]

              ▲ Peak (index 2)
            /   \
          /       \
        /           \
 Increasing        Decreasing
```

---

## 🧪 Example 1

### Input

```cpp
vector<int> arr = {0, 2, 5, 3, 1};
```

### Output

```text
Peak index: 2
```

---

## 🧪 Example 2

### Input

```cpp
vector<int> arr = {0, 10, 5, 2};
```

### Output

```text
Peak index: 1
```

---

## 🧪 Example 3

### Input

```cpp
vector<int> arr = {3, 4, 5, 1};
```

### Output

```text
Peak index: 2
```

---

# ⚙️ How the Logic Works

### Case 1 — Peak Found

```cpp
if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
```

`mid` is greater than both neighbours → return `mid`.

### Case 2 — Increasing Slope

```cpp
else if (arr[mid - 1] < arr[mid])
```

The peak is to the **right** → `st = mid + 1`.

### Case 3 — Decreasing Slope

```cpp
else
```

The peak is to the **left** → `end = mid - 1`.

---

# 📈 Complexity Analysis

| Operation | Complexity |
|-----------|------------|
| Best Case | `O(1)` |
| Average Case | `O(log n)` |
| Worst Case | `O(log n)` |
| Space Complexity | `O(1)` |

**Why `O(log n)`?**

The search space is halved in every iteration.

---

# 🌟 Important Notes

### ✅ Why `st = 1`?

The peak can never be at index `0` in a valid mountain array. Starting at `1` makes `arr[mid - 1]` always safe to access.

### ✅ Why `arr[mid + 1]` is safe

In a valid mountain array the peak is never the last element, so `st` never moves past it and `mid` never lands on `n - 1`. Using `end = n - 2` makes this explicit and safer.

### ✅ Safe Mid Formula

```cpp
int mid = st + (end - st) / 2;
```

Avoids integer overflow compared to `(st + end) / 2`.

---

# ⚠️ Common Mistakes

| Mistake | Correct Approach |
|---------|------------------|
| Starting at `st = 0`. | Start at `1` so `arr[mid - 1]` stays in bounds. |
| Doing a linear scan. | Use Binary Search for `O(log n)`. |
| Using `(st + end) / 2`. | Use the safe mid formula. |
| Updating `end = mid` or `st = mid` without moving past `mid`. | Use `mid + 1` / `mid - 1` to avoid infinite loops. |

---

# 🎓 Interview Tip

Be ready to explain:

- Why Binary Search works on a mountain array (slope tells which side the peak is on).
- Why comparing `mid` with a neighbour is enough.
- Why the time complexity is `O(log n)`.

---

# 🌱 What This Chapter Builds

- Binary Search on a pattern, not just a sorted array.
- Using neighbour comparison to decide the search direction.
- Safe index handling at array boundaries.

It leads into problems like:

- Find Peak Element
- Find in Mountain Array
- Binary Search on Answers

---

> **"Binary Search isn't only for sorted arrays — wherever there's a pattern that tells you which half to discard, it works."** 🌸✨
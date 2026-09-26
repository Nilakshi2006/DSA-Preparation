# 🚀 DSA Journey – Chapter 12: Binary Search (C++)

Welcome to **Chapter 12** of my **Data Structures & Algorithms (DSA)** journey! 💻✨

In this chapter, I learned one of the most important searching algorithms — **Binary Search**. It is an efficient searching technique that works on **sorted arrays** by repeatedly dividing the search space into two halves.

This chapter covers **Binary Search using Iteration** and **Binary Search using Recursion**.

---

## 📚 Programs Covered

| # | File Name | Concept |
|---|-----------|---------|
| 01 | `01.BinarySearchWithIterations.cpp` | Binary Search using an iterative (`while` loop) approach. |
| 02 | `02.BinarySearchWithRecursion.cpp` | Binary Search using recursion and base case. |

---

# 🎯 Concepts I Learned

This chapter helped me understand how Binary Search reduces the search space by half in every step, making it much faster than Linear Search for sorted data.

### Binary Search

- Works only on **sorted arrays**.
- Finds the middle element of the array.
- Compares the target with the middle element.
- Searches either the **left half** or the **right half**.
- Repeats the process until the target is found or the search space becomes empty.

### Iterative Binary Search

- Uses a `while` loop.
- Updates `start` and `end` pointers until `start <= end`.

### Recursive Binary Search

- Uses recursive function calls instead of a loop.
- Stops recursion using a **base case** (`start > end`).

---

# 💻 Language Used

- **C++**

### Concepts Used

- Arrays
- Vectors
- Functions
- Iteration (`while`)
- Recursion
- Divide and Conquer
- Time and Space Complexity

---

# 📂 Folder Structure

```text
12-BinarySearch/

│── output/
│── 01.BinarySearchWithIterations.cpp
│── 02.BinarySearchWithRecursion.cpp
└── README.md
```

---

# 📍 Program 1 — Binary Search Using Iteration

### Objective

Search an element in a sorted array using the iterative Binary Search algorithm.

### Algorithm

1. Initialize `start = 0` and `end = size - 1`.
2. Find the middle index.
3. Compare the target with `arr[mid]`.
4. If target is greater, move to the right half.
5. If target is smaller, move to the left half.
6. If found, return the index.
7. If `start > end`, return `-1`.

### Dry Run

**Array**

```text
[-1, 0, 3, 4, 5, 9, 12]
Target = 12
```

| Step | Start | End | Mid | Value at Mid | Action |
|------|------|-----|-----|--------------|--------|
| 1 | 0 | 6 | 3 | 4 | Search Right Half |
| 2 | 4 | 6 | 5 | 9 | Search Right Half |
| 3 | 6 | 6 | 6 | 12 | Target Found |

### Example

**Input**

```cpp
vector<int> arr = {-1, 0, 3, 4, 5, 9, 12};
int target = 12;
```

**Output**

```text
6
```

### Time Complexity

- **Time:** `O(log n)`
- **Space:** `O(1)`

---

# 📍 Program 2 — Binary Search Using Recursion

### Objective

Search an element in a sorted array using recursive Binary Search.

### Algorithm

1. Check the base case.
2. If `start > end`, return `-1`.
3. Calculate the middle index.
4. Compare target with `arr[mid]`.
5. Search the left half recursively if target is smaller.
6. Search the right half recursively if target is greater.
7. Return the index if found.

### Dry Run

**Array**

```text
[-1, 0, 3, 4, 5, 9, 12]
Target = 12
```

```text
binarySearch(0,6)

mid = 3 → value = 4
Target > 4

binarySearch(4,6)

mid = 5 → value = 9
Target > 9

binarySearch(6,6)

mid = 6 → value = 12
Target Found ✅
```

### Base Case

```cpp
if (start > end)
{
    return -1;
}
```

The recursion stops when the search space becomes empty.

### Example

**Input**

```cpp
vector<int> arr = {-1, 0, 3, 4, 5, 9, 12};
int target = 12;
```

**Output**

```text
6
```

### Time Complexity

- **Time:** `O(log n)`
- **Space:** `O(log n)` *(Recursive call stack)*

---

# 📊 Iterative vs Recursive Binary Search

| Feature | Iterative | Recursive |
|---------|-----------|-----------|
| Approach | Uses `while` loop | Uses recursive function calls |
| Base Condition | `while(start <= end)` | `if(start > end)` |
| Space Complexity | `O(1)` | `O(log n)` |
| Time Complexity | `O(log n)` | `O(log n)` |
| Extra Memory | No | Yes (Call Stack) |

---

# 🌟 Important Notes

### Binary Search Works Only on Sorted Arrays

```text
Sorted Array ✅

[1, 3, 5, 7, 9, 11]
```

```text
Unsorted Array ❌

[5, 1, 9, 3, 7, 2]
```

### Safe Mid Formula

Instead of:

```cpp
int mid = (start + end) / 2;
```

Use:

```cpp
int mid = start + (end - start) / 2;
```

This avoids integer overflow for very large arrays.

---

# 📈 Complexity Analysis

| Operation | Complexity |
|-----------|------------|
| Best Case | `O(1)` |
| Average Case | `O(log n)` |
| Worst Case | `O(log n)` |
| Iterative Space | `O(1)` |
| Recursive Space | `O(log n)` |

---

# 🌱 What This Chapter Builds

By completing this chapter, I strengthened my understanding of:

- Binary Search on sorted arrays.
- Divide and Conquer technique.
- Iterative Binary Search using `while` loop.
- Recursive Binary Search using base case.
- Safe middle index calculation.
- Time and Space Complexity comparison.
- Difference between Iterative and Recursive approaches.

This chapter forms the **foundation for advanced Binary Search problems** such as **First & Last Occurrence, Search in Rotated Sorted Array, Peak Element, Square Root using Binary Search, and Binary Search on Answers**.

---

> *“Binary Search teaches us that instead of checking every element, we can eliminate half of the search space at every step.”* 🌸
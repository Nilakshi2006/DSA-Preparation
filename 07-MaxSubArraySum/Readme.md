# 🚀 DSA Journey – Chapter 7: Maximum Subarray Sum (C++)

Welcome to **Chapter 7** of my **Data Structures & Algorithms (DSA)** journey! 📊💻

In this chapter, I learned how to solve the **Maximum Subarray Sum** problem using **two approaches** — the **Brute Force Approach** and **Kadane's Algorithm**.

The goal is to find the **maximum sum of any contiguous subarray** in a given array. This is one of the most frequently asked DSA problems in **LeetCode, coding interviews, and competitive programming**.

---

## 📚 Programs Covered

| # | File Name | Concept |
|---|-----------|---------|
| 01 | `01.BruteForce.cpp` | Find Maximum Subarray Sum using the Brute Force Approach (`O(n²)`). |
| 02 | `02.KadaneAlgo.cpp` | Find Maximum Subarray Sum using Kadane's Algorithm (`O(n)`). |

---

# 🎯 Concepts I Learned

This chapter helped me understand **subarrays, running sum, optimization techniques, and Kadane's Algorithm**.

---

## 🌱 1. Maximum Subarray Sum

The **Maximum Subarray Sum** problem asks us to find the **largest possible sum of a contiguous subarray** within a given array.

### Example

```cpp
Array = {3, -4, 5, 4, -1, 7, -8}
```

**Output**

```text
Maximum Subarray Sum = 15
```

**Maximum Subarray:** `{5, 4, -1, 7}`

### 📌 Key Learning

- A **subarray** contains **contiguous elements** of an array.
- The objective is to find the subarray whose sum is the maximum.

---

## 🔍 2. Brute Force Approach

The brute force approach checks **every possible subarray** and calculates its sum.

### Algorithm

1. Start from each index of the array.
2. Extend the subarray one element at a time.
3. Keep adding elements to `currSum`.
4. Update `maxSum` whenever a larger sum is found.

### Logic Used

```cpp
currSum += arr[end];
maxSum = max(currSum, maxSum);
```

### Example Output

```text
Maximum Subarray Sum is: 15
```

### 📌 Key Learning

- Uses **two nested loops**.
- Calculates the sum of every possible subarray.
- Simple and easy to understand, but slower for large arrays.

**Time Complexity:** `O(n²)`

**Space Complexity:** `O(1)`

---

## ⚡ 3. Kadane's Algorithm

Kadane's Algorithm is the **optimized solution** for the Maximum Subarray Sum problem.

It traverses the array only once while maintaining:

- `currSum` → Current subarray sum.
- `maxSum` → Maximum sum found so far.

### Algorithm

1. Initialize `currSum = 0` and `maxSum = INT_MIN`.
2. Add each element to `currSum`.
3. Update `maxSum`.
4. If `currSum` becomes negative, reset it to `0`.

### Logic Used

```cpp
currSum += arr[i];
maxSum = max(currSum, maxSum);

if (currSum < 0) {
    currSum = 0;
}
```

### Example Output

```text
Maximum Subarray is: 15
```

### 📌 Why `INT_MIN` is Used?

`INT_MIN` initializes `maxSum` with the **smallest possible integer value**, ensuring the algorithm works correctly even when **all elements in the array are negative**.

**Example**

```cpp
arr = {-5, -2, -8}
```

If `maxSum = 0`, the answer becomes **0 (incorrect)**.

If `maxSum = INT_MIN`, the answer becomes **-2 (correct)**.

---

## ⚖️ Brute Force vs Kadane's Algorithm

| Feature | Brute Force | Kadane's Algorithm |
|---------|-------------|--------------------|
| Approach | Checks every possible subarray. | Traverses the array once. |
| Time Complexity | `O(n²)` | `O(n)` |
| Space Complexity | `O(1)` | `O(1)` |
| Efficiency | Slower for large arrays. | Faster and optimized. |
| Best Use | Understanding subarrays. | Interviews and competitive programming. |

---

# 💻 Language Used

- **C++**

### Concepts Used

- Arrays
- Subarrays
- Nested Loops
- Running Sum (`currSum`)
- `INT_MIN`
- `max()` Function
- Kadane's Algorithm
- Time & Space Complexity

---

## 📂 Folder Structure

```text
07-MaxSubArraySum/
│── output/
│── 01.BruteForce.cpp
│── 02.KadaneAlgo.cpp
└── README.md
```

---

## 📊 Complexity Summary

| Approach | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| Brute Force | `O(n²)` | `O(1)` |
| Kadane's Algorithm | `O(n)` | `O(1)` |

---

## 🌱 What This Chapter Builds

By completing these programs, I strengthened my understanding of:

- Finding the **Maximum Subarray Sum** using the Brute Force approach.
- Optimizing the solution using **Kadane's Algorithm**.
- Using `currSum` and `maxSum` efficiently.
- Understanding the importance of `INT_MIN`.
- Comparing a naive solution with an optimized solution.

This chapter builds the foundation for upcoming DSA topics like **Sliding Window, Prefix Sum, Dynamic Programming, and Array Optimization Problems**.

---

# 📖 Key Takeaways

- A **subarray** contains contiguous elements of an array.
- The **Maximum Subarray Sum** problem finds the largest sum among all contiguous subarrays.
- **Brute Force** generates all possible subarrays and has `O(n²)` complexity.
- **Kadane's Algorithm** solves the same problem in **linear time `O(n)`**.
- `currSum` stores the running sum of the current subarray.
- If `currSum` becomes negative, it is reset to `0`.
- `INT_MIN` ensures correct results even when all array elements are negative.

---

> **"Kadane's Algorithm is one of the most important array optimization algorithms because it reduces the Maximum Subarray Sum problem from `O(n²)` to `O(n)` using a single traversal."** 🚀
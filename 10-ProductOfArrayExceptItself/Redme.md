# 🚀 DSA Journey – Chapter 10: Product of Array Except Self (C++)

Welcome to **Chapter 10** of my **Data Structures & Algorithms (DSA)** journey! 💻✨

In this chapter, I learned how to solve the **Product of Array Except Self** problem using two different approaches in C++. This is one of the most common interview questions because it teaches the concept of **Brute Force optimization**, **Prefix Product**, and **Suffix Product** without using division.

The goal of this problem is to create a new array where each element contains the product of all other elements except itself.

---

## 📚 Programs Covered

| # | File Name | Concept |
|---|-----------|---------|
| 01 | `01.BruteForceApproach.cpp` | Find product of array except self using nested loops. |
| 02 | `02.OptimisedApproach.cpp` | Solve the problem using Prefix and Suffix Product in **O(n)** time. |

---

## 🎯 Concepts I Learned

This chapter helped me understand how to optimize array problems from **O(n²)** to **O(n)**.

### Brute Force Approach

- Traverse every element of the array.
- For each index, multiply all elements except the current one.
- Store the result in a new array.
- Uses **two nested loops**.

### Optimized Prefix-Suffix Approach

- Compute the product of all elements on the **left** of each index.
- Compute the product of all elements on the **right** of each index.
- Multiply prefix and suffix products to get the final answer.
- Solves the problem **without using division**.

### Prefix Product

- Start with `prefix = 1`.
- Store prefix product before updating it.
- Prefix represents the product of elements to the left.

### Suffix Product

- Start from the last element.
- Maintain `suffix = 1`.
- Multiply suffix with the current answer.
- Update suffix while moving left.

---

## 💻 Language Used

- **C++**

### Concepts Used

- Vectors (`vector<int>`)
- Nested `for` loops
- Prefix Product
- Suffix Product
- Array Traversal
- Time Complexity Optimization

---

## 📂 Folder Structure

```text
10-ProductOfArrayExceptItself/
│── output/
│── 01.BruteForceApproach.cpp
│── 02.OptimisedApproach.cpp
└── README.md
```

---

## 🔄 Approach 1: Brute Force

### Algorithm

1. Create an answer vector initialized with `1`.
2. Traverse each index `i`.
3. Traverse the entire array again.
4. Multiply every element except `nums[i]`.
5. Store the product in `ans[i]`.

### Dry Run

**Input**

```text
nums = [1, 2, 3, 4]
```

| Index | Product of Remaining Elements |
|-------|-------------------------------|
| 0 | 2 × 3 × 4 = 24 |
| 1 | 1 × 3 × 4 = 12 |
| 2 | 1 × 2 × 4 = 8 |
| 3 | 1 × 2 × 3 = 6 |

**Output**

```text
[24, 12, 8, 6]
```

### Time Complexity

- **Time:** `O(n²)`
- **Space:** `O(n)`

---

## ⚡ Approach 2: Optimized (Prefix + Suffix)

### Algorithm

#### Step 1 — Prefix Product

- Initialize `prefix = 1`.
- Store prefix in the answer array.
- Update prefix by multiplying the current element.

#### Step 2 — Suffix Product

- Initialize `suffix = 1`.
- Traverse from right to left.
- Multiply answer with suffix.
- Update suffix.

### Dry Run

**Input**

```text
nums = [1, 2, 3, 4]
```

### Prefix Pass

| Index | Prefix | Answer |
|-------|--------|--------|
| 0 | 1 | 1 |
| 1 | 1 | 1 |
| 2 | 2 | 2 |
| 3 | 6 | 6 |

Answer after prefix pass:

```text
[1, 1, 2, 6]
```

### Suffix Pass

| Index | Suffix | Updated Answer |
|-------|--------|----------------|
| 3 | 1 | 6 |
| 2 | 4 | 8 |
| 1 | 12 | 12 |
| 0 | 24 | 24 |

Final Output:

```text
[24, 12, 8, 6]
```

### Time Complexity

- **Time:** `O(n)`
- **Space:** `O(n)` (Answer array only)

---

## 📊 Complexity Comparison

| Approach | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| Brute Force | `O(n²)` | `O(n)` |
| Optimized Prefix-Suffix | `O(n)` | `O(n)` |

---

## 🌱 What This Chapter Builds

By completing this problem, I strengthened my understanding of:

- Brute Force vs Optimized Approach.
- Prefix Product and Suffix Product concepts.
- Array traversal from left and right.
- Space-efficient array manipulation.
- Interview-style optimization without using division.

This chapter is an important step toward mastering **array optimization techniques** that frequently appear in coding interviews and competitive programming.

---

> *“Optimization is not about writing shorter code—it’s about finding a smarter way to solve the same problem.”* 🌸
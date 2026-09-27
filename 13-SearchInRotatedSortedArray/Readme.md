# 🚀 DSA Journey – Chapter 13: Search in Rotated Sorted Array (C++)

Welcome to **Chapter 13** of my **Data Structures & Algorithms (DSA)** journey! 💻⚡

In this chapter, I learned how to solve one of the most popular **Binary Search interview problems** — **Search in Rotated Sorted Array**.

Unlike a normal Binary Search, this problem works on a **rotated sorted array**. The key idea is to identify which half of the array is sorted and then decide where the target element can exist.

This is an important **LeetCode Medium** problem that is frequently asked in coding interviews.

---

## 📚 Program Covered

| # | File Name | Concept |
|---|-----------|---------|
| 01 | `01.BinarySearchApproach.cpp` | Search an element in a rotated sorted array using a modified Binary Search. |

---

# 🎯 Concepts I Learned

This chapter helped me understand how Binary Search can be modified to work even when a sorted array has been rotated.

### Rotated Sorted Array

- A sorted array is rotated at an unknown pivot.
- One half of the array always remains sorted.
- Identify the sorted half first.
- Check whether the target lies inside the sorted half.
- Eliminate the other half and continue searching.

### Modified Binary Search

- Uses Binary Search logic.
- Detects whether the **left half** or **right half** is sorted.
- Reduces the search space by half in every iteration.

---

# 💻 Language Used

- **C++**

### Concepts Used

- Arrays
- Vectors
- Binary Search
- Iteration (`while`)
- Conditional Statements
- Divide and Conquer
- Time and Space Complexity

---

# 📂 Folder Structure

```text
13-SearchInRotatedSortedArray/
│── output/
│── 01.BinarySearchApproach.cpp
└── README.md
```

---

# 📍 Program — Search in Rotated Sorted Array

## Objective

Find the index of a target element in a **rotated sorted array** using an optimized Binary Search approach.

---

## 🧠 Algorithm

1. Initialize `start = 0` and `end = size - 1`.
2. Find the middle index.
3. If `nums[mid]` is the target, return its index.
4. Check which half is sorted.
5. If the left half is sorted:
   - Check whether the target lies between `start` and `mid`.
   - Search the appropriate half.
6. Otherwise, the right half is sorted:
   - Check whether the target lies between `mid` and `end`.
   - Search the appropriate half.
7. Repeat until the target is found.
8. If the search space becomes empty, return `-1`.

---

## 🔍 Dry Run

### Example Array

```text
nums = [4, 5, 6, 7, 0, 1, 2]
Target = 0
```

<table>
  <table-section header>
    <table-row header>
      <table-cell header>Step</table-cell>
      <table-cell header>Start</table-cell>
      <table-cell header>End</table-cell>
      <table-cell header>Mid</table-cell>
      <table-cell header>Value at Mid</table-cell>
      <table-cell header>Sorted Half</table-cell>
      <table-cell header>Action</table-cell>
    </table-row>
  </table-section>
  <table-row>
    <table-cell>1</table-cell>
    <table-cell>0</table-cell>
    <table-cell>6</table-cell>
    <table-cell>3</table-cell>
    <table-cell>7</table-cell>
    <table-cell>Left Half Sorted</table-cell>
    <table-cell>Target not in left half → Search Right Half</table-cell>
  </table-row>
  <table-row>
    <table-cell>2</table-cell>
    <table-cell>4</table-cell>
    <table-cell>6</table-cell>
    <table-cell>5</table-cell>
    <table-cell>1</table-cell>
    <table-cell>Left Half Sorted</table-cell>
    <table-cell>Target lies in left half → Search Left Half</table-cell>
  </table-row>
  <table-row>
    <table-cell>3</table-cell>
    <table-cell>4</table-cell>
    <table-cell>4</table-cell>
    <table-cell>4</table-cell>
    <table-cell>0</table-cell>
    <table-cell>Target Found ✅</table-cell>
    <table-cell>Return index `4`</table-cell>
  </table-row>
</table>

---

## 💡 Visual Understanding

### Original Sorted Array

```text
[0, 1, 2, 4, 5, 6, 7]
```

### Rotated at Pivot

```text
        Pivot
          ↓
[4, 5, 6, 7, 0, 1, 2]
```

The array is still made up of **two sorted parts**.

```text
[4, 5, 6, 7]   [0, 1, 2]
    Sorted         Sorted
```

Binary Search identifies which sorted part to search next.

---

## 🧪 Example 1

### Input

```cpp
vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
int target = 0;
```

### Output

```text
4
```

---

## 🧪 Example 2

### Input

```cpp
vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
int target = 3;
```

### Output

```text
-1
```

Target is not present in the array.

---

## 🧪 Example 3

### Input

```cpp
vector<int> nums = {1};
int target = 0;
```

### Output

```text
-1
```

---

# ⚙️ How the Logic Works

### Case 1 — Left Half is Sorted

```cpp
if (nums[start] <= nums[mid])
```

Example:

```text
[4, 5, 6, 7, 0, 1, 2]
 ↑        ↑
start    mid
```

Check if the target lies between `start` and `mid`.

```cpp
if (nums[start] <= target && target <= nums[mid])
```

- Yes → Move Left.
- No → Move Right.

---

### Case 2 — Right Half is Sorted

```cpp
else
```

Example:

```text
[4, 5, 6, 7, 0, 1, 2]
            ↑      ↑
           mid    end
```

Check if the target lies between `mid` and `end`.

```cpp
if (nums[mid] <= target && target <= nums[end])
```

- Yes → Move Right.
- No → Move Left.

---

# 📊 Dry Run (Target = 6)

```text
nums = [4, 5, 6, 7, 0, 1, 2]
Target = 6
```

<table>
  <table-section header>
    <table-row header>
      <table-cell header>Step</table-cell>
      <table-cell header>Start</table-cell>
      <table-cell header>End</table-cell>
      <table-cell header>Mid</table-cell>
      <table-cell header>Value</table-cell>
      <table-cell header>Action</table-cell>
    </table-row>
  </table-section>
  <table-row>
    <table-cell>1</table-cell>
    <table-cell>0</table-cell>
    <table-cell>6</table-cell>
    <table-cell>3</table-cell>
    <table-cell>7</table-cell>
    <table-cell>Left Half Sorted → Target is in Left Half.</table-cell>
  </table-row>
  <table-row>
    <table-cell>2</table-cell>
    <table-cell>0</table-cell>
    <table-cell>2</table-cell>
    <table-cell>1</table-cell>
    <table-cell>5</table-cell>
    <table-cell>Target is greater → Move Right.</table-cell>
  </table-row>
  <table-row>
    <table-cell>3</table-cell>
    <table-cell>2</table-cell>
    <table-cell>2</table-cell>
    <table-cell>2</table-cell>
    <table-cell>6</table-cell>
    <table-cell>Target Found ✅</table-cell>
  </table-row>
</table>

---

# 📈 Complexity Analysis

<table>
  <table-section header>
    <table-row header>
      <table-cell header>Operation</table-cell>
      <table-cell header>Complexity</table-cell>
    </table-row>
  </table-section>
  <table-row>
    <table-cell>Best Case</table-cell>
    <table-cell>`O(1)`</table-cell>
  </table-row>
  <table-row>
    <table-cell>Average Case</table-cell>
    <table-cell>`O(log n)`</table-cell>
  </table-row>
  <table-row>
    <table-cell>Worst Case</table-cell>
    <table-cell>`O(log n)`</table-cell>
  </table-row>
  <table-row>
    <table-cell>Space Complexity</table-cell>
    <table-cell>`O(1)`</table-cell>
  </table-row>
</table>

**Why `O(log n)`?**

Because Binary Search removes **half of the remaining search space** during each iteration.

---

# 🌟 Important Notes

### ✅ One Half is Always Sorted

Even after rotation, one side of the array remains sorted.

```text
[4, 5, 6, 7, 0, 1, 2]

Left Half  → Sorted
Right Half → Sorted (depending on pointers)
```

---

### ✅ Safe Mid Formula

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

### ✅ Binary Search Still Works After Rotation

The trick is **not finding the pivot first**.

Instead:

- Identify the sorted half.
- Decide whether the target belongs there.
- Continue Binary Search.

This makes the solution efficient and elegant.

---

# ⚠️ Common Mistakes

<table>
  <table-section header>
    <table-row header>
      <table-cell header>Mistake</table-cell>
      <table-cell header>Correct Approach</table-cell>
    </table-row>
  </table-section>
  <table-row>
    <table-cell>Using Binary Search on an unsorted array.</table-cell>
    <table-cell>Works only because one half is always sorted.</table-cell>
  </table-row>
  <table-row>
    <table-cell>Using `nums[start] &lt; nums[mid]`.</table-cell>
    <table-cell>Use `nums[start] &lt;= nums[mid]` to handle edge cases.</table-cell>
  </table-row>
  <table-row>
    <table-cell>Using `(start + end) / 2`.</table-cell>
    <table-cell>Use the safe mid formula.</table-cell>
  </table-row>
  <table-row>
    <table-cell>Searching both halves.</table-cell>
    <table-cell>Search only the half where the target can exist.</table-cell>
  </table-row>
</table>

---

# 🎓 Interview Tip

This problem is one of the most frequently asked **Binary Search interview questions**.

Interviewers usually expect you to explain:

- Why Binary Search works after rotation.
- How to identify the sorted half.
- Why the time complexity remains `O(log n)`.
- Why the safe mid formula is preferred.

Understanding this problem also helps solve many advanced Binary Search questions.

---

# 🌱 What This Chapter Builds

By completing this chapter, I strengthened my understanding of:

- Modified Binary Search.
- Rotated Sorted Arrays.
- Identifying the sorted half.
- Eliminating half of the search space.
- Divide and Conquer strategy.
- Safe middle index calculation.
- Time and Space Complexity analysis.

This chapter builds the foundation for advanced Binary Search problems like:

- First and Last Occurrence
- Find Minimum in Rotated Sorted Array
- Search in Rotated Sorted Array II (Duplicates)
- Peak Element
- Square Root using Binary Search
- Binary Search on Answers

---

> **"Binary Search becomes even more powerful when we learn to recognize patterns — in a rotated sorted array, one half always stays sorted, and that's the key to finding the answer efficiently."** 🌸✨
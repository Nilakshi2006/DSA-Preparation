# 🚀 DSA Journey – Chapter 15: Single Element in a Sorted Array (C++)

Welcome to **Chapter 15** of my **Data Structures & Algorithms (DSA)** journey! 💻⚡

In this chapter, I solved **Single Element in a Sorted Array** in two ways: a **Frequency Map** approach in `O(n)` and an optimized **Binary Search** approach in `O(log n)`.

Every element in the sorted array appears exactly twice, except one. The task is to find that single element.

This is a **LeetCode Medium** problem and a great example of how a brute-force solution can be upgraded using Binary Search.

---

## 📚 Programs Covered

| # | File Name | Concept |
|---|-----------|---------|
| 01 | `01.UsingFreq.cpp` | Count frequencies with `unordered_map` and return the element with count 1. |
| 02 | `02.BinarySearchApproach.cpp` | Use Binary Search and index parity to find the single element. |

---

# 🎯 Concepts I Learned

### Frequency Map Approach

- Count how many times each element appears.
- The element with frequency `1` is the answer.
- Simple, but ignores the sorted property and uses extra space.

### Binary Search Using Pair Parity

- Before the single element, every pair starts at an **even** index.
- After the single element, pairs start at an **odd** index.
- Checking the index parity of `mid` tells us which side the single element is on.
- Discard half of the array every iteration.

---

# 💻 Language Used

- **C++**

### Concepts Used

- Arrays
- Vectors
- Hash Map (`unordered_map`)
- Binary Search
- Iteration (`for`, `while`)
- Conditional Statements
- Time and Space Complexity

---

# 📂 Folder Structure

```text
15-SingleElementInSortedArr/
│── output/
│── 01.UsingFreq.cpp
│── 02.BinarySearchApproach.cpp
└── README.md
```

---

# 📍 Program 1 — Using Frequency Map

## Objective

Find the element that appears only once by counting the frequency of every element.

---

## 🧠 Algorithm

1. Create an `unordered_map<int, int>` called `freq`.
2. Traverse the array and increase the count of each element.
3. Traverse the array again.
4. Return the first element whose frequency is `1`.
5. If none is found, return `-1`.

---

## 💻 Code

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (freq[nums[i]] == 1) {
            return nums[i];
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4};

    cout << "Single element: " << singleNonDuplicate(nums);

    return 0;
}
```

---

## 🔍 Dry Run

```text
nums = [1, 1, 2, 3, 3, 4, 4]
```

**Frequency map:**

| Element | Frequency |
|---------|-----------|
| 1 | 2 |
| 2 | 1 |
| 3 | 2 |
| 4 | 2 |

| Step | Index | Value | Frequency | Action |
|------|-------|-------|-----------|--------|
| 1 | 0 | 1 | 2 | Skip |
| 2 | 1 | 1 | 2 | Skip |
| 3 | 2 | 2 | 1 | Single element found ✅ Return `2` |

---

# 📍 Program 2 — Binary Search Approach

## Objective

Find the single element in `O(log n)` time and `O(1)` space.

---

## 🧠 Algorithm

1. Initialize `st = 0` and `end = n - 1`.
2. Find the middle index.
3. If `nums[mid]` differs from both neighbours, it is the single element → return it.
4. If `mid` is **even**:
   - `nums[mid] == nums[mid + 1]` → pair is intact, single is on the right → `st = mid + 2`.
   - Otherwise → single is on the left → `end = mid - 1`.
5. If `mid` is **odd**:
   - `nums[mid] == nums[mid - 1]` → pair is intact, single is on the right → `st = mid + 1`.
   - Otherwise → single is on the left → `end = mid - 1`.
6. Repeat until the element is found.

---

## 💻 Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int st = 0, end = n - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        // Single element at start
        if (mid == 0 && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }

        // Single element at end
        if (mid == n - 1 && nums[mid] != nums[mid - 1]) {
            return nums[mid];
        }

        // Single element in the middle
        if (nums[mid] != nums[mid - 1] &&
            nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }

        // Check whether we are on the first or second element of a pair
        if (mid % 2 == 0) {
            if (nums[mid] == nums[mid + 1]) {
                // Pair is correct, go right
                st = mid + 2;
            } else {
                // Single element is on the left
                end = mid - 1;
            }
        }
        else {
            if (nums[mid] == nums[mid - 1]) {
                // Pair is correct, go right
                st = mid + 1;
            } else {
                // Single element is on the left
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5, 5};

    cout << singleNonDuplicate(nums);

    return 0;
}
```

---

## 🔍 Dry Run

### Example Array

```text
nums = [1, 1, 2, 2, 3, 4, 4, 5, 5]
```

| Step | Start | End | Mid | Value at Mid | Action |
|------|-------|-----|-----|--------------|--------|
| 1 | 0 | 8 | 4 | 3 | `2 ≠ 3 ≠ 4` → Single element found ✅ Return `3` |

### Longer Example

```text
nums = [1, 1, 2, 3, 3, 4, 4]
```

| Step | Start | End | Mid | Value at Mid | Action |
|------|-------|-----|-----|--------------|--------|
| 1 | 0 | 6 | 3 | 3 | Odd `mid`, `nums[3] ≠ nums[2]` → Single is on the left → `end = 2` |
| 2 | 0 | 2 | 1 | 1 | Odd `mid`, `nums[1] == nums[0]` → Pair intact → `st = 2` |
| 3 | 2 | 2 | 2 | 2 | `1 ≠ 2 ≠ 3` → Single element found ✅ Return `2` |

---

## 💡 Visual Understanding

### Before the Single Element

```text
Index:  0  1  2  3
Value: [1, 1, 2, 2, ...]
        └──┘  └──┘
      Even index starts each pair
```

### After the Single Element

```text
Index:  4  5  6  7  8
Value: [3, 4, 4, 5, 5]
        ↑  └──┘  └──┘
     Single   Odd index starts each pair
```

The single element **flips the parity** of every pair after it. That is how Binary Search knows which side to discard.

---

## 🧪 Example 1

### Input

```cpp
vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5, 5};
```

### Output

```text
3
```

---

## 🧪 Example 2

### Input

```cpp
vector<int> nums = {1, 1, 2, 3, 3, 4, 4};
```

### Output

```text
2
```

---

## 🧪 Example 3

### Input

```cpp
vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
```

### Output

```text
10
```

---

# ⚙️ How the Logic Works

### Case 1 — Single Element Found

```cpp
if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
```

`mid` differs from both neighbours → return `nums[mid]`.

### Case 2 — `mid` is Even

```cpp
if (nums[mid] == nums[mid + 1])
```

- Yes → pair is intact, move **right** (`st = mid + 2`).
- No → single element is on the **left** (`end = mid - 1`).

### Case 3 — `mid` is Odd

```cpp
if (nums[mid] == nums[mid - 1])
```

- Yes → pair is intact, move **right** (`st = mid + 1`).
- No → single element is on the **left** (`end = mid - 1`).

---

# 📈 Complexity Analysis

| Approach | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| Frequency Map | `O(n)` | `O(n)` |
| Binary Search | `O(log n)` | `O(1)` |

**Why `O(log n)` for Binary Search?**

The search space is halved in every iteration.

---

# 🌟 Important Notes

### ✅ The Array Length is Always Odd

Every element appears twice except one, so `n` is always odd. The single element always sits at an **even index**.

### ✅ Sorted Property is Not Used in the Frequency Approach

The frequency map works on any array. Binary Search is faster because it uses the sorted order and pair positions.

### ✅ Safe Mid Formula

```cpp
int mid = st + (end - st) / 2;
```

Avoids integer overflow compared to `(st + end) / 2`.

### ⚠️ Edge Case: Boundaries

The code reads `nums[mid - 1]` and `nums[mid + 1]`, so a one-element array (`n = 1`) reads `nums[1]`, which is out of bounds. Handle `n == 1` separately or check boundaries before comparing neighbours.

---

# ⚠️ Common Mistakes

| Mistake | Correct Approach |
|---------|------------------|
| Accessing `nums[mid - 1]` or `nums[mid + 1]` without boundary checks. | Handle the first and last index separately. |
| Using `st = mid + 1` for an even `mid`. | Skip the full pair with `st = mid + 2`. |
| Ignoring index parity. | Parity tells which side the single element is on. |
| Using `(st + end) / 2`. | Use the safe mid formula. |

---

# 🎓 Interview Tip

Be ready to explain:

- Why the frequency approach is `O(n)` and how Binary Search improves it.
- Why index parity tells which half contains the single element.
- Why the single element is always at an even index.
- Why the time complexity is `O(log n)`.

---

# 🌱 What This Chapter Builds

- Upgrading a brute-force solution to Binary Search.
- Using index parity as a search condition.
- Handling boundary cases safely.

It leads into problems like:

- Find Peak Element
- Search in Rotated Sorted Array II
- Binary Search on Answers

---

> **"The best Binary Search solutions start by asking: what pattern tells me which half to throw away?"** 🌸✨
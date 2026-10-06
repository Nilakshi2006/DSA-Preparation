# 🚀 DSA Journey — Chapter 22: Next Permutation (C++)

Chapter 22 of my Data Structures & Algorithms journey. 💻

Problem: rearrange an array into the **next lexicographically greater permutation**. If none exists, rearrange it into the lowest order (sorted ascending). I solved it with the **optimal single-pass approach**.

---

## 📂 Programs Covered

| #  | File Name                | Concept                                   |
| -- | ------------------------ | ----------------------------------------- |
| 01 | `01.OptimalApproach.cpp` | Find pivot, swap, reverse the suffix      |

## 📁 Folder Structure

```text
22-NextPermutation/

│── output/
│── 01.OptimalApproach.cpp

└── README.md
```

---

## 💻 Concepts Used

Arrays, Vectors, Loops, Swapping, Reversing, Two Pointers, In-place Algorithms, Time and Space Complexity.

---

## ⚡ Optimal Approach

The suffix after the pivot is in descending order, so it is the largest arrangement of those elements. To get the next permutation, we bump the pivot to the next larger value and make the suffix as small as possible.

1. **Find the pivot:** the rightmost index `i` where `nums[i] < nums[i + 1]`.
2. **Swap:** from the right, find the first element greater than `nums[pivot]` and swap it with the pivot.
3. **Reverse:** reverse everything after the pivot to make it ascending.

If no pivot exists, the array is the last permutation, so sort it ascending.

```cpp
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int pivot = -1;

    // Step 1: Find pivot
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            pivot = i;
            break;
        }
    }

    // No pivot: last permutation
    if (pivot == -1) {
        sort(nums.begin(), nums.end());
        return;
    }

    // Step 2: Swap with next greater element from the right
    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] > nums[pivot]) {
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    // Step 3: Reverse the suffix
    int i = pivot + 1, j = n - 1;
    while (i < j) {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}
```

### 🔍 Dry Run (`{1, 2, 5, 4, 3}`)

```text
Step 1: scan from right
        4 < 3? no | 5 < 4? no | 2 < 5? yes → pivot = index 1 (value 2)

Step 2: first value > 2 from right is 3
        swap 3 and 2       → 1 3 5 4 2

Step 3: reverse after pivot (5 4 2 → 2 4 5)
                           → 1 3 2 4 5
```

### 🔍 Dry Run, No Pivot (`{3, 2, 1}`)

```text
3 < 2? no | 2 < 1? no → pivot = -1
Last permutation → sort → 1 2 3
```

---

## 🧪 Output

For:

```text
nums = {1, 2, 5, 4, 3}
```

```text
Next Permutation: 1 3 2 4 5
```

---

## 📈 Complexity

| Approach | Time                    | Space  |
| -------- | ----------------------- | ------ |
| Optimal  | `O(n)`                  | `O(1)` |

The no-pivot case uses `sort()`, which is `O(n log n)`. Using `reverse()` instead keeps it at `O(n)`, since the array is already in descending order there.

---

## ⚠️ Common Mistakes

| Mistake                                      | Correct Approach                                  |
| -------------------------------------------- | ------------------------------------------------- |
| Starting the pivot scan at `n - 1`           | Start at `n - 2`, since we compare with `i + 1`   |
| Using `<=` when finding the pivot            | Use `<`, or duplicates break the logic            |
| Searching for the swap element from the left | Search from the right, where the suffix is descending |
| Skipping the reverse step                    | Reverse the suffix to make it the smallest        |
| Forgetting the no-pivot case                 | Sort (or reverse) to return the lowest order      |
| Reversing from `pivot` instead of `pivot + 1` | Reverse only the elements after the pivot         |

---

## 🎓 Interview Tip

Be ready to explain:

* Why the suffix after the pivot is always descending
* Why we search for the swap element from the right
* Why reversing the suffix gives the smallest arrangement
* What happens when the array is already the last permutation
* Why generating all permutations is not an acceptable solution

A simple explanation:

> "I find the rightmost position where the order increases, swap it with the next larger element from the right, then reverse the suffix. This gives the next permutation in `O(n)` time and `O(1)` space."

---

## 🌱 What This Chapter Builds

Pattern Recognition, In-place Rearrangement, Lexicographic Ordering, Pivot Technique, Edge Case Handling.

> **"Change as little as possible, as far right as possible."** 💻
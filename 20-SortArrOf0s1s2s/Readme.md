# 🚀 DSA Journey — Chapter 20: Sort an Array of 0s, 1s and 2s (C++)

Chapter 20 of my Data Structures & Algorithms journey. 💻

Problem: sort an array that contains only **0s, 1s and 2s**. I solved it in three ways: Built-in Sort, Counting, and the **Dutch National Flag (DNF) algorithm**.

---

## 📂 Programs Covered

| #  | File Name                | Concept                                   |
| -- | ------------------------ | ----------------------------------------- |
| 01 | `01.BruteForceApproach.cpp` | Use the built-in `sort()`              |
| 02 | `02.OptimizedApproach.cpp`  | Count 0s, 1s, 2s and overwrite the array |
| 03 | `03.UsingDNFAlgo.cpp`       | Three pointers, single pass            |

## 📁 Folder Structure

```text
20-SortArrOf0s1s2s/

│── output/
│── 01.BruteForceApproach.cpp
│── 02.OptimizedApproach.cpp
│── 03.UsingDNFAlgo.cpp

└── README.md
```

---

## 💻 Concepts Used

Arrays, Vectors, Loops, Counting, Two/Three Pointers, Swapping, In-place Algorithms, Time and Space Complexity.

---

## 🔨 1. Brute Force (Built-in Sort)

Sort the whole array with `sort()`.

```cpp
sort(arr.begin(), arr.end());
```

Works, but it ignores the fact that only three values exist.

---

## ⚡ 2. Counting Approach

Count how many 0s, 1s and 2s there are, then write them back in order.

```cpp
void sort012(vector<int>& arr) {
    int count0 = 0, count1 = 0, count2 = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) count0++;
        else if (arr[i] == 1) count1++;
        else count2++;
    }

    int idx = 0;
    for (int i = 0; i < count0; i++) arr[idx++] = 0;
    for (int i = 0; i < count1; i++) arr[idx++] = 1;
    for (int i = 0; i < count2; i++) arr[idx++] = 2;
}
```

Two passes: one to count, one to overwrite.

### 🔍 Dry Run (`{2, 0, 2, 1, 1, 0}`)

```text
Count:  count0 = 2, count1 = 2, count2 = 2
Write:  0 0 _ _ _ _
        0 0 1 1 _ _
        0 0 1 1 2 2
```

---

## 🇳🇱 3. Dutch National Flag (DNF) Algorithm

Use three pointers to split the array into four regions in **one pass**.

```text
[ 0 ... low-1 ]  → all 0s
[ low ... mid-1 ] → all 1s
[ mid ... high ]  → unsorted
[ high+1 ... n-1 ] → all 2s
```

```cpp
void sort012(vector<int>& arr) {
    int n = arr.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;                      // do NOT move mid here
        }
    }
}
```

| `arr[mid]` | Action                         | Pointers        |
| ---------- | ------------------------------ | --------------- |
| `0`        | swap with `low`                | `low++, mid++`  |
| `1`        | already in place               | `mid++`         |
| `2`        | swap with `high`               | `high--`        |

### 🔍 Dry Run (`{2, 0, 2, 1, 1, 0}`)

```text
low=0 mid=0 high=5 → arr[mid]=2 → swap with high → 0 0 2 1 1 2   high=4
low=0 mid=0 high=4 → arr[mid]=0 → swap with low  → 0 0 2 1 1 2   low=1 mid=1
low=1 mid=1 high=4 → arr[mid]=0 → swap with low  → 0 0 2 1 1 2   low=2 mid=2
low=2 mid=2 high=4 → arr[mid]=2 → swap with high → 0 0 1 1 2 2   high=3
low=2 mid=2 high=3 → arr[mid]=1 → mid++                           mid=3
low=2 mid=3 high=3 → arr[mid]=1 → mid++                           mid=4
mid > high → stop
```

---

## 🧪 Output

For:

```text
arr = {2, 0, 2, 1, 1, 0}
```

All three approaches print:

```text
0 0 1 1 2 2
```

---

## 📈 Complexity

| Approach     | Time         | Space  | Passes |
| ------------ | ------------ | ------ | ------ |
| Brute Force  | `O(n log n)` | `O(1)` | —      |
| Counting     | `O(n)`       | `O(1)` | 2      |
| DNF          | `O(n)`       | `O(1)` | 1      |

---

## 🆚 Quick Comparison

| Feature         | Brute Force        | Counting              | DNF                    |
| --------------- | ------------------ | --------------------- | ---------------------- |
| Idea            | Sort everything    | Count, then rewrite   | Partition with 3 pointers |
| Uses the 0/1/2 limit | No            | Yes                   | Yes                    |
| Modifies in place | Yes              | Yes (overwrites)      | Yes (swaps)            |
| Best for        | Quick solution     | Simple and fast       | Interviews (single pass) |

---

## ⚠️ Common Mistakes

| Mistake                                    | Correct Approach                              |
| ------------------------------------------ | --------------------------------------------- |
| Doing `mid++` after swapping with `high`   | Don't. The swapped-in value is not checked yet |
| Loop condition `mid < high`                | Use `mid <= high`                             |
| Not doing `mid++` after swapping with `low` | Do it. The value from `low` is always `1`     |
| Starting `high` at `n`                     | Start at `n - 1`                              |
| Forgetting `idx++` while rewriting         | Use `arr[idx++] = value`                      |

---

## 🎓 Interview Tip

Be ready to explain:

* Why `sort()` is not the expected answer
* How counting works and why it needs two passes
* The four regions in DNF and what each pointer does
* Why `mid` does not move after swapping with `high`
* Time and space complexity of all three

A simple explanation:

> "Counting sort counts each value and rewrites the array. DNF uses `low`, `mid` and `high` to push 0s to the front and 2s to the back in a single pass. Both are `O(n)` time and `O(1)` space."

---

## 🌱 What This Chapter Builds

Three-Pointer Technique, In-place Partitioning, Counting Logic, Single-pass Thinking, Time Complexity Analysis.

> **"Use the constraints. Only three values means you don't need a full sort."** 💻
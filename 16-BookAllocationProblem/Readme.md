# 🚀 DSA Journey — Chapter 16: Book Allocation Problem (C++)

Chapter 16 of my Data Structures & Algorithms journey. 💻📚

I solved the Book Allocation Problem using **Binary Search on Answer**.

Rules:
- Each student gets at least one book.
- Books are allocated in contiguous order.
- A book cannot be split between students.
- Minimize the maximum pages assigned to any student.

This is Binary Search on Answer: we don't search for an element, we search for the **smallest value that satisfies a condition**.

---

## 📚 Problem Statement

Given:
- `arr[i]`: pages in the `i-th` book
- `n`: total books
- `m`: total students

Return the **minimum possible value of the maximum pages** assigned to any student. If `m > n`, return `-1`.

### 💡 Example

```text
arr = [2, 1, 3, 4], m = 2
```

Allocation A:

```text
Student 1 → [2, 1, 3] = 6
Student 2 → [4]       = 4
Max = 6
```

Allocation B:

```text
Student 1 → [2, 1] = 3
Student 2 → [3, 4] = 7
Max = 7
```

Minimum possible maximum = **6**.

---

## 📂 Program Covered

| # | File Name | Concept |
|---|-----------|---------|
| 01 | `01.BinarySearchApproach.cpp` | Binary Search on Answer for Book Allocation |

## 📁 Folder Structure

```text
16-BookAllocationProblem/
│── output/
│── 01.BinarySearchApproach.cpp
└── README.md
```

## 💻 Concepts Used

Arrays, Vectors, Binary Search, Binary Search on Answer, Greedy Approach, Functions, Loops, Time and Space Complexity.

---

## 🎯 Main Concept — Binary Search on Answer

We search the **answer range**, not the array.

For `arr = [2, 1, 3, 4]`:
- Smallest possible answer: `max(arr) = 4` (someone must take the biggest book)
- Largest possible answer: `sum(arr) = 10` (one student takes everything)

For every candidate `mid`, we ask:

> Can all books be allocated to at most `m` students without anyone exceeding `mid` pages?

`isValid()` answers that.

---

## 🧠 Key Idea

Try `maxAllowedPages = 5`:

```text
Student 1 → [2, 1] = 3
Student 2 → [3]    = 3
Student 3 → [4]    = 4
```

Needs 3 students, but `m = 2`. So **5 is invalid**.

Try `maxAllowedPages = 6`:

```text
Student 1 → [2, 1, 3] = 6
Student 2 → [4]       = 4
```

Needs 2 students. So **6 is valid**.

---

## 🔍 Step 1 — The `isValid()` Function

```cpp
bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages)
```

| Parameter | Meaning |
|-----------|---------|
| `arr` | Pages in each book |
| `n` | Number of books |
| `m` | Number of students |
| `maxAllowedPages` | Max pages one student can receive |

Start with the first student:

```cpp
int stu = 1, pages = 0;
```

## Step 2 — Reject Oversized Books

```cpp
if(arr[i] > maxAllowedPages){
    return false;
}
```

A book can't be split. If one book exceeds the limit, the limit is impossible.

## Step 3 — Add Book to Current Student

```cpp
if(pages + arr[i] <= maxAllowedPages){
    pages += arr[i];
}
```

If it fits, the current student keeps it.

## Step 4 — Move to the Next Student

```cpp
else{
    stu++;
    pages = arr[i];
}
```

If it doesn't fit, a new student starts with this book.

## Step 5 — Check Student Count

```cpp
return stu <= m;
```

If we needed more than `m` students, the limit is invalid.

### Complete `isValid()`

```cpp
bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages){
    int stu = 1, pages = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] > maxAllowedPages){
            return false;
        }

        if(pages + arr[i] <= maxAllowedPages){
            pages += arr[i];
        }
        else{
            stu++;
            pages = arr[i];
        }
    }

    return stu <= m;
}
```

---

## 🔎 Step 6 — Search Range

```cpp
long long sum = 0;
int maxBook = 0;

for(int i = 0; i < n; i++){
    sum += arr[i];
    maxBook = max(maxBook, arr[i]);
}

long long st = maxBook, end = sum;
```

For `arr = [2, 1, 3, 4]`: `st = 4`, `end = 10`.

## 🔍 Step 7 — Binary Search

```cpp
long long mid = st + (end - st) / 2;
```

`st + (end - st) / 2` avoids the overflow that `(st + end) / 2` can cause.

## ✅ Step 8 — `mid` Is Valid

```cpp
ans = mid;
end = mid - 1;
```

Store it, then search left for a smaller valid answer.

## ❌ Step 9 — `mid` Is Invalid

```cpp
st = mid + 1;
```

`mid` is too small, so search right.

---

## 💻 Complete Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages){
    int stu = 1, pages = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] > maxAllowedPages){
            return false;
        }

        if(pages + arr[i] <= maxAllowedPages){
            pages += arr[i];
        }
        else{
            stu++;
            pages = arr[i];
        }
    }

    return stu <= m;
}

int allocateBooks(vector<int>& arr, int n, int m){
    // Not enough books for every student
    if(m > n){
        return -1;
    }

    long long sum = 0;
    int maxBook = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];
        maxBook = max(maxBook, arr[i]);
    }

    int ans = -1;
    long long st = maxBook, end = sum;

    while(st <= end){
        long long mid = st + (end - st) / 2;

        if(isValid(arr, n, m, (int)mid)){
            ans = (int)mid;
            end = mid - 1;   // search left
        }
        else{
            st = mid + 1;    // search right
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {2, 1, 3, 4};

    int n = 4;
    int m = 2;

    cout << allocateBooks(arr, n, m) << endl;

    return 0;
}
```

---

## 🔍 Dry Run

```text
arr = [2, 1, 3, 4], n = 4, m = 2
Range: st = 4, end = 10
```

**Iteration 1:** `mid = 7`

```text
Student 1 → [2, 1, 3] = 6
Student 2 → [4]       = 4
```

2 students → **valid ✅**. `ans = 7`, `end = 6`.

**Iteration 2:** `st = 4, end = 6, mid = 5`

```text
Student 1 → [2, 1] = 3
Student 2 → [3]    = 3
Student 3 → [4]    = 4
```

3 students → **invalid ❌**. `st = 6`.

**Iteration 3:** `st = 6, end = 6, mid = 6`

```text
Student 1 → [2, 1, 3] = 6
Student 2 → [4]       = 4
```

2 students → **valid ✅**. `ans = 6`, `end = 5`.

**Stop:** `st > end`. Final answer: **6**.

### 📊 Dry Run Table

| Step | `st` | `end` | `mid` | Valid? | Action |
|------|------|-------|-------|--------|--------|
| 1 | 4 | 10 | 7 | ✅ | Store 7, search left |
| 2 | 4 | 6 | 5 | ❌ | Search right |
| 3 | 6 | 6 | 6 | ✅ | Store 6, search left |
| 4 | 6 | 5 | — | — | Stop |

---

## 🧠 Why Binary Search Works Here

The answer is **monotonic**. If `6` is valid, then `7, 8, 9, 10` are valid too, because a bigger limit never makes an allocation impossible. If `5` is invalid, then `4, 3, 2, 1` are invalid too.

```text
Invalid Invalid Invalid | Valid Valid Valid Valid
                         ↑
                  Minimum Answer
```

## 📌 Pattern: Binary Search on Answer

Ask: **can I check whether a particular answer is possible?** If results look like `False False False True True True` (or the reverse), binary search applies.

```text
1. Identify the answer range.
2. Pick the middle value.
3. Check if it's possible.
4. Possible   → try smaller.
5. Impossible → try larger.
6. Stop when the minimum valid answer is found.
```

---

## 🧪 Examples

**Example 1:** `arr = {2, 1, 3, 4}, m = 2` → `6`

**Example 2:** `arr = {10, 20, 30, 40}, m = 2`

```text
[10, 20, 30] = 60 | [40] = 40       → max 60
[10, 20] = 30     | [30, 40] = 70   → max 70
```

Output: `60`

**Example 3:** `arr = {12, 34, 67, 90}, m = 2`

```text
[12, 34, 67] = 113 | [90] = 90      → max 113
[12, 34] = 46      | [67, 90] = 157 → max 157
```

Output: `113`

**Example 4 (edge case):** `arr = {10, 20}, m = 3` → `-1` (more students than books)

---

## 📈 Complexity

Let `n` = number of books and `S` = total pages.

| Operation | Time | Space |
|-----------|------|-------|
| One `isValid()` check | `O(n)` | `O(1)` |
| Binary search iterations | `O(log S)` | `O(1)` |
| **Overall** | **`O(n log S)`** | **`O(1)`** |

Each of the `O(log S)` iterations runs an `O(n)` check.

---

## 🔥 Template

```cpp
int st = minimumPossible;
int end = maximumPossible;

while(st <= end){
    int mid = st + (end - st) / 2;

    if(isValid(mid)){
        ans = mid;
        end = mid - 1;   // look for smaller
    }
    else{
        st = mid + 1;    // need larger
    }
}
```

---

## ⚠️ Important Notes

1. **Contiguous allocation.** For `[2, 1, 3, 4]`, giving Student 1 `[2, 3]` and Student 2 `[1, 4]` is not allowed.
2. **No splitting.** A 10-page book goes to exactly one student.
3. **`m <= n` required.** Otherwise some student gets nothing, so return `-1`.
4. **Lower bound is `max(arr)`.** The answer can never be smaller than the biggest book.

## ❌ Common Mistakes

| Mistake | Correct Approach |
|---------|------------------|
| Trying every allocation | Use Binary Search on Answer |
| Breaking contiguity | Allocate in the given order |
| Splitting a book | A book goes to one student |
| Skipping `arr[i] > maxAllowedPages` | Return `false` |
| Skipping the `m > n` check | Return `-1` |
| Moving left when `mid` is invalid | Move right |
| Moving right when `mid` is valid | Move left to minimize |
| Using `(st + end) / 2` | Use `st + (end - st) / 2` |
| Ignoring student count | Check `stu <= m` |

---

## 🎓 Interview Tip

Be ready to explain:
- What the Book Allocation Problem is
- Why binary search applies (monotonicity)
- What `isValid()` does
- Why we search the answer range, not the array
- Why an invalid `mid` moves right and a valid `mid` moves left
- Why the complexity is `O(n log S)`
- Why the lower bound is `max(arr)`
- What happens when `m > n`

---

## 🌱 What This Chapter Builds

Binary Search, Binary Search on Answer, Monotonic Search Space, Greedy Validation, Optimization Problems.

```text
Don't always search for an element.
Sometimes search for the answer.
```

## 🏆 Final Output

```text
6
```

> **"In Binary Search on Answer, don't ask where the answer is — ask whether a possible answer is valid."** 💻✨
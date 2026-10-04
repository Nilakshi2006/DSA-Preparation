# 🚀 DSA Journey — Chapter 17: Painter's Partition Problem (C++)

Chapter 17 of my Data Structures & Algorithms journey. 💻🎨

I solved the **Painter's Partition Problem** using **Binary Search on Answer**.

Rules:

* Each painter gets at least one board.
* Boards are allocated in contiguous order.
* A board cannot be split between painters.
* Minimize the maximum time taken by any painter.

This is **Binary Search on Answer**: we don't search for an element, we search for the **smallest value that satisfies a condition**.

---

## 🎨 Problem Statement

Given:

* `arr[i]`: time required to paint the `i-th` board
* `n`: total number of boards
* `m`: total number of painters

Each painter paints a contiguous set of boards.

Return the **minimum possible value of the maximum time** taken by any painter.

### 💡 Example

```text
arr = [40, 30, 10, 20], m = 2
```

Allocation A:

```text
Painter 1 → [40]          = 40
Painter 2 → [30, 10, 20]  = 60
```

Maximum time = `60`

Allocation B:

```text
Painter 1 → [40, 30] = 70
Painter 2 → [10, 20] = 30
```

Maximum time = `70`

Therefore:

```text
Minimum possible maximum time = 60
```

---

## 📂 Program Covered

| #  | File Name                     | Concept                                         |
| -- | ----------------------------- | ----------------------------------------------- |
| 01 | `01.BinarySearchApproach.cpp` | Binary Search on Answer for Painter's Partition |

## 📁 Folder Structure

```text
17-PaintersPartitionProblem/

│── output/
│── 01.BinarySearchApproach.cpp

└── README.md
```

---

## 💻 Concepts Used

Arrays, Vectors, Binary Search, Binary Search on Answer, Greedy Approach, Functions, Loops, Optimization Problems, Time and Space Complexity.

---

## 🎯 Main Concept — Binary Search on Answer

We search the **answer range**, not the array.

For:

```text
arr = [40, 30, 10, 20]
```

* Smallest possible answer: `max(arr) = 40`
* Largest possible answer: `sum(arr) = 100`

Why?

A painter must paint at least one complete board, so the answer cannot be smaller than the largest board.

If there is only one painter, that painter paints every board, so the answer can be as large as the total sum.

Therefore:

```text
Search Range = [40, 100]
```

For every candidate `mid`, we ask:

> Can all boards be painted by at most `m` painters without any painter taking more than `mid` time?

The `isValid()` function answers this.

---

## 🧠 Key Idea

Try:

```text
maxAllowedTime = 50
```

Allocation:

```text
Painter 1 → [40] = 40
Painter 2 → [30, 10] = 40
Painter 3 → [20] = 20
```

We need `3` painters, but:

```text
m = 2
```

So:

```text
50 is invalid ❌
```

Now try:

```text
maxAllowedTime = 60
```

Allocation:

```text
Painter 1 → [40] = 40
Painter 2 → [30, 10, 20] = 60
```

We need only `2` painters.

So:

```text
60 is valid ✅
```

Therefore, we continue searching for a smaller valid answer.

---

## 🔍 Step 1 — The `isValid()` Function

```cpp
bool isValid(vector<int>& arr, int n, int m, int maxAllowedTime)
```

| Parameter        | Meaning                           |
| ---------------- | --------------------------------- |
| `arr`            | Time required for each board      |
| `n`              | Number of boards                  |
| `m`              | Number of painters                |
| `maxAllowedTime` | Maximum time one painter can take |

Start with the first painter:

```cpp
int painters = 1;
int time = 0;
```

---

## Step 2 — Reject Oversized Boards

```cpp
if(arr[i] > maxAllowedTime){
    return false;
}
```

A board cannot be split between painters.

Therefore, if one board itself requires more time than the allowed limit, the limit is impossible.

For example:

```text
Board = 70
maxAllowedTime = 60
```

The board cannot be painted within `60`.

Therefore:

```text
false
```

---

## Step 3 — Add Board to Current Painter

```cpp
if(time + arr[i] <= maxAllowedTime){
    time += arr[i];
}
```

If the current painter can paint the board without exceeding the limit, assign the board to that painter.

Example:

```text
Current time = 40
Board = 10
Limit = 60
```

Since:

```text
40 + 10 <= 60
```

the board can be assigned to the current painter.

---

## Step 4 — Move to the Next Painter

```cpp
else{
    painters++;
    time = arr[i];
}
```

If adding the current board would exceed the limit, we need another painter.

Example:

```text
Current time = 40
Board = 30
Limit = 60
```

Since:

```text
40 + 30 > 60
```

the current painter cannot take the board.

So:

```text
Painter 2 → starts with board = 30
```

---

## Step 5 — Check Painter Count

```cpp
return painters <= m;
```

If the required number of painters is greater than the available painters, the candidate limit is invalid.

For example:

```text
Required painters = 3
Available painters = 2
```

Therefore:

```text
3 <= 2 → false
```

So the candidate is invalid.

---

## ### Complete `isValid()`

```cpp
bool isValid(vector<int>& arr, int n, int m, int maxAllowedTime){

    int painters = 1;
    int time = 0;

    for(int i = 0; i < n; i++){

        if(arr[i] > maxAllowedTime){
            return false;
        }

        if(time + arr[i] <= maxAllowedTime){
            time += arr[i];
        }
        else{
            painters++;
            time = arr[i];
        }
    }

    return painters <= m;
}
```

---

## 🔎 Step 6 — Search Range

```cpp
int sum = 0;
int maxBoard = 0;

for(int i = 0; i < n; i++){
    sum += arr[i];
    maxBoard = max(maxBoard, arr[i]);
}

int st = maxBoard;
int end = sum;
```

For:

```text
arr = [40, 30, 10, 20]
```

We get:

```text
maxBoard = 40
sum = 100
```

Therefore:

```text
st = 40
end = 100
```

---

## 🔍 Step 7 — Binary Search

Calculate the middle value:

```cpp
int mid = st + (end - st) / 2;
```

Using:

```cpp
st + (end - st) / 2
```

is safer than:

```cpp
(st + end) / 2
```

because the latter can cause integer overflow when the values are very large.

---

## ✅ Step 8 — `mid` Is Valid

```cpp
if(isValid(arr, n, m, mid)){
    ans = mid;
    end = mid - 1;
}
```

If `mid` is valid:

1. Store it as the current answer.
2. Search the left half.
3. Try to find an even smaller valid answer.

---

## ❌ Step 9 — `mid` Is Invalid

```cpp
else{
    st = mid + 1;
}
```

If `mid` is invalid, the maximum allowed time is too small.

Therefore, search the right half.

---

# 💻 Complete Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int>& arr, int n, int m, int maxAllowedTime){

    int painters = 1;
    int time = 0;

    for(int i = 0; i < n; i++){

        if(arr[i] > maxAllowedTime){
            return false;
        }

        if(time + arr[i] <= maxAllowedTime){
            time += arr[i];
        }
        else{
            painters++;
            time = arr[i];
        }
    }

    return painters <= m;
}

int minTimeToPaint(vector<int>& arr, int n, int m){

    int sum = 0;
    int maxBoard = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];
        maxBoard = max(maxBoard, arr[i]);
    }

    int st = maxBoard;
    int end = sum;
    int ans = -1;

    while(st <= end){

        int mid = st + (end - st) / 2;

        if(isValid(arr, n, m, mid)){
            ans = mid;
            end = mid - 1;   // search left
        }
        else{
            st = mid + 1;    // search right
        }
    }

    return ans;
}

int main(){

    vector<int> arr = {40, 30, 10, 20};

    int n = arr.size();
    int m = 2;

    cout << minTimeToPaint(arr, n, m) << endl;

    return 0;
}
```

---

# 🔍 Dry Run

```text
arr = [40, 30, 10, 20]
n = 4
m = 2

Range:
st = 40
end = 100
```

### **Iteration 1: `mid = 70`**

```text
Painter 1 → [40, 30] = 70
Painter 2 → [10, 20] = 30
```

2 painters → **valid ✅**

```text
ans = 70
end = 69
```

---

### **Iteration 2: `st = 40, end = 69, mid = 54`**

```text
Painter 1 → [40] = 40
Painter 2 → [30, 10] = 40
Painter 3 → [20] = 20
```

3 painters are required.

```text
3 > 2
```

Therefore:

**54 is invalid ❌**

```text
st = 55
```

---

### **Iteration 3: `st = 55, end = 69, mid = 62`**

```text
Painter 1 → [40] = 40
Painter 2 → [30, 10, 20] = 60
```

2 painters → **valid ✅**

```text
ans = 62
end = 61
```

---

### **Iteration 4: `st = 55, end = 61, mid = 58`**

```text
Painter 1 → [40] = 40
Painter 2 → [30, 10] = 40
Painter 3 → [20] = 20
```

3 painters are required.

**58 is invalid ❌**

```text
st = 59
```

---

### **Iteration 5: `st = 59, end = 61, mid = 60`**

```text
Painter 1 → [40] = 40
Painter 2 → [30, 10, 20] = 60
```

2 painters → **valid ✅**

```text
ans = 60
end = 59
```

---

### **Iteration 6: `st = 59, end = 59, mid = 59`**

```text
Painter 1 → [40] = 40
Painter 2 → [30, 10] = 40
Painter 3 → [20] = 20
```

3 painters → **invalid ❌**

```text
st = 60
```

---

### **Stop**

```text
st > end
```

Final answer:

```text
60
```

---

## 📊 Dry Run Table

| Step | `st` | `end` | `mid` | Valid? | Action                |
| ---- | ---- | ----- | ----- | ------ | --------------------- |
| 1    | 40   | 100   | 70    | ✅      | Store 70, search left |
| 2    | 40   | 69    | 54    | ❌      | Search right          |
| 3    | 55   | 69    | 62    | ✅      | Store 62, search left |
| 4    | 55   | 61    | 58    | ❌      | Search right          |
| 5    | 59   | 61    | 60    | ✅      | Store 60, search left |
| 6    | 59   | 59    | 59    | ❌      | Search right          |
| 7    | 60   | 59    | —     | —      | Stop                  |

Final answer:

```text
60
```

---

# 🧠 Why Binary Search Works Here

The answer is **monotonic**.

If `60` is valid, then:

```text
61, 62, 63, ..., 100
```

will also be valid.

A larger maximum allowed time can never make an already possible allocation impossible.

Similarly, if `59` is invalid, then:

```text
40, 41, 42, ..., 59
```

are also invalid.

Therefore, the search space looks like:

```text
Invalid Invalid Invalid | Valid Valid Valid Valid
                         ↑
                  Minimum Answer
```

This monotonic property allows us to use Binary Search.

---

# 📌 Pattern: Binary Search on Answer

Ask:

> **Can I check whether a particular answer is possible?**

If the result follows:

```text
False False False False True True True
```

then Binary Search can often be applied.

General approach:

```text
1. Identify the answer range.

2. Pick the middle value.

3. Check if it is possible.

4. Possible
   → store answer
   → search left

5. Impossible
   → search right

6. Stop when the minimum valid answer is found.
```

---

# 🧪 Examples

### **Example 1**

```text
arr = {40, 30, 10, 20}
m = 2
```

Output:

```text
60
```

---

### **Example 2**

```text
arr = {10, 20, 30, 40}
m = 2
```

Possible allocation:

```text
Painter 1 → [10, 20, 30] = 60
Painter 2 → [40] = 40
```

Maximum:

```text
60
```

Output:

```text
60
```

---

### **Example 3**

```text
arr = {10, 20, 30, 40}
m = 3
```

Possible allocation:

```text
Painter 1 → [10, 20] = 30
Painter 2 → [30] = 30
Painter 3 → [40] = 40
```

Output:

```text
40
```

---

### **Example 4**

```text
arr = {10, 20, 30}
m = 1
```

Only one painter is available:

```text
Painter 1 → [10, 20, 30] = 60
```

Output:

```text
60
```

---

### **Example 5**

```text
arr = {10, 20}
m = 3
```

There are only 2 boards but 3 painters.

If every painter must receive at least one board, this allocation is impossible.

Output:

```text
-1
```

> **Note:** This `-1` rule applies when the problem requires every painter to receive at least one board.

---

# 📈 Complexity

Let:

* `n` = number of boards
* `S` = total painting time

| Operation                | Time             | Space      |
| ------------------------ | ---------------- | ---------- |
| One `isValid()` check    | `O(n)`           | `O(1)`     |
| Binary Search iterations | `O(log S)`       | `O(1)`     |
| **Overall**              | **`O(n log S)`** | **`O(1)`** |

Each Binary Search iteration performs one `O(n)` validation.

Therefore:

```text
Overall Time = O(n log S)
Space = O(1)
```

---

# 🔥 Template

```cpp
int st = minimumPossible;
int end = maximumPossible;
int ans = -1;

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

For Painter's Partition:

```cpp
minimumPossible = max(arr)
maximumPossible = sum(arr)
```

---

# ⚠️ Important Notes

### 1. **Contiguous allocation**

Boards must be assigned in their original order.

For:

```text
[40, 30, 10, 20]
```

This is allowed:

```text
Painter 1 → [40, 30]
Painter 2 → [10, 20]
```

But this is not allowed:

```text
Painter 1 → [40, 10]
Painter 2 → [30, 20]
```

because the boards are no longer contiguous.

---

### 2. **No splitting**

A board cannot be divided between two painters.

For example:

```text
Board = 40
```

It must be completely assigned to one painter.

---

### 3. **`m <= n`**

If every painter must receive at least one board:

```cpp
if(m > n){
    return -1;
}
```

---

### 4. **Lower bound is `max(arr)`**

The answer can never be smaller than the largest board.

For:

```text
arr = [40, 30, 10, 20]
```

the answer cannot be:

```text
30
```

because the board requiring `40` units of time still has to be painted.

Therefore:

```text
minimum answer = 40
```

---

### 5. **Upper bound is `sum(arr)`**

If there is only one painter, that painter paints every board.

Therefore:

```text
maximum answer = sum(arr)
```

For:

```text
40 + 30 + 10 + 20 = 100
```

the maximum possible answer is:

```text
100
```

---

# ❌ Common Mistakes

| Mistake                            | Correct Approach                   |
| ---------------------------------- | ---------------------------------- |
| Trying every possible partition    | Use Binary Search on Answer        |
| Breaking contiguity                | Allocate boards in the given order |
| Splitting a board                  | A board goes to one painter        |
| Ignoring `arr[i] > maxAllowedTime` | Return `false`                     |
| Skipping `m > n` check             | Return `-1` when required          |
| Moving left when `mid` is invalid  | Move right                         |
| Moving right when `mid` is valid   | Move left to minimize              |
| Using `(st + end) / 2`             | Use `st + (end - st) / 2`          |
| Ignoring painter count             | Check `painters <= m`              |
| Starting from `0`                  | Start from `max(arr)`              |

---

# 🎓 Interview Tip

Be ready to explain:

* What the Painter's Partition Problem is
* Why Binary Search applies
* What `isValid()` does
* Why we search the answer range instead of the array
* Why the lower bound is `max(arr)`
* Why the upper bound is `sum(arr)`
* Why an invalid `mid` moves right
* Why a valid `mid` moves left
* Why boards must remain contiguous
* Why boards cannot be split
* Why the complexity is `O(n log S)`

A simple interview explanation:

> "I use Binary Search on Answer. The minimum possible time is the maximum board length, and the maximum possible time is the sum of all board lengths. For every middle value, I greedily assign contiguous boards to the current painter until adding another board would exceed the limit. Then I move to the next painter. If the required painters are within `m`, the value is valid and I search left; otherwise, I search right."

---

# 🌱 What This Chapter Builds

Binary Search, Binary Search on Answer, Monotonic Search Space, Greedy Validation, Partition Problems, Optimization Problems.

```text
Don't always search for an element.

Sometimes search for the answer.
```

---

# 🏆 Final Output

For:

```text
arr = {40, 30, 10, 20}
m = 2
```

Output:

```text
60
```

> **"In Binary Search on Answer, don't ask where the answer is — ask whether a possible answer is valid."** 💻🎨

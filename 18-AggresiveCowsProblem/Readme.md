# 🚀 DSA Journey — Chapter 18: Aggressive Cows (C++)

Chapter 18 of my Data Structures & Algorithms journey. 💻🐄

I solved the **Aggressive Cows Problem** using **Binary Search on Answer**.

Rules:

* Each stall holds at most one cow.
* All `k` cows must be placed.
* Stalls are at given positions on a line.
* Maximize the minimum distance between any two cows.

This is the mirror image of Painter's Partition: there we minimized a maximum, here we **maximize a minimum**.

---

## 🐄 Problem Statement

Given:

* `stalls[i]`: position of the `i-th` stall
* `n`: total number of stalls
* `k`: total number of cows

Place all cows in stalls so that the **smallest distance between any two cows is as large as possible**.

Return that largest possible minimum distance.

### 💡 Example

```text
stalls = [1, 2, 4, 8, 9], k = 3
```

Placement A:

```text
Cows at 1, 2, 4 → distances 1, 2
```

Minimum distance = `1`

Placement B:

```text
Cows at 1, 4, 8 → distances 3, 4
```

Minimum distance = `3`

Therefore:

```text
Maximum possible minimum distance = 3
```

---

## 📂 Program Covered

| #  | File Name                     | Concept                                      |
| -- | ----------------------------- | -------------------------------------------- |
| 01 | `01.BinarySearchApproach.cpp` | Binary Search on Answer for Aggressive Cows  |

## 📁 Folder Structure

```text
18-AggressiveCows/

│── output/
│── 01.BinarySearchApproach.cpp

└── README.md
```

---

## 💻 Concepts Used

Arrays, Vectors, Sorting, Binary Search, Binary Search on Answer, Greedy Approach, Functions, Loops, Optimization Problems, Time and Space Complexity.

---

## 🎯 Main Concept — Binary Search on Answer

We search the **distance range**, not the stalls.

For:

```text
stalls = [1, 2, 4, 8, 9]
```

* Smallest possible answer: `1`
* Largest possible answer: `stalls[n-1] - stalls[0] = 8`

Why?

Stalls are at distinct positions, so the minimum gap is at least `1`.

With only two cows, the best placement is the first and last stall, giving `8`. No distance can be larger.

Therefore:

```text
Search Range = [1, 8]
```

For every candidate `mid`, we ask:

> Can all `k` cows be placed so that every pair is at least `mid` apart?

The `isValid()` function answers this.

---

## 🧠 Key Idea

Try:

```text
minAllowedDistance = 4
```

Placement:

```text
Cow 1 → stall 1
Cow 2 → stall 8   (8 - 1 = 7 ≥ 4)
```

Stalls `2` and `4` are too close to `1`, and `9` is too close to `8`.

We placed only `2` cows, but:

```text
k = 3
```

So:

```text
4 is invalid ❌
```

Now try:

```text
minAllowedDistance = 3
```

Placement:

```text
Cow 1 → stall 1
Cow 2 → stall 4   (4 - 1 = 3 ≥ 3)
Cow 3 → stall 8   (8 - 4 = 4 ≥ 3)
```

All `3` cows placed.

So:

```text
3 is valid ✅
```

Therefore, we continue searching for a larger valid answer.

---

## 🔍 Step 1 — Sort the Stalls

```cpp
sort(stalls.begin(), stalls.end());
```

Stall positions may come unsorted. Greedy placement only works left to right, so sorting is mandatory.

---

## Step 2 — The `isValid()` Function

```cpp
bool isValid(vector<int>& stalls, int n, int k, int minAllowedDistance)
```

| Parameter            | Meaning                              |
| -------------------- | ------------------------------------ |
| `stalls`             | Sorted stall positions               |
| `n`                  | Number of stalls                     |
| `k`                  | Number of cows                       |
| `minAllowedDistance` | Minimum gap required between cows    |

Place the first cow in the first stall:

```cpp
int cows = 1;
int lastStall = stalls[0];
```

Placing the first cow at the leftmost stall is always safe. It leaves the most room for the rest.

---

## Step 3 — Place a Cow if the Gap Is Enough

```cpp
if (stalls[i] - lastStall >= minAllowedDistance) {
    cows++;
    lastStall = stalls[i];
}
```

If the current stall is far enough from the last cow, place a cow here.

Example:

```text
Last cow = 4
Stall = 8
Limit = 3
```

Since:

```text
8 - 4 = 4 ≥ 3
```

a cow can be placed at stall `8`.

Otherwise, skip the stall and check the next one.

---

## Step 4 — Check Cow Count

```cpp
if (cows == k) {
    return true;
}
```

As soon as all `k` cows are placed, the distance is valid. There is no need to scan further.

If the loop ends with fewer than `k` cows:

```cpp
return false;
```

---

## ### Complete `isValid()`

```cpp
bool isValid(vector<int>& stalls, int n, int k, int minAllowedDistance) {
    int cows = 1;
    int lastStall = stalls[0];

    for (int i = 1; i < n; i++) {

        if (stalls[i] - lastStall >= minAllowedDistance) {
            cows++;
            lastStall = stalls[i];
        }

        if (cows == k) {
            return true;
        }
    }

    return false;
}
```

---

## 🔎 Step 5 — Search Range

```cpp
int st = 1;
int end = stalls[n - 1] - stalls[0];
```

For:

```text
stalls = [1, 2, 4, 8, 9]
```

We get:

```text
st = 1
end = 9 - 1 = 8
```

---

## 🔍 Step 6 — Binary Search

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

## ✅ Step 7 — `mid` Is Valid

```cpp
if (isValid(stalls, n, k, mid)) {
    ans = mid;
    st = mid + 1;
}
```

If `mid` is valid:

1. Store it as the current answer.
2. Search the right half.
3. Try to find an even larger valid distance.

---

## ❌ Step 8 — `mid` Is Invalid

```cpp
else {
    end = mid - 1;
}
```

If `mid` is invalid, the required distance is too large.

Therefore, search the left half.

---

# 💻 Complete Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int>& stalls, int n, int k, int minAllowedDistance) {
    int cows = 1;
    int lastStall = stalls[0];

    for (int i = 1; i < n; i++) {

        if (stalls[i] - lastStall >= minAllowedDistance) {
            cows++;
            lastStall = stalls[i];
        }

        if (cows == k) {
            return true;
        }
    }

    return false;
}

int aggressiveCows(vector<int>& stalls, int n, int k) {

    sort(stalls.begin(), stalls.end());

    int st = 1;
    int end = stalls[n - 1] - stalls[0];
    int ans = -1;

    while (st <= end) {

        int mid = st + (end - st) / 2;

        if (isValid(stalls, n, k, mid)) {
            ans = mid;
            st = mid + 1;       // try for a larger distance
        }
        else {
            end = mid - 1;      // distance is too large
        }
    }

    return ans;
}

int main() {

    vector<int> stalls = {1, 2, 4, 8, 9};

    int n = stalls.size();
    int k = 3;

    cout << aggressiveCows(stalls, n, k) << endl;

    return 0;
}
```

---

# 🔍 Dry Run

```text
stalls = [1, 2, 4, 8, 9]
n = 5
k = 3

Range:
st = 1
end = 8
```

### **Iteration 1: `mid = 4`**

```text
Cow 1 → 1
Cow 2 → 8
```

Only 2 cows placed.

```text
2 < 3
```

Therefore:

**4 is invalid ❌**

```text
end = 3
```

---

### **Iteration 2: `st = 1, end = 3, mid = 2`**

```text
Cow 1 → 1
Cow 2 → 4
Cow 3 → 8
```

3 cows placed → **valid ✅**

```text
ans = 2
st = 3
```

---

### **Iteration 3: `st = 3, end = 3, mid = 3`**

```text
Cow 1 → 1
Cow 2 → 4
Cow 3 → 8
```

3 cows placed → **valid ✅**

```text
ans = 3
st = 4
```

---

### **Stop**

```text
st > end
```

Final answer:

```text
3
```

---

## 📊 Dry Run Table

| Step | `st` | `end` | `mid` | Valid? | Action                 |
| ---- | ---- | ----- | ----- | ------ | ---------------------- |
| 1    | 1    | 8     | 4     | ❌      | Search left            |
| 2    | 1    | 3     | 2     | ✅      | Store 2, search right  |
| 3    | 3    | 3     | 3     | ✅      | Store 3, search right  |
| 4    | 4    | 3     | —     | —      | Stop                   |

Final answer:

```text
3
```

---

# 🧠 Why Binary Search Works Here

The answer is **monotonic**.

If `3` is valid, then:

```text
1, 2, 3
```

are also valid.

A smaller required distance can never make an already possible placement impossible.

Similarly, if `4` is invalid, then:

```text
4, 5, 6, 7, 8
```

are also invalid.

Therefore, the search space looks like:

```text
Valid Valid Valid | Invalid Invalid Invalid
                ↑
         Maximum Answer
```

This monotonic property allows us to use Binary Search.

---

# 📌 Pattern: Binary Search on Answer

Ask:

> **Can I check whether a particular answer is possible?**

If the result follows:

```text
True True True False False False
```

then Binary Search can often be applied.

General approach:

```text
1. Identify the answer range.

2. Pick the middle value.

3. Check if it is possible.

4. Possible
   → store answer
   → search right (maximize)

5. Impossible
   → search left

6. Stop when the maximum valid answer is found.
```

---

# 🆚 Painter's Partition vs Aggressive Cows

| Feature         | Painter's Partition           | Aggressive Cows                  |
| --------------- | ----------------------------- | -------------------------------- |
| Goal            | Minimize the maximum          | Maximize the minimum             |
| Search range    | `[max(arr), sum(arr)]`        | `[1, last - first]`              |
| Valid `mid`     | Store, move **left**          | Store, move **right**            |
| Invalid `mid`   | Move **right**                | Move **left**                    |
| Greedy check    | Pack boards into painters     | Place cows as far left as possible |
| Needs sorting   | No                            | Yes                              |

---

# 🧪 Examples

### **Example 1**

```text
stalls = {1, 2, 4, 8, 9}
k = 3
```

Output:

```text
3
```

---

### **Example 2**

```text
stalls = {1, 2, 4, 8, 9}
k = 2
```

Best placement:

```text
Cow 1 → 1
Cow 2 → 9
```

Output:

```text
8
```

---

### **Example 3**

```text
stalls = {1, 2, 4, 8, 9}
k = 5
```

Every stall must hold a cow, so the closest pair (`1` and `2`) decides the answer.

Output:

```text
1
```

---

### **Example 4**

```text
stalls = {5, 17, 100, 11}
k = 2
```

After sorting: `{5, 11, 17, 100}`

```text
Cow 1 → 5
Cow 2 → 100
```

Output:

```text
95
```

---

### **Example 5**

```text
stalls = {1, 2, 4}
k = 5
```

There are only 3 stalls but 5 cows.

Output:

```text
-1
```

> **Note:** `ans` stays `-1` because `isValid()` never places `k` cows.

---

# 📈 Complexity

Let:

* `n` = number of stalls
* `D` = `stalls[n-1] - stalls[0]`

| Operation                | Time               | Space      |
| ------------------------ | ------------------ | ---------- |
| Sorting                  | `O(n log n)`       | `O(1)`     |
| One `isValid()` check    | `O(n)`             | `O(1)`     |
| Binary Search iterations | `O(log D)`         | `O(1)`     |
| **Overall**              | **`O(n log n + n log D)`** | **`O(1)`** |

Each Binary Search iteration performs one `O(n)` validation.

---

# 🔥 Template

```cpp
int st = minimumPossible;
int end = maximumPossible;
int ans = -1;

while (st <= end) {

    int mid = st + (end - st) / 2;

    if (isValid(mid)) {

        ans = mid;

        st = mid + 1;    // look for larger
    }
    else {

        end = mid - 1;   // need smaller
    }
}
```

For Aggressive Cows:

```cpp
minimumPossible = 1
maximumPossible = stalls[n-1] - stalls[0]
```

---

# ⚠️ Important Notes

### 1. **Sort first**

The greedy check assumes stalls are in increasing order.

---

### 2. **Place the first cow at `stalls[0]`**

The leftmost stall leaves the maximum room for the remaining cows.

---

### 3. **`k <= n`**

Each stall holds one cow. If `k > n`, no valid placement exists and the answer is `-1`.

---

### 4. **Early return when `cows == k`**

Once all cows are placed, the distance is valid. No need to check the remaining stalls.

---

### 5. **Direction is opposite to Painter's Partition**

Valid `mid` → search **right** (we want a larger distance).
Invalid `mid` → search **left**.

---

# ❌ Common Mistakes

| Mistake                              | Correct Approach                      |
| ------------------------------------ | ------------------------------------- |
| Forgetting to sort `stalls`          | Sort before searching                 |
| Trying every possible placement      | Use Binary Search on Answer           |
| Moving right when `mid` is invalid   | Move left                             |
| Moving left when `mid` is valid      | Move right to maximize                |
| Using `>` instead of `>=` for gap    | Gap equal to `mid` is allowed         |
| Not updating `lastStall`             | Update it after every placement       |
| Skipping the `k > n` case            | Return `-1`                           |
| Using `(st + end) / 2`               | Use `st + (end - st) / 2`             |
| Starting `st` at `0`                 | Start from `1`                        |

---

# 🎓 Interview Tip

Be ready to explain:

* What the Aggressive Cows Problem is
* Why Binary Search applies
* What `isValid()` does
* Why we search the distance range instead of the stalls
* Why sorting is required
* Why the upper bound is `last - first`
* Why a valid `mid` moves right
* Why an invalid `mid` moves left
* Why the first cow goes in the first stall
* Why the complexity is `O(n log n + n log D)`

A simple interview explanation:

> "I sort the stalls and use Binary Search on Answer. The minimum possible distance is 1 and the maximum is the gap between the first and last stall. For every middle value, I greedily place a cow in the first stall, then in the next stall that is at least `mid` away from the last cow. If I can place all `k` cows, the value is valid and I search right for a larger distance; otherwise, I search left."

---

# 🌱 What This Chapter Builds

Binary Search, Binary Search on Answer, Monotonic Search Space, Greedy Validation, Sorting, Maximize-the-Minimum Problems.

```text
Don't always search for an element.

Sometimes search for the answer.
```

---

# 🏆 Final Output

For:

```text
stalls = {1, 2, 4, 8, 9}
k = 3
```

Output:

```text
3
```

> **"In Binary Search on Answer, don't ask where the answer is — ask whether a possible answer is valid."** 💻🐄
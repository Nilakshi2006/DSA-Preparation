# 🚀 DSA Journey – Chapter 8: Better Brute Force (C++)

Welcome to **Chapter 8** of my **Data Structures & Algorithms (DSA)** journey! 💻✨

In this chapter, I learned how to solve two important array problems using **better brute force and optimized techniques**:

- **Pair Sum (Two Sum)** using the **Brute Force Approach** and the **Two Pointer Approach**.
- **Majority Element** using a **Frequency Map (`unordered_map`)**.

These are among the most common **LeetCode, coding interview, and competitive programming** problems for learning array optimization and hashing.

---

## 📚 Programs Covered

| # | File Name | Concept |
|---|-----------|---------|
| 01 | `01.PairSum.cpp` | Find the indices of two numbers whose sum equals the target using the Brute Force approach (`O(n²)`). |
| 02 | `02.OptimisedPairSum.cpp` | Find the Pair Sum using the Two Pointer approach (`O(n)`) on a sorted array. |
| 03 | `03.MajorityElement.cpp` | Find the Majority Element using `unordered_map` (Frequency Map). |

---

# 🎯 Concepts I Learned

This chapter helped me understand **nested loops, vectors, two pointers, hashing, frequency counting, and optimization techniques**.

---

## 🌱 1. Pair Sum (Two Sum)

The **Pair Sum** problem asks us to find **two elements whose sum is equal to a given target value**.

Instead of returning the values, these programs return the **indices** of the pair.

### Example

```cpp
nums = {2, 7, 1, 15};
target = 9;
```

**Output**

```text
0,1
```

**Explanation**

```cpp
nums[0] + nums[1] = 2 + 7 = 9
```

### 📌 Key Learning

- A **vector** is used to return multiple values from a function.
- `ans[0]` stores the first index.
- `ans[1]` stores the second index.

---

## 🔍 2. Pair Sum — Brute Force Approach

The Brute Force approach checks **every possible pair** in the array.

### Algorithm

1. Start from each element.
2. Compare it with every element after it.
3. If the sum equals the target, store both indices.
4. Return the answer vector.

### Logic Used

```cpp
for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
        if(nums[i] + nums[j] == target){
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
}
```

### Example Output

```text
0,1
```

### 📌 Key Learning

- Uses **two nested loops**.
- Checks every possible pair.
- Easy to understand but slower for large arrays.

**Time Complexity:** `O(n²)`

**Space Complexity:** `O(1)` *(excluding the answer vector).*

---

## ⚡ 3. Pair Sum — Two Pointer Approach

The Two Pointer approach is an **optimized solution** for a **sorted array**.

It uses two pointers:

- `i` → Beginning of the array.
- `j` → End of the array.

### Algorithm

1. Place one pointer at the beginning and one at the end.
2. Calculate the sum of both elements.
3. If the sum is greater than the target, move `j` left.
4. If the sum is smaller than the target, move `i` right.
5. If the sum matches the target, return both indices.

### Logic Used

```cpp
int i = 0;
int j = n - 1;

while(i < j){
    int pairSum = nums[i] + nums[j];

    if(pairSum > target){
        j--;
    }
    else if(pairSum < target){
        i++;
    }
    else{
        ans.push_back(i);
        ans.push_back(j);
        return ans;
    }
}
```

### Example

```cpp
nums = {2, 7, 10, 15};
target = 17;
```

**Output**

```text
0,3
```

**Explanation**

```cpp
nums[0] + nums[3] = 2 + 15 = 17
```

### 📌 Key Learning

- Uses **two pointers** moving toward each other.
- Eliminates unnecessary comparisons.
- Works efficiently only for **sorted arrays**.

**Time Complexity:** `O(n)`

**Space Complexity:** `O(1)`

> **Note:** The Two Pointer approach works correctly only when the input array is sorted.

---

## 🗂️ 4. Majority Element

The **Majority Element** problem asks us to find the element that appears **more than `n/2` times** in an array.

### Example

```cpp
nums = {2, 2, 1, 2, 3, 2, 2};
```

**Output**

```text
Majority Element = 2
```

Because `2` appears **5 times**, and `5 > 7/2`.

### 📌 Key Learning

- Count the frequency of each element.
- Return the element whose frequency is greater than `n/2`.

---

## 🔢 5. Majority Element Using `unordered_map`

This solution uses a **hash map** to store the frequency of every element.

### Algorithm

1. Traverse the array.
2. Store frequency using `unordered_map`.
3. Traverse again.
4. Return the element whose frequency is greater than `n/2`.

### Logic Used

```cpp
unordered_map<int, int> freq;

for(int i = 0; i < n; i++){
    freq[nums[i]]++;
}

for(int i = 0; i < n; i++){
    if(freq[nums[i]] > n/2){
        return nums[i];
    }
}
```

### Example Output

```text
Majority Element = 2
```

### 📌 Key Learning

- `unordered_map` stores values as **element → frequency**.
- Frequency counting is completed in linear time.
- Useful for many hashing-based interview questions.

**Time Complexity:** `O(n)`

**Space Complexity:** `O(n)`

---

## ⚖️ Brute Force vs Two Pointer Approach

| Feature | Brute Force | Two Pointer |
|---------|-------------|-------------|
| Approach | Checks every possible pair. | Uses two pointers from both ends. |
| Array Requirement | Works on any array. | Requires a sorted array. |
| Time Complexity | `O(n²)` | `O(n)` |
| Space Complexity | `O(1)` | `O(1)` |
| Efficiency | Slower for large arrays. | Faster and optimized. |

---

## ⚖️ Majority Element (`unordered_map`) Summary

| Feature | `unordered_map` Approach |
|---------|--------------------------|
| Technique | Frequency Counting (Hash Map) |
| Time Complexity | `O(n)` |
| Space Complexity | `O(n)` |
| Best Use | Counting occurrences efficiently using hashing. |

---

# 💻 Language Used

- **C++**

### Concepts Used

- Arrays
- Vectors (`vector<int>`)
- Nested Loops
- Two Pointer Technique
- Hashing
- `unordered_map`
- Frequency Counting
- Functions Returning a Vector
- Time & Space Complexity

---

## 📂 Folder Structure

```text
08-BetterBruteForce/
│── output/
│── 01.PairSum.cpp
│── 02.OptimisedPairSum.cpp
│── 03.MajorityElement.cpp
└── README.md
```

---

## 📊 Complexity Summary

| Program | Time Complexity | Space Complexity |
|---------|-----------------|------------------|
| Pair Sum (Brute Force) | `O(n²)` | `O(1)` |
| Pair Sum (Two Pointer) | `O(n)` | `O(1)` |
| Majority Element (`unordered_map`) | `O(n)` | `O(n)` |

---

## 🌱 What This Chapter Builds

By completing these programs, I strengthened my understanding of:

- Solving the **Pair Sum (Two Sum)** problem using the Brute Force approach.
- Optimizing Pair Sum using the **Two Pointer Technique**.
- Understanding when the Two Pointer approach should be used.
- Returning multiple values from a function using a **vector**.
- Using **`unordered_map`** for efficient frequency counting.
- Solving the **Majority Element** problem using hashing.

This chapter builds the foundation for upcoming DSA topics like **Binary Search, Sliding Window, Prefix Sum, Hashing, and Array Optimization Problems**.

---

# 📖 Key Takeaways

- **Pair Sum** finds two elements whose sum equals a target value.
- **Brute Force** checks every possible pair using nested loops.
- The **Two Pointer** approach solves Pair Sum in **`O(n)`** time for sorted arrays.
- **Vectors** can return multiple values, such as the indices of the answer.
- `ans[0]` and `ans[1]` access the first and second returned indices from the vector.
- **`unordered_map`** stores frequencies in the form **key → count**.
- The **Majority Element** appears more than **`n/2` times** in an array.
- Hashing is an important optimization technique for many array-based DSA problems.

---

> **"Brute Force helps understand the logic, while Two Pointers and Hashing teach how to optimize the same problem for coding interviews."** 🚀
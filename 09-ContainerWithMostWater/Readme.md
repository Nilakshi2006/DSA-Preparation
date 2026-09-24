# 🚀 DSA Journey – Chapter 9: Container With Most Water (C++)

Welcome to **Chapter 9** of my **Data Structures & Algorithms (DSA)** journey! 💧💻

In this chapter, I learned how to solve the **Container With Most Water** problem using **two approaches**:

- **Brute Force Approach** using nested loops.
- **Two Pointer Approach** (optimized solution).

This is one of the most popular **LeetCode, coding interview, and array optimization** problems for learning the **Two Pointer Technique**.

---

## 📚 Programs Covered

| # | File Name | Concept |
|---|-----------|---------|
| 01 | `01.BruteForceApproach.cpp` | Find the maximum water container area using the Brute Force approach (`O(n²)`). |
| 02 | `02.TwoPointerApproach.cpp` | Find the maximum water container area using the optimized Two Pointer approach (`O(n)`). |

---

# 🎯 Concepts I Learned

This chapter helped me understand **nested loops, vectors, two pointers, optimization techniques, and time-space complexity**.

---

## 🌊 1. Container With Most Water

The **Container With Most Water** problem asks us to find **two vertical lines that can store the maximum amount of water**.

The amount of water stored depends on:

- **Width** → Distance between the two lines.
- **Height** → The shorter of the two lines.

### Formula Used

```cpp
Area = Width × Minimum Height
```

### Example

```cpp
height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
```

**Output**

```text
Maximum Area = 49
```

### Explanation

The maximum water is stored between heights **8** and **7**.

```cpp
Width = 8 - 1 = 7
Height = min(8, 7) = 7

Area = 7 × 7 = 49
```

### 📌 Key Learning

- Water level is always determined by the **shorter line**.
- We need to find the **maximum possible area** among all pairs.

---

## 🔍 2. Container With Most Water — Brute Force Approach

The Brute Force approach checks **every possible pair of lines**.

### Algorithm

1. Pick one line.
2. Compare it with every line after it.
3. Calculate the width.
4. Find the minimum height.
5. Calculate the area.
6. Store the maximum area.

### Logic Used

```cpp
for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){

        int width = j - i;
        int height1 = min(height[i], height[j]);
        int newArea = width * height1;

        maxArea = max(maxArea, newArea);
    }
}
```

### Example Output

```text
Maximum Area = 49
```

### 📌 Key Learning

- Uses **two nested loops**.
- Calculates the area for **every possible pair**.
- Easy to understand but inefficient for large arrays.

**Time Complexity:** `O(n²)`

**Space Complexity:** `O(1)`

---

## ⚡ 3. Container With Most Water — Two Pointer Approach

The Two Pointer approach is the **optimized solution**.

Instead of checking every pair, it starts from **both ends** of the array.

It uses two pointers:

- `lp` → Left Pointer (Beginning of the array).
- `rp` → Right Pointer (End of the array).

### Algorithm

1. Place one pointer at the beginning (`lp`).
2. Place another pointer at the end (`rp`).
3. Calculate the current area.
4. Store the maximum area.
5. Move the pointer having the **smaller height**.
6. Repeat until both pointers meet.

### Logic Used

```cpp
int lp = 0;
int rp = n - 1;

while(lp < rp){

    int width = rp - lp;
    int height1 = min(height[lp], height[rp]);
    int newArea = width * height1;

    maxArea = max(maxArea, newArea);

    if(height[lp] < height[rp]){
        lp++;
    }
    else{
        rp--;
    }
}
```

### Example Output

```text
Maximum Area = 49
```

### 📌 Key Learning

- Uses **two pointers moving toward each other**.
- Eliminates unnecessary comparisons.
- Gives the same answer much faster.

**Time Complexity:** `O(n)`

**Space Complexity:** `O(1)`

> **Note:** Always move the pointer with the **smaller height** because moving the taller line cannot increase the water level.

---

## 🧠 4. Why Do We Move the Smaller Pointer?

Suppose:

```cpp
height = {1, 8, 6, 2, 5, 4, 8, 3, 7}
```

Initially,

```cpp
lp = 0
rp = 8

Width = 8
Height = min(1,7) = 1

Area = 8
```

Since `1 < 7`, we move `lp`.

### Explanation

- Width decreases in every step.
- To get a larger area, we need a **taller minimum height**.
- Only moving the pointer with the smaller height gives a chance of finding a larger area.

This is the key optimization behind the Two Pointer approach.

---

## ⚖️ Brute Force vs Two Pointer Approach

| Feature | Brute Force | Two Pointer |
|---------|-------------|-------------|
| Approach | Checks every possible pair. | Uses two pointers from both ends. |
| Technique | Nested loops. | Two Pointer Optimization. |
| Array Requirement | Works on any array. | Works on any array for this problem. |
| Time Complexity | `O(n²)` | `O(n)` |
| Space Complexity | `O(1)` | `O(1)` |
| Efficiency | Slower for large arrays. | Faster and optimized. |

---

# 💻 Language Used

- **C++**

### Concepts Used

- Arrays
- Vectors (`vector<int>`)
- Nested Loops
- Two Pointer Technique
- `min()` Function
- `max()` Function
- Width & Height Calculation
- Time & Space Complexity

---

## 📂 Folder Structure

```text
09-ContainerWithMostWater/
│── output/
│── 01.BruteForceApproach.cpp
│── 02.TwoPointerApproach.cpp
└── README.md
```

---

## 📊 Complexity Summary

| Program | Time Complexity | Space Complexity |
|---------|-----------------|------------------|
| Brute Force Approach | `O(n²)` | `O(1)` |
| Two Pointer Approach | `O(n)` | `O(1)` |

---

## 🌱 What This Chapter Builds

By completing these programs, I strengthened my understanding of:

- Solving the **Container With Most Water** problem using the **Brute Force Approach**.
- Optimizing the same problem using the **Two Pointer Technique**.
- Understanding why the **shorter height pointer** is moved.
- Calculating area using **Width × Minimum Height**.
- Comparing **Brute Force vs Optimized Approach** based on time complexity.
- Applying the **Two Pointer Technique** to solve array optimization problems efficiently.

This chapter builds the foundation for upcoming DSA topics like **Sliding Window, Binary Search, Prefix Sum, Trapping Rain Water, and Advanced Two Pointer Problems**.

---

# 📖 Key Takeaways

- **Container With Most Water** finds the maximum area formed by two vertical lines.
- The **area** is calculated as **Width × Minimum Height**.
- **Brute Force** checks every possible pair using nested loops.
- The **Two Pointer** approach solves the problem in **`O(n)`** time.
- Always move the pointer pointing to the **smaller height** to maximize the chance of finding a larger area.
- The **Two Pointer Technique** is one of the most important optimization methods in array-based interview questions.

---

> **"Brute Force helps understand every possibility, while the Two Pointer technique teaches how to eliminate unnecessary comparisons and solve the same problem in linear time."** 🚀
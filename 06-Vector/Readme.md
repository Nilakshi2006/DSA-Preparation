# 🚀 DSA Journey – Chapter 6: Vectors (C++)

Welcome to **Chapter 6** of my **Data Structures & Algorithms (DSA)** journey! 📦🌿

After learning **Arrays**, I started exploring **Vectors** — one of the most useful containers in the C++ Standard Template Library (STL).

Vectors are **dynamic arrays** that automatically resize as elements are added or removed. This chapter covers the fundamentals of vectors in C++, including **initialization, traversal using the for-each loop, built-in vector functions, size vs capacity, linear search, and reversing a vector using the two-pointer technique with `swap()` and pass by reference**.

Vectors are widely used in **LeetCode, coding interviews, competitive programming, and real-world C++ applications** because they are flexible and easy to use.

---

## 📚 Programs Covered

| # | File Name | Concept |
|---|-----------|---------|
| 01 | `01.InitialisationOfVector.cpp` | Different Ways to Initialize a Vector. |
| 02 | `02.ForEachLoop.cpp` | Traverse a Vector using For-Each Loop. |
| 03 | `03.VectorFunction.cpp` | Built-in Vector Functions (`push_back`, `pop_back`, `front`, `back`, `at`, `size`). |
| 04 | `04.SizeAndCapacity.cpp` | Difference Between Vector Size and Capacity. |
| 05 | `05.LinearSearch.cpp` | Perform Linear Search in a Vector. |
| 06 | `06.Reverse.cpp` | Reverse a Vector using `swap()` and Pass by Reference. |

---

# 🎯 Concepts I Learned

This chapter introduced me to the basics of **dynamic arrays, vector traversal, searching, reversing, and understanding vector memory management**.

---

## 🌱 1. Vector Initialization

A **vector** is a dynamic array that stores elements in contiguous memory and automatically resizes itself.

### Syntax

```cpp
vector<int> vec;
```

Creates an **empty vector** with size `0`.

### Different Ways to Initialize a Vector

```cpp
vector<int> vec;               // Empty vector

vector<int> vec = {1, 2, 3};   // Initialize with values

vector<int> vec(3, 0);         // Size = 3, every element = 0
```

### Example

```cpp
vector<int> vec(3, 0);

cout << vec[2];
```

### Output

```text
0
```

### 📌 Key Learning

- Vectors are indexed from **0**.
- `vector<int> vec(3,0)` creates a vector of **3 elements**, each initialized to `0`.
- Vectors can grow dynamically using built-in functions.

---

## 🔁 2. For-Each Loop in Vector

The **For-Each Loop** is a simple way to traverse every element in a vector without using indexes.

### Syntax

```cpp
for (int value : vec)
{
    cout << value;
}
```

### Example

```cpp
vector<int> num = {1, 2, 3, 4};

for (int value : num)
{
    cout << value << " ";
}
```

### Output

```text
1 2 3 4
```

### 📌 Key Learning

- `value` stores each element of the vector.
- No need to use an index variable.
- Makes traversal cleaner and easier to read.

**Time Complexity:** `O(n)`

---

## ⚙️ 3. Vector Built-in Functions

Vectors provide many useful built-in functions for inserting, deleting, and accessing elements.

### Common Functions

| Function | Purpose |
|----------|---------|
| `push_back(x)` | Adds an element at the end. |
| `pop_back()` | Removes the last element. |
| `front()` | Returns the first element. |
| `back()` | Returns the last element. |
| `at(index)` | Returns the element at the given index safely. |
| `size()` | Returns the number of elements. |

### Example

```cpp
vector<int> arr;

arr.push_back(24);
arr.push_back(80);
arr.push_back(30);

arr.pop_back();
```

Now the vector contains:

```text
24 80
```

### Access Elements

```cpp
cout << arr.front();      // 24
cout << arr.back();       // 80
cout << arr.at(1);        // 80
```

### Traverse Vector

```cpp
for (int value : arr)
{
    cout << value << " ";
}
```

### Output

```text
24 80
```

### 📌 Key Learning

- `push_back()` inserts elements at the end.
- `pop_back()` removes only the last element.
- `front()` accesses the first element.
- `back()` accesses the last element.
- `at()` is safer than `[]` because it checks the index range.

---

## 📏 4. Vector Size and Capacity

Vectors have **two important properties**: **Size** and **Capacity**.

### Size

The number of elements currently stored inside the vector.

### Capacity

The total memory allocated to store elements before resizing is required.

### Example

```cpp
vector<int> num;

num.push_back(1);
num.push_back(2);
num.push_back(3);
num.push_back(4);
num.push_back(5);
num.push_back(6);

cout << "Size: " << num.size() << endl;
cout << "Capacity: " << num.capacity() << endl;
```

### Example Output

```text
Size of Vector is: 6
Capacity of Vector is: 8
```

### Difference Between Size and Capacity

| Property | Meaning |
|----------|---------|
| `size()` | Number of elements present in the vector. |
| `capacity()` | Total storage allocated by the vector. |

### 📌 Key Learning

- Capacity increases automatically when the vector becomes full.
- Capacity is managed internally for efficient insertions.

---

## 🔍 5. Linear Search in Vector

Linear Search checks every element one by one until the target element is found.

### Algorithm

1. Traverse the vector.
2. Compare each element with the key.
3. If matched, print the index.
4. If traversal finishes without a match, print **Element not found**.

### Example

```cpp
for (int i = 0; i < n; i++)
{
    if (arr[i] == key)
    {
        cout << "Element found at index " << i;
        break;
    }
}

if (i == n)
{
    cout << "Element is not present in the array.";
}
```

### Output Example

```text
Enter the value of key: 40
Element found at index 3
```

### If Element is Not Present

```text
Enter the value of key: 25
Element is not present in the array.
```

### 📌 Key Learning

- Search starts from index `0`.
- `break` stops unnecessary comparisons after finding the element.
- `i == n` means the element was not found.

**Time Complexity:** `O(n)`

**Space Complexity:** `O(1)`

---

## 🔄 6. Reverse a Vector using `swap()`

Vectors can be reversed efficiently using the **Two Pointer Technique**.

### Strategy

- `start = 0`
- `end = size - 1`
- Swap elements.
- Move pointers toward the center.

### Reverse Function (Pass by Reference)

```cpp
void reverse(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
```

### Example Output

```text
Original Array is: 1 2 3 4 5
Reversed Array is: 5 4 3 2 1
```

### 📌 Key Learning

- `&arr` passes the original vector by reference.
- `swap()` exchanges the first and last elements.
- The vector is reversed **in-place** without creating another vector.

**Time Complexity:** `O(n)`

**Space Complexity:** `O(1)`

---

# 💻 Language Used

- **C++**

### Concepts Used

- Vectors (STL)
- Dynamic Arrays
- For-Each Loop
- `push_back()`
- `pop_back()`
- `front()`
- `back()`
- `at()`
- `size()`
- `capacity()`
- Linear Search
- Pass by Reference
- Two Pointer Technique
- `swap()`

---

## 📂 Folder Structure

```text
06-Vector/
│── output/
│── 01.InitialisationOfVector.cpp
│── 02.ForEachLoop.cpp
│── 03.VectorFunction.cpp
│── 04.SizeAndCapacity.cpp
│── 05.LinearSearch.cpp
│── 06.Reverse.cpp
└── README.md
```

---

# 📝 Vector Operations Summary

| Operation | Time Complexity |
|-----------|-----------------|
| Access Element (`[]`, `at()`) | `O(1)` |
| Traverse Vector | `O(n)` |
| `push_back()` | `O(1)` *(Average)* |
| `pop_back()` | `O(1)` |
| `front()` / `back()` | `O(1)` |
| `size()` | `O(1)` |
| `capacity()` | `O(1)` |
| Linear Search | `O(n)` |
| Reverse Vector | `O(n)` |

---

## 🌱 What This Chapter Builds

By completing these programs, I strengthened my understanding of:

- Creating vectors in different ways.
- Initializing vectors with default values.
- Traversing vectors using the **For-Each Loop**.
- Using built-in vector functions like `push_back()`, `pop_back()`, `front()`, `back()`, and `at()`.
- Understanding the difference between **Size** and **Capacity**.
- Searching elements using **Linear Search**.
- Reversing vectors using the **Two Pointer Technique** with `swap()`.
- Passing vectors to functions using **Pass by Reference**.

This chapter builds the foundation for upcoming DSA topics like **Strings, 2D Vectors, Binary Search, Sorting Algorithms, Sliding Window, and STL Containers**.

---

# 📖 Key Takeaways

- Vectors are **dynamic arrays** that resize automatically.
- Vector indexing starts from **0**.
- `push_back()` inserts elements at the end, while `pop_back()` removes the last element.
- `front()` and `back()` provide access to the first and last elements.
- `size()` returns the number of elements, while `capacity()` returns allocated storage.
- The **For-Each Loop** is the easiest way to traverse a vector.
- **Linear Search** checks each element one by one and returns its index if found.
- The **Two Pointer Technique** with `swap()` reverses a vector efficiently in-place.
- Passing a vector **by reference (`&`)** modifies the original vector without creating a copy.

---

> **"Vectors combine the simplicity of arrays with the flexibility of dynamic memory, making them one of the most powerful STL containers in C++ for DSA and coding interviews."** 🚀🌸
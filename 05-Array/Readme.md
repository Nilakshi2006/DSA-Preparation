# 🚀 DSA Journey – Chapter 5: Arrays (C++)

Welcome to **Chapter 5** of my **Data Structures & Algorithms (DSA)** journey! 📦✨

After learning **Functions** and **Bitwise Operators**, I started exploring one of the most important topics in DSA — **Arrays**.

This chapter covers the fundamentals of arrays in C++, including **array input/output, searching, reversing, finding largest and smallest elements, swapping values, sum and product, pass by reference, unique elements using frequency arrays, and intersection of two arrays**.

Arrays are the foundation of DSA because many advanced topics like **Sorting, Binary Search, Strings, 2D Arrays, Vectors, and Dynamic Programming** build upon them.

---

## 📚 Programs Covered

| # | File Name | Concept |
|---|-----------|---------|
| 01 | `01.OutinArr.cpp` | Output (Print) Elements of an Array. |
| 02 | `02.InpinArr.cpp` | Input Elements into an Array from the User. |
| 03 | `03.SmallestNo.UsingLoop.cpp` | Find the Smallest Element in an Array. |
| 04 | `04.LargestNo.usingLoop.cpp` | Find the Largest Element in an Array. |
| 05 | `05.SizeofArr.cpp` | Find the Size of an Array using `sizeof()`. |
| 06 | `06.PassbyReference.cpp` | Arrays Passed to Functions by Reference. |
| 07 | `07.LinearSearch.cpp` | Linear Search Using Function (Returns Index). |
| 08 | `08.ReverseAnArray.cpp` | Reverse an Array using `swap()`. |
| 09 | `09.SumandProductofArrElem.cpp` | Find Sum and Product of Array Elements. |
| 10 | `10.SwapMaxAndMinElemOfArr.cpp` | Swap Maximum and Minimum Elements in an Array. |
| 11 | `11.UniqueValueInArr.cpp` | Find the Unique Element using Frequency Array. |
| 12 | `12.IntersectionOf2Array.cpp` | Find Common Elements (Intersection) of Two Arrays. |

---

# 🎯 Concepts I Learned

This chapter introduced me to the basics of **array traversal, searching, comparison, swapping, and frequency counting**.

---

## 📥 1. Array Input and Output

Arrays store multiple values of the **same data type** in contiguous memory locations.

### 🖨️ Output an Array

```cpp
int arr[] = {10, 20, 30, 40, 50};

for (int i = 0; i < 5; i++)
{
    cout << arr[i] << endl;
}
```

### ⌨️ Input an Array

```cpp
int arr[5];

for (int i = 0; i < 5; i++)
{
    cin >> arr[i];
}
```

### 📌 Key Learning

- Arrays are indexed from **0**.
- Use loops to access every element.
- Input and output operations both require array traversal.

---

## 🔍 2. Find the Smallest Element in an Array

### Strategy

1. Assume the first element is the smallest.
2. Traverse the array.
3. Update the smallest value whenever a smaller element is found.

```cpp
int small = arr[0];

for (int i = 0; i < size; i++)
{
    if (arr[i] < small)
    {
        small = arr[i];
    }
}
```

### Example

```text
Array : 8 5 2 9 4
Smallest = 2
```

**Time Complexity:** `O(n)`

---

## 🔺 3. Find the Largest Element in an Array

### Strategy

1. Assume the first element is the largest.
2. Compare every element with it.
3. Update whenever a larger element appears.

```cpp
int largest = arr[0];

for (int i = 0; i < n; i++)
{
    if (arr[i] > largest)
    {
        largest = arr[i];
    }
}
```

### Example

```text
Array : 8 5 2 9 4
Largest = 9
```

**Time Complexity:** `O(n)`

---

## 📏 4. Find the Size of an Array using `sizeof()`

The `sizeof()` operator returns the memory occupied by an array.

```cpp
int arr[] = {1,2,3,4,5};

int size = sizeof(arr) / sizeof(arr[0]);
```

### Formula

```text
Number of Elements = sizeof(arr) / sizeof(arr[0])
```

### Example

```text
Array Memory = 20 Bytes
One Integer = 4 Bytes

Size = 20 / 4 = 5
```

### 📌 Key Learning

- Works for **static arrays**.
- No need to manually count elements.

---

## 🔄 5. Pass Array by Reference

Arrays are passed **by reference** in C++.

### Example

```cpp
void change(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i] * 2;
    }
}
```

### Output

```text
Original Array : 1 2 3
Modified Array : 2 4 6
```

### 📌 Key Learning

- The original array changes after calling the function.
- Arrays are **not copied** when passed to functions.

---

## 🔎 6. Linear Search

Linear Search checks every element one by one until the target is found.

### Algorithm

1. Traverse the array.
2. Compare each element with the target.
3. Return the index if found.
4. Return `-1` if not found.

```cpp
int linear(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}
```

### Example

```text
Array  : 4 2 7 8 1 2 5
Target : 8

Output : Index = 3
```

### 📌 Key Learning

- Returns the **index** of the target.
- `-1` means the element is not present.

**Time Complexity:** `O(n)`

---

## 🔁 7. Reverse an Array using `swap()`

Reverse an array using the **Two Pointer Technique**.

### Strategy

- `start = 0`
- `end = size - 1`
- Swap both elements.
- Move pointers inward.

```cpp
while (start < end)
{
    swap(arr[start], arr[end]);
    start++;
    end--;
}
```

### Example

```text
Before : 4 2 7 8 1 2 5

After  : 5 2 1 8 7 2 4
```

### 📌 Key Learning

- Efficient in-place reversal.
- Uses `swap()` from C++.

**Time Complexity:** `O(n)`

**Space Complexity:** `O(1)`

---

## ➕ 8. Sum and Product of Array Elements

### Strategy

- Initialize `sum = 0`.
- Initialize `product = 1`.
- Traverse the array once.

```cpp
sum += arr[i];
product *= arr[i];
```

### Example

```text
Array : 1 2 3 4 5

Sum = 15
Product = 120
```

### 📌 Key Learning

| Operation | Initial Value |
|-----------|---------------|
| Sum | `0` |
| Product | `1` |

**Time Complexity:** `O(n)`

---

## 🔀 9. Swap Maximum and Minimum Elements

### Strategy

1. Find the index of the smallest element.
2. Find the index of the largest element.
3. Swap both indices.

```cpp
swap(arr[minIndex], arr[maxIndex]);
```

### Example

```text
Before : 9 3 4 5 2 6

After  : 2 3 4 5 9 6
```

### 📌 Key Learning

- Store **indices**, not values.
- Swapping values alone does **not** change the array.

**Time Complexity:** `O(n)`

---

## ⭐ 10. Find Unique Element using Frequency Array

A **frequency array** stores how many times each number appears.

### Strategy

**Step 1 — Count Frequency**

```cpp
freq[arr[i]]++;
```

**Step 2 — Find Frequency = 1**

```cpp
if (freq[arr[i]] == 1)
{
    cout << arr[i];
}
```

### Example

```text
Array : 2 3 4 3 2

Frequency

2 → 2 times
3 → 2 times
4 → 1 time

Unique Element = 4
```

### 📌 Key Learning

- `freq[value]` stores the occurrence count.
- Works when array values are within the frequency array range.

**Time Complexity:** `O(n)`

**Space Complexity:** `O(max value)`

---

## 🤝 11. Intersection of Two Arrays

Intersection means elements present in **both arrays**.

### Strategy (Nested Loops)

1. Pick one element from the first array.
2. Compare it with every element of the second array.
3. If equal, print it.
4. Use `break` after the first match.

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            break;
        }
    }
}
```

### Example

```text
Array 1 : 2 4 6
Array 2 : 1 2 3 4 5 6 7 8

Intersection : 2 4 6
```

### 🧠 How Comparison Works

For each value in **Array 1**, compare it with **every value** in **Array 2**.

| Array 1 Element | Compared with Array 2 |
|-----------------|-----------------------|
| `2` | `1 → 2 ✅` |
| `4` | `1 → 2 → 3 → 4 ✅` |
| `6` | `1 → 2 → 3 → 4 → 5 → 6 ✅` |

### 📌 Key Learning

- Outer loop picks one element.
- Inner loop checks all elements of the second array.
- `break` avoids unnecessary comparisons after a match.

**Time Complexity:** `O(n × m)`

---

# 💻 Language Used

- **C++**

### Concepts Used

- Arrays
- Array Traversal
- `for` Loops
- `if` Conditions
- `sizeof()`
- Functions
- Pass by Reference
- `swap()`
- Linear Search
- Frequency Array
- Nested Loops

---

## 📂 Folder Structure

```text
05-Array/
│── output/
│── 01.OutinArr.cpp
│── 02.InpinArr.cpp
│── 03.SmallestNo.UsingLoop.cpp
│── 04.LargestNo.usingLoop.cpp
│── 05.SizeofArr.cpp
│── 06.PassbyReference.cpp
│── 07.LinearSearch.cpp
│── 08.ReverseAnArray.cpp
│── 09.SumandProductofArrElem.cpp
│── 10.SwapMaxAndMinElemOfArr.cpp
│── 11.UniqueValueInArr.cpp
│── 12.IntersectionOf2Array.cpp
└── README.md
```

---

# 📝 Array Operations Summary

| Operation | Time Complexity |
|-----------|-----------------|
| Traverse / Print Array | `O(n)` |
| Input Array | `O(n)` |
| Find Smallest Element | `O(n)` |
| Find Largest Element | `O(n)` |
| Linear Search | `O(n)` |
| Reverse Array | `O(n)` |
| Sum of Elements | `O(n)` |
| Product of Elements | `O(n)` |
| Swap Min & Max Elements | `O(n)` |
| Unique Element (Frequency Array) | `O(n)` |
| Intersection of Two Arrays | `O(n × m)` |

---

## 🌱 What This Chapter Builds

By completing these programs, I strengthened my understanding of:

- Creating and traversing arrays.
- Taking input and printing array elements.
- Finding smallest and largest values efficiently.
- Calculating array size using `sizeof()`.
- Passing arrays to functions by reference.
- Searching elements using Linear Search.
- Reversing arrays using the Two Pointer technique.
- Computing sum and product of array elements.
- Swapping minimum and maximum elements.
- Finding unique elements using frequency counting.
- Comparing two arrays to find their intersection.

This chapter builds the foundation for upcoming DSA topics like **Sorting Algorithms, Binary Search, Strings, 2D Arrays, Vectors, and Hashing**.

---

# 📖 Key Takeaways

- Arrays store multiple values of the **same data type** in contiguous memory.
- Array indexing starts from **0**.
- `sizeof(arr) / sizeof(arr[0])` gives the number of elements in a static array.
- Arrays are passed **by reference** to functions in C++.
- Linear Search checks elements one by one and returns the index of the target.
- The **Two Pointer Technique** is an efficient way to reverse an array.
- Use `sum = 0` and `product = 1` while calculating sum and product.
- Store **indices** while swapping minimum and maximum elements.
- Frequency arrays help count occurrences and find unique elements.
- Intersection compares **each element of the first array with every element of the second array** using nested loops.

---

> *"Arrays are the building blocks of DSA. Mastering traversal, searching, swapping, and basic array manipulation makes advanced algorithms much easier to understand."* 🚀🌸
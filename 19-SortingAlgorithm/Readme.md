# 🚀 DSA Journey — Chapter 19: Sorting Algorithms (C++)

Chapter 19 of my Data Structures & Algorithms journey. 💻

I implemented three basic **O(n²) sorting algorithms**: Bubble Sort, Selection Sort and Insertion Sort. Each one is written for both **ascending** and **descending** order.

---

## 📂 Programs Covered

| #  | File Name              | Concept                                  |
| -- | ---------------------- | ---------------------------------------- |
| 01 | `01.BubbleSort.cpp`    | Swap adjacent elements, largest bubbles up |
| 02 | `02.SelectionSort.cpp` | Pick the smallest, place it at the front |
| 03 | `03.InsertionSort.cpp` | Insert each element into the sorted part |

## 📁 Folder Structure

```text
19-SortingAlgorithm/

│── output/
│── 01.BubbleSort.cpp
│── 02.SelectionSort.cpp
│── 03.InsertionSort.cpp

└── README.md
```

---

## 💻 Concepts Used

Arrays, Loops, Nested Loops, Functions, Swapping, Sorting, Time and Space Complexity.

---

## 🫧 1. Bubble Sort

Compare adjacent elements and swap them if they are in the wrong order. After each pass, the largest element reaches its final position at the end.

```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool isSwap = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {      // use < for descending
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        if (!isSwap) return;                // already sorted
    }
}
```

**Optimization:** if a full pass makes no swap, the array is already sorted, so we stop early.

### 🔍 Dry Run (`{4, 1, 5, 3, 2}`)

```text
Pass 1: 1 4 3 2 5
Pass 2: 1 3 2 4 5
Pass 3: 1 2 3 4 5
Pass 4: no swaps → stop
```

---

## 🎯 2. Selection Sort

Find the smallest element in the unsorted part and swap it into the first unsorted position.

```cpp
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int smallestIdx = i;                // start of unsorted part

        for (int j = i + 1; j < n; j++) {
            if (arr[j] <= arr[smallestIdx]) {   // use >= for descending
                smallestIdx = j;
            }
        }

        swap(arr[i], arr[smallestIdx]);
    }
}
```

### 🔍 Dry Run (`{4, 1, 5, 3, 2}`)

```text
i = 0: smallest = 1 → 1 4 5 3 2
i = 1: smallest = 2 → 1 2 5 3 4
i = 2: smallest = 3 → 1 2 3 5 4
i = 3: smallest = 4 → 1 2 3 4 5
```

---

## 🃏 3. Insertion Sort

Take one element at a time and insert it into its correct position in the already sorted left part (like sorting playing cards in hand).

```cpp
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] > curr) {   // use < for descending
            arr[prev + 1] = arr[prev];            // shift right
            prev--;
        }

        arr[prev + 1] = curr;                     // place curr
    }
}
```

### 🔍 Dry Run (`{4, 1, 5, 3, 2}`)

```text
i = 1: curr = 1 → 1 4 5 3 2
i = 2: curr = 5 → 1 4 5 3 2   (no shift)
i = 3: curr = 3 → 1 3 4 5 2
i = 4: curr = 2 → 1 2 3 4 5
```

---

## 🔁 Ascending vs Descending

Only the comparison changes. The logic stays the same.

| Algorithm | Ascending         | Descending         |
| --------- | ----------------- | ------------------ |
| Bubble    | `arr[j] > arr[j+1]` | `arr[j] < arr[j+1]` |
| Selection | `arr[j] <= arr[smallestIdx]` | `arr[j] >= arr[smallestIdx]` |
| Insertion | `arr[prev] > curr` | `arr[prev] < curr` |

---

## 🧪 Output

For:

```text
arr = {4, 1, 5, 3, 2}
```

Ascending:

```text
1 2 3 4 5
```

Descending:

```text
5 4 3 2 1
```

---

## 📈 Complexity

| Algorithm | Best           | Average / Worst | Space  | Stable? |
| --------- | -------------- | --------------- | ------ | ------- |
| Bubble    | `O(n)`*        | `O(n²)`         | `O(1)` | Yes     |
| Selection | `O(n²)`        | `O(n²)`         | `O(1)` | No      |
| Insertion | `O(n)`         | `O(n²)`         | `O(1)` | Yes     |

\* Best case for Bubble Sort needs the `isSwap` optimization.

---

## 🆚 Quick Comparison

| Feature            | Bubble             | Selection            | Insertion               |
| ------------------ | ------------------ | -------------------- | ----------------------- |
| Idea               | Swap neighbours    | Pick the minimum     | Insert into sorted part |
| Swaps              | Many               | At most `n - 1`      | Shifts instead of swaps |
| Already sorted     | Fast (optimized)   | Still `O(n²)`        | Fast                    |
| Best for           | Learning           | Fewest swaps         | Small / nearly sorted data |

---

## ⚠️ Common Mistakes

| Mistake                                   | Correct Approach                          |
| ----------------------------------------- | ----------------------------------------- |
| Inner loop up to `n - 1` in Bubble Sort   | Use `n - i - 1`                           |
| Forgetting the `isSwap` check             | Add it for early exit                     |
| Starting Insertion Sort from `i = 0`      | Start from `i = 1`                        |
| Not placing `curr` after the shifting loop | `arr[prev + 1] = curr`                   |
| Flipping only one comparison for descending | Flip the comparison in the right place   |

---

## 🎓 Interview Tip

Be ready to explain:

* How each algorithm works, with a dry run
* Why Bubble Sort is optimized with `isSwap`
* Why Selection Sort is not stable
* Why Insertion Sort is fast on nearly sorted data
* Time and space complexity of all three

A simple explanation:

> "Bubble Sort pushes the largest element to the end by swapping neighbours. Selection Sort picks the smallest element and places it at the front. Insertion Sort inserts each element into its correct place in the sorted part. All three are `O(n²)` and use `O(1)` extra space."

---

## 🌱 What This Chapter Builds

Sorting Fundamentals, Nested Loops, Swapping, In-place Algorithms, Stability, Time Complexity Analysis.

> **"Master the simple sorts first. Faster ones build on the same ideas."** 💻
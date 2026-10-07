# 🚀 DSA Journey — Chapter 23: STL (C++)

Chapter 23 of my Data Structures & Algorithms journey. 💻

The **Standard Template Library** gives ready-made containers, iterators, and algorithms. This chapter covers the ones used most in problem solving and interviews, one runnable program per topic.

---

## 📂 Programs Covered

| #  | File Name                  | Concept                                              |
| -- | -------------------------- | ---------------------------------------------------- |
| 01 | `01.Vector.cpp`            | Dynamic array: push, pop, insert, erase, access      |
| 02 | `02.Iterator.cpp`          | `begin()`, `end()`, forward and reverse traversal    |
| 03 | `03.List.cpp`              | Doubly linked list: front/back operations            |
| 04 | `04.Deque.cpp`             | Double-ended queue with random access                |
| 05 | `05.Pair.cpp`              | `pair`, nested pairs, vector of pairs                |
| 06 | `06.Stack.cpp`             | LIFO: push, pop, top, swap                           |
| 07 | `07.Queue.cpp`             | FIFO: push, pop, front, back, swap                   |
| 08 | `08.PriorityQueue.cpp`     | Max heap, min heap, swap                             |
| 09 | `09.Map.cpp`               | `map`, `multimap`, `unordered_map`                   |
| 10 | `10.Set.cpp`               | Sorted unique set, `lower_bound`, `upper_bound`      |
| 11 | `11.SortingTechniques.cpp` | `sort()` on arrays and vectors, comparator, `greater<>` |
| 12 | `12.CustomComparitor.cpp`  | Sort pairs by second value, STL algorithm functions  |

## 📁 Folder Structure

```text
23-STL/

│── output/
│── 01.Vector.cpp
│── 02.Iterator.cpp
│── 03.List.cpp
│── 04.Deque.cpp
│── 05.Pair.cpp
│── 06.Stack.cpp
│── 07.Queue.cpp
│── 08.PriorityQueue.cpp
│── 09.Map.cpp
│── 10.Set.cpp
│── 11.SortingTechniques.cpp
│── 12.CustomComparitor.cpp

└── README.md
```

---

## 💻 Concepts Used

Containers, Iterators, Pairs, Heaps, Hashing, Lambda Functions, Comparators, Bit Manipulation, Time and Space Complexity.

---

## 📦 Program Breakdown

### 01. Vector

A resizable array stored in contiguous memory.

| Function              | What it does                                   |
| --------------------- | ---------------------------------------------- |
| `push_back(x)`        | Add at the end                                 |
| `emplace_back(x)`     | Same, but constructs the element in place      |
| `pop_back()`          | Remove the last element                        |
| `arr[i]` / `at(i)`    | Access by index; `at()` throws if out of range |
| `front()` / `back()`  | First and last element                         |
| `insert(pos, x)`      | Insert at a position, `O(n)`                   |
| `erase(pos)`          | Remove at a position, `O(n)`                   |
| `clear()`             | Remove everything                              |
| `empty()`             | `1` if empty, `0` if not                       |

```text
Output:
0
Element at index 3 is: 4
Element at index 2 is: 3
front element is: 1
Back Element is: 5
check if arr is empty: 0
Arr Element: 1 2 3 4 5
```

### 02. Iterator

An iterator is a pointer-like object that walks through a container.

* `begin()` points to the first element.
* `end()` points **one past** the last element. It is a stopping marker, so dereferencing it is undefined behavior.
* `rbegin()` and `rend()` walk the container backward.

```cpp
for (auto it = arr.begin(); it != arr.end(); it++)       // forward
    cout << *it << " ";

for (auto it = arr.rbegin(); it != arr.rend(); it++)     // backward
    cout << *it << " ";
```

```text
Output:
First Element: 1
1 2 3 4 5
5 4 3 2 1
```

### 03. List

A doubly linked list. Insert and erase at a known position are `O(1)`, but there is no random access.

```text
push_front(10), push_back(20), emplace_front(5), emplace_back(30)
List: 5 10 20 30
After pop_front and pop_back: 10 20
```

### 04. Deque

Double-ended queue. Fast insert and delete at both ends, plus `[]` access.

```text
push_front(10), push_back(20), emplace_front(5), emplace_back(30)
Deque: 5 10 20 30
After pop_front and pop_back: 10 20
dq[1] = 20
```

### 05. Pair

Holds two values together. Used everywhere: graph edges, coordinates, `(value, index)`.

```cpp
pair<int, int> p = {10, 20};                    // p.first, p.second
pair<int, pair<int, int>> p2 = {1, {2, 3}};     // p2.second.first
vector<pair<int, int>> v;                       // vector of pairs
v.push_back({10, 20});
v.emplace_back(50, 60);                         // no braces needed
```

### 06. Stack (LIFO)

| Function  | Use                    |
| --------- | ---------------------- |
| `push()`  | Add on top             |
| `top()`   | Read the top           |
| `pop()`   | Remove the top         |
| `size()`  | Number of elements     |
| `swap()`  | Swap with another stack |

```text
Pushed 10 20 30 40 → top = 40, size = 4
After pop → top = 30
After swap with {100, 200} → top = 200
```

### 07. Queue (FIFO)

Same functions as stack, but with `front()` and `back()` instead of `top()`.

```text
Pushed 10 20 30 40 → front = 10, back = 40, size = 4
After pop → front = 20
After swap with {100, 200} → front = 100
```

### 08. Priority Queue

A heap. `top()` always returns the highest-priority element.

```cpp
priority_queue<int> maxHeap;                                  // default: max heap
priority_queue<int, vector<int>, greater<int>> minHeap;       // min heap
```

```text
Max heap {10, 30, 20, 40} → top = 40, after pop = 30
Min heap {10, 30, 20, 5}  → top = 5,  after pop = 10
After swap with {100, 200} → max heap top = 200
```

### 09. Map, Multimap, Unordered Map

| Container       | Order         | Duplicate keys | Internals  |
| --------------- | ------------- | -------------- | ---------- |
| `map`           | Sorted by key | No             | Red-black tree |
| `multimap`      | Sorted by key | Yes            | Red-black tree |
| `unordered_map` | None          | No             | Hash table |

Functions covered: `insert`, `emplace`, `count`, `find`, `erase`, `size`, `empty`.

```text
map: 1 -> Apple, 2 -> Banana, 3 -> Mango, 4 -> Orange
After erase(2): key 2 is gone, size = 3
multimap: key 2 holds Banana, Mango, and Grapes; count(2) = 3
```

`unordered_map` prints in no guaranteed order, so don't rely on it.

### 10. Set

Sorted, unique elements.

```text
Inserted 10 20 30 40 (20 again is ignored), emplace 50
Set: 10 20 30 40 50
count(20) = 1
lower_bound(25) → 30   (first element >= 25)
upper_bound(30) → 40   (first element >  30)
After erase(20): 10 30 40 50
```

### 11. Sorting Techniques

```cpp
sort(arr, arr + n);                           // array, ascending
sort(v.begin(), v.end());                     // vector, ascending
sort(arr, arr + n, comp);                     // custom comparator
sort(v.begin(), v.end(), greater<int>());     // descending
```

A comparator returns `true` when `a` should come **before** `b`.

### 12. Custom Comparator and Algorithm Functions

By default, pairs sort by `first`, then by `second` if `first` ties. To sort by `second`:

```cpp
sort(v.begin(), v.end(),
    [](pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    });
```

| Function                  | Purpose                                  |
| ------------------------- | ---------------------------------------- |
| `reverse()`               | Reverse a range                          |
| `next_permutation()`      | Next lexicographic order (see Chapter 22) |
| `max()` / `min()`         | Larger / smaller of two values           |
| `max_element()` / `min_element()` | Iterator to the largest / smallest |
| `swap()`                  | Swap two values                          |
| `binary_search()`         | Check existence in a **sorted** range    |
| `count()`                 | Occurrences of a value                   |
| `__builtin_popcount()`    | Set bits in an `int`                     |
| `__builtin_popcountll()`  | Set bits in a `long long`                |

`__builtin_popcount(13)` returns `3`, since `13` is `1101`.

---

## ⚡ Containers at a Glance

| Container        | Ordered       | Duplicates | Access            |
| ---------------- | ------------- | ---------- | ----------------- |
| `vector`         | By index      | Yes        | Random            |
| `list`           | By insertion  | Yes        | Sequential only   |
| `deque`          | By index      | Yes        | Random            |
| `stack`          | LIFO          | Yes        | Top only          |
| `queue`          | FIFO          | Yes        | Front and back    |
| `priority_queue` | By priority   | Yes        | Top only          |
| `set`            | Sorted        | No         | By value          |
| `map`            | Sorted by key | No (keys)  | By key            |
| `multimap`       | Sorted by key | Yes        | By key            |
| `unordered_map`  | None          | No (keys)  | By key            |

---

## 📈 Complexity

| Operation                               | Time                         |
| --------------------------------------- | ---------------------------- |
| `vector` `push_back`                    | `O(1)` amortized             |
| `vector` `insert` / `erase` in middle   | `O(n)`                       |
| `list` insert / erase at known position | `O(1)`                       |
| `deque` push / pop at either end        | `O(1)`                       |
| `stack` / `queue` operations            | `O(1)`                       |
| `priority_queue` `push` / `pop`         | `O(log n)`                   |
| `priority_queue` `top`                  | `O(1)`                       |
| `set` / `map` insert, find, erase       | `O(log n)`                   |
| `unordered_map` insert, find, erase     | `O(1)` average, `O(n)` worst |
| `sort`                                  | `O(n log n)`                 |
| `binary_search`                         | `O(log n)`                   |
| `max_element` / `min_element` / `count` | `O(n)`                       |

---

## 🧭 Which Container Should I Use?

| I need...                               | Use              |
| --------------------------------------- | ---------------- |
| Fast index access, general purpose      | `vector`         |
| Fast insert/delete at both ends         | `deque`          |
| Frequent insert/delete in the middle    | `list`           |
| Undo, brackets, DFS                     | `stack`          |
| BFS, order of arrival                   | `queue`          |
| Repeated min or max                     | `priority_queue` |
| Sorted unique values, range queries     | `set`            |
| Key-value lookup in sorted order        | `map`            |
| Fastest key-value lookup, order not needed | `unordered_map` |

---

## ⚠️ Common Mistakes

| Mistake                                            | Correct Approach                                             |
| -------------------------------------------------- | ------------------------------------------------------------ |
| Dereferencing `end()`                              | `end()` is past the last element, so it is undefined behavior |
| Using `begin()` to `end()` for backward traversal  | Use `rbegin()` to `rend()`                                   |
| Indexing a `deque` or `vector` out of range        | Check `size()` first; `at()` throws instead of failing silently |
| Calling `top()` or `front()` on an empty container | Check `empty()` first                                        |
| Expecting `priority_queue` to be a min heap        | Default is max heap; use `greater<int>` for min heap         |
| Expecting `unordered_map` to be ordered            | Use `map` if order matters                                   |
| Using `binary_search` on an unsorted range         | Sort first                                                   |
| Using `set` when duplicates are needed             | Use `multiset` or `multimap`                                 |
| Erasing while iterating without updating the iterator | Use `it = c.erase(it)`                                    |
| Comparator returning `<=`                          | Use strict `<` or `>`, or `sort` can crash                   |

---

## 🎓 Interview Tip

Be ready to explain:

* Why `vector` `push_back` is amortized `O(1)`
* `vector` vs `list` vs `deque`: when to use each
* `map` vs `unordered_map`: tree vs hash table, and the complexity difference
* How `priority_queue` works internally (binary heap)
* How a custom comparator controls sort order
* What `lower_bound` and `upper_bound` return
* Why `end()` cannot be dereferenced

A simple explanation:

> "I pick the container by the operation I need most: `vector` for index access, `deque` for both ends, `set` or `map` for sorted lookup in `O(log n)`, `unordered_map` for average `O(1)` lookup, and `priority_queue` for repeated min or max."

---

## 🌱 What This Chapter Builds

STL Fluency, Container Selection, Iterator Usage, Comparator Writing, Faster Problem Solving.

> **"Pick the right container, and half the problem is solved."** 💻
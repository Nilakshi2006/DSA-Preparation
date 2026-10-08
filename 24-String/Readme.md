# 🚀 DSA Journey — Chapter 24: Strings (C++)

Chapter 24 of my Data Structures & Algorithms journey. 💻

Topic: working with strings in C++ using **character arrays** (C-style) and the **`string` class**, plus reversing a string both ways.

---

## 📂 Programs Covered

| #  | File Name              | Concept                                          |
| -- | ---------------------- | ------------------------------------------------ |
| 01 | `01.CharArr.cpp`       | Character array basics and `<cstring>` functions |
| 02 | `02.String.cpp`        | `string` class operations                        |
| 03 | `03.RevInCharArr.cpp`  | Reverse a char array using two pointers          |
| 04 | `04.RevInAtr.cpp`      | Reverse a string using `reverse()`               |

## 📁 Folder Structure

```text
24-String/

│── output/
│── 01.CharArr.cpp
│── 02.String.cpp
│── 03.RevInCharArr.cpp
│── 04.RevInAtr.cpp

└── README.md
```

---

## 💻 Concepts Used

Character Arrays, Null Terminator, `string` Class, Input Handling, Loops, Two Pointers, Swapping, STL `reverse()`.

---

## 🔤 Character Array

A char array is a string stored as characters ending with the null terminator `'\0'`.

```cpp
char name[] = "Nilakshi";
char city[20] = {'D', 'e', 'l', 'h', 'i', '\0'};
```

| Operation          | Code                          |
| ------------------ | ----------------------------- |
| Input (no spaces)  | `cin >> arr;`                 |
| Input (with spaces)| `cin.getline(arr, 100);`      |
| Length             | `strlen(arr)`                 |
| Compare            | `strcmp(str1, str2) == 0`     |
| Copy               | `strcpy(str3, str1)`          |
| Concatenate        | `strcat(a, b)`                |

Loop until the null terminator:

```cpp
for(int i = 0; arr[i] != '\0'; i++) {
    cout << arr[i] << " ";
}
```

---

## 🧵 String Class

`string` manages its own size and supports operators directly.

| Operation        | Code                                |
| ---------------- | ----------------------------------- |
| Initialize       | `string s = "Hello";` / `string s("World");` |
| Input (no spaces)| `cin >> name;`                      |
| Input (with spaces) | `getline(cin, name);`            |
| Length           | `name.length()` / `name.size()`     |
| Access           | `name[0]`, `front()`, `back()`      |
| Concatenate      | `first + " " + second`              |
| Append           | `first += " C++";`                  |
| Compare          | `a == b`, `a != b`                  |
| Add / remove last| `push_back('!')` / `pop_back()`     |
| Substring        | `text.substr(0, 4)`                 |
| Find             | `text.find("gram")`                 |

Two ways to loop:

```cpp
for(int i = 0; i < name.length(); i++) cout << name[i] << " ";

for(char ch : name) cout << ch << " ";
```

---

## ⚡ Reverse a String

### Approach 1: Char Array (Two Pointers)

Place one pointer at each end, swap, and move inward until they meet.

```cpp
char ch[] = "Nilakshi";
int n = strlen(ch);
int start = 0, end = n - 1;

while (start < end) {
    swap(ch[start], ch[end]);
    start++;
    end--;
}
```

### Approach 2: STL

```cpp
string s = "Nilakshi";
reverse(s.begin(), s.end());
```

### 🔍 Dry Run (`"Nilakshi"`)

```text
N i l a k s h i
0 1 2 3 4 5 6 7

start = 0, end = 7  → swap N and i  → i i l a k s h N
start = 1, end = 6  → swap i and h  → i h l a k s i N
start = 2, end = 5  → swap l and s  → i h s a k l i N
start = 3, end = 4  → swap a and k  → i h s k a l i N
start = 4, end = 3  → stop

Result: ihskalin
```

---

## 🧪 Output

**01.CharArr.cpp**

```text
Enter your name: Nilakshi
Name: Nilakshi
Enter your full name: Nilakshi Dev
Full name: Nilakshi Dev
Length: 13
Characters: N i l a k s h i   D e v 
First character: N
Both strings are same
Copied string: Hello
After concatenation: Hello World
```

**02.String.cpp**

```text
Hello
C++
World
...
Combined: Hello World
After += : Hello C++
Both strings are same
Strings are different
After push_back: Hello!
After pop_back: Hello
First: H
Last: o
Substring: Prog
Position of 'gram': 3
```

**03.RevInCharArr.cpp** and **04.RevInAtr.cpp**

```text
ihskalin
```

---

## 📈 Complexity

| Operation                     | Time       | Space  |
| ----------------------------- | ---------- | ------ |
| `strlen`, `strcmp`, `strcpy`  | `O(n)`     | `O(1)` |
| Reverse (two pointers)        | `O(n)`     | `O(1)` |
| Reverse (`reverse()`)         | `O(n)`     | `O(1)` |
| `find()`                      | `O(n * m)` | `O(1)` |

---

## ⚠️ Common Mistakes

| Mistake                                         | Correct Approach                                         |
| ----------------------------------------------- | -------------------------------------------------------- |
| Forgetting `'\0'` in a manual char array        | Always end with `'\0'`                                   |
| Using `cin >>` for a full name                  | Use `getline()`, since `cin >>` stops at a space         |
| Skipping `cin.ignore()` before `getline()`      | Clear the leftover newline first                         |
| Comparing char arrays with `==`                 | Use `strcmp()`, since `==` compares addresses            |
| Destination array too small for `strcpy`/`strcat` | Make sure it fits the result plus `'\0'`               |
| Using `start <= end` in the reverse loop        | Use `start < end`; the middle element needs no swap      |
| Comparing `int i` with `name.length()`          | `length()` returns `size_t`, so use `size_t i` to avoid warnings |

---

## 🎓 Interview Tip

Be ready to explain:

* What the null terminator is and why char arrays need it
* Difference between a char array and `string`
* Why `cin >>` stops at spaces and how `getline()` fixes it
* Why `==` fails for char arrays
* How to reverse a string in place with `O(1)` extra space

A simple explanation:

> "I keep one pointer at the start and one at the end, swap the characters, and move both inward until they meet. This reverses the string in `O(n)` time and `O(1)` space."

---

## 🌱 What This Chapter Builds

String Handling, Input Handling, Two Pointer Technique, In-place Operations, Working with Built-in Functions.

> **"Know the basics well, because every string problem builds on them."** 💻
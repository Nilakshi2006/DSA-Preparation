# 🚀 DSA Journey — Chapter 26: Remove All Occurrences of a Substring (C++)

Chapter 26 of my Data Structures & Algorithms journey. 💻

Problem: given strings `s` and `part`, repeatedly remove the **leftmost** occurrence of `part` from `s` until it no longer appears. I solved it using `find()` and `erase()`.

---

## 📂 Programs Covered

| #  | File Name                  | Concept                                  |
| -- | -------------------------- | ---------------------------------------- |
| 01 | `01.RemoveOccurance.cpp`   | Repeated `find()` and `erase()`          |

## 📁 Folder Structure

```text
26-RemoveOccurance/

│── 01.RemoveOccurance.cpp

└── README.md
```

---

## 💻 Concepts Used

Strings, `find()`, `erase()`, `npos`, Loops, Classes, Time and Space Complexity.

---

## ⚡ Approach

Keep finding the first occurrence of `part` and erasing it. Removing one occurrence can join the characters around it and create a new one, so a single pass is not enough.

1. **Find:** `s.find(part)` returns the index of the first match.
2. **Erase:** `s.erase(index, part.length())` removes it.
3. **Repeat:** stop when `find()` returns `npos`.

When nothing is found, `find()` returns `string::npos`, a huge value, so the check `s.find(part) < s.length()` becomes false and the loop ends.

```cpp
string removeOccurrences(string s, string part) {
    while (s.length() > 0 && s.find(part) < s.length()) {
        s.erase(s.find(part), part.length());
    }
    return s;
}
```

### 🔍 Dry Run (`s = "daabcbaabcbc"`, `part = "abc"`)

```text
s = daabcbaabcbc
find("abc") = 2  → erase → dabaabcbc

find("abc") = 4  → erase → dababc
                   (new "abc" formed after the first removal)

find("abc") = 3  → erase → dab

find("abc") = npos → stop

Result: dab
```

---

## 🧪 Output

```text
Enter the string: daabcbaabcbc
Enter the part to remove: abc
After removing all occurrences: dab
```

---

## 📈 Complexity

| Approach        | Time                | Space  |
| --------------- | ------------------- | ------ |
| `find` + `erase` | `O(n²)` worst case | `O(n)` |

Each `find()` and `erase()` can take `O(n)`, and there can be up to `n / m` removals. Space is `O(n)` because `s` is passed by value. A stack-based approach brings this down to `O(n * m)`.

---

## ⚠️ Common Mistakes

| Mistake                                         | Correct Approach                                              |
| ----------------------------------------------- | ------------------------------------------------------------- |
| Removing occurrences in only one pass           | Loop again, since a removal can create a new match            |
| Passing the end index to `erase()`              | `erase(pos, len)` takes a **length**, not an end index        |
| Not handling the "not found" case               | Check against `npos` before erasing                           |
| Removing a non-leftmost occurrence              | Always remove the leftmost one, which `find()` gives          |
| Using `cin >>` to read `s` or `part`            | Use `getline()` so spaces are read correctly                  |

---

## 🎓 Interview Tip

Be ready to explain:

* Why one pass is not enough (removals can form new matches)
* What `find()` returns when there is no match
* The difference between `erase(pos, len)` and `erase(first, last)`
* Why this solution is `O(n²)` in the worst case
* The stack-based alternative for better performance

A simple explanation:

> "I repeatedly find the leftmost occurrence of the part and erase it, until `find()` returns `npos`. I loop because removing one occurrence can create another."

---

## 🌱 What This Chapter Builds

String Manipulation, Built-in String Functions, Simulation Thinking, Edge Case Handling.

> **"After every removal, look again."** 💻
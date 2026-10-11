# 🚀 DSA Journey — Chapter 29: String Compression (C++)

Chapter 29 of my Data Structures & Algorithms journey. 💻

Problem: compress a character array **in place** by replacing each group of repeating characters with the character followed by the group's count. If the count is 1, only the character is kept. Return the new length. I solved it with the **two pointer (read/write) approach**.

---

## 📂 Programs Covered

| #  | File Name           | Concept                                      |
| -- | ------------------- | -------------------------------------------- |
| 01 | `01.StringComp.cpp` | In-place compression with read/write pointers |

## 📁 Folder Structure

```text
29-StringCompression/

│── 01.StringComp.cpp

└── Readme.md
```

---

## 💻 Concepts Used

Vectors, Two Pointers, Counting Groups, `to_string()`, In-place Modification, Time and Space Complexity.

---

## ⚡ Two Pointer Approach

One pointer `i` reads the array, and another pointer `idx` writes the result into the same array. The write pointer never gets ahead of the read pointer, so nothing unread is overwritten.

1. **Count the group:** from `i`, move forward while the character stays the same.
2. **Write the character:** `chars[idx++] = ch`.
3. **Write the count:** if `count > 1`, convert it with `to_string()` and write each digit.
4. **Step back:** `i--` cancels the extra move, so the `for` loop's `i++` lands on the next group.

Return `idx`, which is the compressed length.

```cpp
int compress(vector<char>& chars) {
    int n = chars.size();
    int idx = 0;

    for (int i = 0; i < n; i++) {
        char ch = chars[i];
        int count = 0;

        while (i < n && chars[i] == ch) {
            count++;
            i++;
        }

        chars[idx++] = ch;

        if (count > 1) {
            string str = to_string(count);

            for (char dig : str) {
                chars[idx++] = dig;
            }
        }

        i--;
    }

    return idx;
}
```

### 🔍 Dry Run (`{a, a, b, b, c, c, c}`)

```text
group "aa"  → count = 2 → write a, 2   → a 2 ...
group "bb"  → count = 2 → write b, 2   → a 2 b 2 ...
group "ccc" → count = 3 → write c, 3   → a 2 b 2 c 3

Length = 6
```

### 🔍 Dry Run, Count With Two Digits (`a` followed by twelve `b`)

```text
group "a"        → count = 1  → write a only
group "bbbbbbbbbbbb" → count = 12 → write b, then '1', '2'

Result: a b 1 2 → length 4
```

---

## 🧪 Output

```text
Compressed length: 6
Compressed string: a2b2c3
```

---

## 📈 Complexity

| Approach     | Time   | Space  |
| ------------ | ------ | ------ |
| Two pointers | `O(n)` | `O(1)` |

Every character is read once. The only extra memory is the small string made by `to_string()`, which holds a few digits at most.

---

## ⚠️ Common Mistakes

| Mistake                                     | Correct Approach                                            |
| ------------------------------------------- | ----------------------------------------------------------- |
| Writing the count when it is 1              | Write the count only if `count > 1`                         |
| Forgetting `i--` after the inner loop       | Without it, the first character of the next group is skipped |
| Writing a count like `12` as one character  | Split it into digits `'1'`, `'2'` with `to_string()`        |
| Returning `chars.size()`                    | Return `idx`, the length of the compressed part             |
| Building a new array for the answer         | Write back into `chars` to keep `O(1)` space                |
| Missing `i < n` in the inner `while`        | Without it, the last group reads past the end               |

---

## 🎓 Interview Tip

Be ready to explain:

* Why the write pointer can never overtake the read pointer
* Why `i--` is needed after counting a group
* How counts of 10 or more are written digit by digit
* Why the array is modified in place instead of creating a new one
* Why the solution is `O(n)` time and `O(1)` space

A simple explanation:

> "I count each group of repeating characters with one pointer and write the character and its count back into the same array with another pointer. This compresses the array in `O(n)` time and `O(1)` space."

---

## 🌱 What This Chapter Builds

Read/Write Pointer Technique, Group Counting, In-place Modification, Digit Handling, Edge Case Handling.

> **"Count the group, write it once, move on."** 💻
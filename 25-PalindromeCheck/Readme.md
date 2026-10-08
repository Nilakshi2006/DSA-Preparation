# 🚀 DSA Journey — Chapter 25: Valid Palindrome (C++)

Chapter 25 of my Data Structures & Algorithms journey. 💻

Problem: check whether a string is a palindrome after **ignoring case and non-alphanumeric characters**. I solved it with the **two pointer approach**.

---

## 📂 Programs Covered

| #  | File Name                 | Concept                                        |
| -- | ------------------------- | ---------------------------------------------- |
| 01 | `01.PalindromeCheck.cpp`  | Two pointers, skip non-alphanumeric, ignore case |

## 📁 Folder Structure

```text
25-PalindromeCheck/

│── 01.PalindromeCheck.cpp

└── README.md
```

---

## 💻 Concepts Used

Strings, Two Pointers, Character Checking, `tolower()`, Helper Functions, Classes, Time and Space Complexity.

---

## ⚡ Two Pointer Approach

Put one pointer at each end and move inward. Skip anything that is not a letter or digit, then compare the two characters in lowercase.

1. **Skip:** if `s[st]` is not alphanumeric, move `st` forward. If `s[end]` is not alphanumeric, move `end` back.
2. **Compare:** if `tolower(s[st]) != tolower(s[end])`, return `false`.
3. **Move:** if they match, move both pointers inward.

If the pointers meet without a mismatch, it is a palindrome.

```cpp
bool isAlphaNum(char ch) {
    if ((ch >= '0' && ch <= '9') ||
        (ch >= 'a' && ch <= 'z') ||
        (ch >= 'A' && ch <= 'Z')) {
        return true;
    }
    return false;
}

bool isPalindrome(string s) {
    int st = 0, end = s.length() - 1;

    while (st < end) {
        if (!isAlphaNum(s[st]))  { st++;  continue; }
        if (!isAlphaNum(s[end])) { end--; continue; }

        if (tolower(s[st]) != tolower(s[end])) {
            return false;
        }
        st++;
        end--;
    }
    return true;
}
```

### 🔍 Dry Run (`"A man, a plan, a canal: Panama"`)

```text
st = 0,  end = 29  → 'A' vs 'a'   → match
st = 1  → ' ' is not alphanumeric  → skip
st = 2,  end = 28  → 'm' vs 'm'   → match
st = 3,  end = 27  → 'a' vs 'a'   → match
st = 4,  end = 26  → 'n' vs 'n'   → match
st = 5  → ',' skip | st = 6 → ' ' skip
st = 7,  end = 25  → 'a' vs 'a'   → match
st = 8  → ' ' skip
st = 9,  end = 24  → 'p' vs 'P'   → match (after tolower)
...
pointers meet → Palindrome
```

---

## 🧪 Output

```text
Enter a string: A man, a plan, a canal: Panama
Palindrome
```

```text
Enter a string: race a car
Not Palindrome
```

---

## 📈 Complexity

| Approach     | Time   | Space  |
| ------------ | ------ | ------ |
| Two pointers | `O(n)` | `O(1)` |

Building a cleaned copy and comparing it with its reverse also works, but it needs `O(n)` extra space.

---

## ⚠️ Common Mistakes

| Mistake                                      | Correct Approach                                        |
| -------------------------------------------- | ------------------------------------------------------- |
| Comparing without `tolower()`                | Convert both characters, or `'A'` and `'a'` won't match |
| Not skipping spaces and punctuation          | Skip non-alphanumeric characters on both sides          |
| Forgetting `continue` after a skip           | Without it, the code compares a skipped character       |
| Using `cin >>` to read the input             | Use `getline()`, since `cin >>` stops at a space        |
| Moving only one pointer after a match        | Move both `st++` and `end--`                            |

---

## 🎓 Interview Tip

Be ready to explain:

* Why two pointers avoid extra space
* Why non-alphanumeric characters are skipped instead of removed
* Why the loop condition is `st < end`
* What happens for an empty string or a string with only symbols (returns `true`)
* The built-in alternative: `isalnum()`

A simple explanation:

> "I keep one pointer at each end, skip characters that are not letters or digits, and compare the rest ignoring case. If every pair matches, it's a palindrome. This takes `O(n)` time and `O(1)` space."

---

## 🌱 What This Chapter Builds

Two Pointer Technique, String Traversal, Input Filtering, Case Handling, Edge Case Handling.

> **"Look from both ends, ignore the noise, trust the match."** 💻
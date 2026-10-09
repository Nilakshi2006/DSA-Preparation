# 🚀 DSA Journey — Chapter 27: Permutation in String (C++)

Chapter 27 of my Data Structures & Algorithms journey. 💻

Problem: given two strings `s1` and `s2`, return `true` if `s2` contains a **permutation of `s1`** as a substring. I solved it with the **frequency array approach**, checking every window of `s2`.

---

## 📂 Programs Covered

| #  | File Name            | Concept                                      |
| -- | -------------------- | -------------------------------------------- |
| 01 | `01.Permutation.cpp` | Frequency arrays, compare every window of s2 |

## 📁 Folder Structure

```text
27-PermutationInStr/

│── 01.Permutation.cpp

└── Readme.md
```

---

## 💻 Concepts Used

Strings, Frequency Array, Hashing by Index, Windows, Nested Loops, Helper Functions, Time and Space Complexity.

---

## ⚡ Frequency Array Approach

Two strings are permutations of each other if they have the same character counts. So we count the letters of `s1`, then check every window of `s2` with the same length.

1. **Count `s1`:** store each letter's count in `freq[26]` using `s[i] - 'a'`.
2. **Build a window:** for every start index `i`, count the next `s1.length()` characters of `s2` in `windowFreq[26]`.
3. **Compare:** if both arrays match, return `true`.

If no window matches, return `false`.

```cpp
bool isfreqSame(int freq1[], int freq2[]) {
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int freq[26] = {0};

    for (int i = 0; i < s1.length(); i++) {
        freq[s1[i] - 'a']++;
    }

    int windowSize = s1.length();

    for (int i = 0; i < s2.length(); i++) {
        int windowIdx = 0, strIdx = i;
        int windowFreq[26] = {0};

        while (windowIdx < windowSize && strIdx < s2.length()) {
            windowFreq[s2[strIdx] - 'a']++;
            windowIdx++;
            strIdx++;
        }

        if (isfreqSame(freq, windowFreq)) {
            return true;
        }
    }

    return false;
}
```

### 🔍 Dry Run (`s1 = "ab"`, `s2 = "eidbaooo"`)

```text
freq of s1 → a:1, b:1

i = 0  window "ei"  → e:1, i:1  → not same
i = 1  window "id"  → i:1, d:1  → not same
i = 2  window "db"  → d:1, b:1  → not same
i = 3  window "ba"  → b:1, a:1  → same ✅

Permutation exists
```

### 🔍 Dry Run, No Match (`s1 = "ab"`, `s2 = "eidboaoo"`)

```text
"ei" ✗ | "id" ✗ | "db" ✗ | "bo" ✗ | "oa" ✗ | "ao" ✗ | "oo" ✗ | "o" ✗

No window matches → Permutation does not exist
```

---

## 🧪 Output

```text
Enter s1: ab
Enter s2: eidbaooo
Permutation exists
```

```text
Enter s1: ab
Enter s2: eidboaoo
Permutation does not exist
```

---

## 📈 Complexity

| Approach        | Time                      | Space  |
| --------------- | ------------------------- | ------ |
| Frequency array | `O(n * (m + 26))` ≈ `O(n * m)` | `O(1)` |

Here `n = s2.length()` and `m = s1.length()`. Every start index rebuilds a window of size `m` and then compares 26 counts. Space is `O(1)` because the arrays always hold 26 integers.

The optimal approach is a **sliding window**: update the window by adding one character and removing one, instead of rebuilding it. That brings the time down to `O(n)`.

---

## ⚠️ Common Mistakes

| Mistake                                         | Correct Approach                                                  |
| ----------------------------------------------- | ----------------------------------------------------------------- |
| Sorting both strings for every window           | Compare frequency arrays instead, which avoids sorting            |
| Forgetting to reset `windowFreq` for each start | Declare it inside the loop so it starts at zero every time        |
| Using `s[i]` directly as the index              | Subtract `'a'` to map letters to `0–25`                           |
| Not stopping the window at the end of `s2`      | Check `strIdx < s2.length()` to avoid reading out of range        |
| Assuming any characters are allowed             | This code only works for lowercase `a–z`                          |
| Comparing arrays with `==`                      | `==` compares addresses, so loop over all 26 counts               |

---

## 🎓 Interview Tip

Be ready to explain:

* Why equal frequency counts means a permutation
* Why the window size is always `s1.length()`
* Why this approach is `O(n * m)` and what makes it slow
* How a sliding window updates the counts in `O(1)` per step
* Why the frequency array is `O(1)` space even though it is an array

A simple explanation:

> "I count the letters of s1, then check every window of s2 of the same length. If a window has the same letter counts, it is a permutation, so I return true. A sliding window makes this O(n)."

---

## 🌱 What This Chapter Builds

Frequency Counting, Window Thinking, Hashing by Index, Brute Force to Optimal Thinking, Edge Case Handling.

> **"Same letters, same counts — order does not matter."** 💻
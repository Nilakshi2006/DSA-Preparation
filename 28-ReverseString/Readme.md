# 🚀 DSA Journey — Chapter 28: Reverse Words in a String (C++)

Chapter 28 of my Data Structures & Algorithms journey. 💻

Problem: given a string `s`, reverse the **order of the words**. Remove leading, trailing, and extra spaces so words are separated by a single space. I solved it with the **double reverse approach**.

---

## 📂 Programs Covered

| #  | File Name            | Concept                                         |
| -- | -------------------- | ----------------------------------------------- |
| 01 | `01.ReverseStr.cpp`  | Reverse whole string, then reverse each word    |

## 📁 Folder Structure

```text
28-ReverseString/

│── output/
│── 01.ReverseStr.cpp

└── Readme.md
```

---

## 💻 Concepts Used

Strings, `reverse()`, Word Extraction, Nested Loops, `substr()`, `getline()`, Time and Space Complexity.

---

## ⚡ Double Reverse Approach

Reversing the whole string puts the words in the right order, but each word comes out backwards. Reversing each word fixes that.

1. **Reverse the whole string:** `reverse(s.begin(), s.end())`.
2. **Extract each word:** skip spaces, collect characters until the next space.
3. **Reverse the word back:** `reverse(word.begin(), word.end())`.
4. **Append:** add `" " + word` to the answer, only if the word is not empty.
5. **Trim:** remove the leading space with `ans.substr(1)`.

Empty words (from extra spaces) are skipped, so only single spaces remain.

```cpp
string reverseWords(string s) {
    int n = s.length();
    string ans = "";

    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++) {
        string word = "";

        while (i < n && s[i] != ' ') {
            word += s[i];
            i++;
        }

        reverse(word.begin(), word.end());

        if (word.length() > 0) {
            ans += " " + word;
        }
    }

    return ans.empty() ? "" : ans.substr(1);
}
```

### 🔍 Dry Run (`"the sky is blue"`)

```text
Step 1: reverse whole string
        "the sky is blue" → "eulb si yks eht"

Step 2: extract and reverse each word
        "eulb" → "blue"  → ans = " blue"
        "si"   → "is"    → ans = " blue is"
        "yks"  → "sky"   → ans = " blue is sky"
        "eht"  → "the"   → ans = " blue is sky the"

Step 3: remove leading space
        → "blue is sky the"
```

### 🔍 Dry Run, Extra Spaces (`"  hello   world  "`)

```text
Reverse whole → "  dlrow   olleh  "

spaces         → word is empty → skipped
"dlrow" → "world" → ans = " world"
spaces         → skipped
"olleh" → "hello" → ans = " world hello"
spaces         → skipped

Remove leading space → "world hello"
```

---

## 🧪 Output

```text
Enter a string: the sky is blue
Reversed words: blue is sky the
```

```text
Enter a string:   hello   world  
Reversed words: world hello
```

---

## 📈 Complexity

| Approach       | Time   | Space  |
| -------------- | ------ | ------ |
| Double reverse | `O(n)` | `O(n)` |

Every character is visited a constant number of times. Space is `O(n)` for `ans` and the temporary `word`.

---

## ⚠️ Common Mistakes

| Mistake                                        | Correct Approach                                              |
| ---------------------------------------------- | ------------------------------------------------------------- |
| Using `cin >>` to read the input               | Use `getline()`, since `cin >>` stops at the first space      |
| Forgetting to reverse each word back           | After the full reverse, every word is backwards                |
| Adding empty words for extra spaces            | Check `word.length() > 0` before appending                    |
| Leaving a leading space in the answer          | Remove it with `substr(1)`                                    |
| Calling `substr(1)` on an empty answer         | Check `ans.empty()` first                                     |
| Missing `i < n` in the inner `while`           | Without it, the last word reads past the end of the string    |

---

## 🎓 Interview Tip

Be ready to explain:

* Why reversing the whole string and then each word works
* How extra spaces are handled without a separate cleanup pass
* Why `ans.empty()` is checked before `substr(1)`
* Why this solution uses `O(n)` extra space
* The in-place alternative: reverse in place, then compact the spaces (`O(1)` extra space in languages with mutable strings)

A simple explanation:

> "I reverse the whole string so the words are in the right order, then reverse each word to fix its letters, skipping extra spaces. This takes `O(n)` time."

---

## 🌱 What This Chapter Builds

String Manipulation, Word Extraction, Reverse Technique, Whitespace Handling, Edge Case Handling.

> **"Reverse everything, then fix each piece."** 💻
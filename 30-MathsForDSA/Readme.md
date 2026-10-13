# 🚀 DSA Journey — Chapter 30: Maths for DSA (C++)

Chapter 30 of my Data Structures & Algorithms journey. 💻

Topic: the core math problems that show up again and again in DSA: **prime numbers, digit manipulation, Armstrong numbers, GCD/LCM, reverse and palindrome numbers**.

---

## 📂 Programs Covered

| #  | File Name                       | Concept                                   |
| -- | ------------------------------- | ----------------------------------------- |
| 01 | `01.PrimeNumber.cpp`            | Check prime up to `√n`                    |
| 02 | `02.PrimeNoInRangeOf2ToN.cpp`   | Count primes below `n` (Sieve of Eratosthenes) |
| 03 | `03.DigitInNumber.cpp`          | Print every digit                         |
| 04 | `04.CountOfDigits.cpp`          | Count digits                              |
| 05 | `05.SumOfDigit.cpp`             | Sum of digits                             |
| 06 | `06.ArmstrongNumber.cpp`        | Armstrong check with manual cube          |
| 07 | `07.Armstrong2.cpp`             | Armstrong check with `pow()`              |
| 08 | `08.GCD.cpp`                    | GCD by brute force                        |
| 09 | `09.GCDUsingEuclidAlgo.cpp`     | GCD with Euclid's algorithm (loop)        |
| 10 | `10.GCDUsingRecursion.cpp`      | GCD with Euclid's algorithm (recursion)   |
| 11 | `11.LCM.cpp`                    | LCM using GCD                             |
| 12 | `12.RevesreNumber.cpp`          | Reverse a number                          |
| 13 | `13.PalindromeNumber.cpp`       | Palindrome number with overflow check     |

## 📁 Folder Structure

```text
30-MathsForDSA/

│── output/
│── 01.PrimeNumber.cpp
│── 02.PrimeNoInRangeOf2ToN.cpp
│── 03.DigitInNumber.cpp
│── 04.CountOfDigits.cpp
│── 05.SumOfDigit.cpp
│── 06.ArmstrongNumber.cpp
│── 07.Armstrong2.cpp
│── 08.GCD.cpp
│── 09.GCDUsingEuclidAlgo.cpp
│── 10.GCDUsingRecursion.cpp
│── 11.LCM.cpp
│── 12.RevesreNumber.cpp
│── 13.PalindromeNumber.cpp

└── Readme.md
```

---

## 💻 Concepts Used

Loops, Modulo and Division, Digit Extraction, Sieve of Eratosthenes, Euclid's Algorithm, Recursion, Integer Overflow, Time and Space Complexity.

---

## ⚡ Digit Extraction (the base of most problems)

```cpp
int digit = n % 10;   // last digit
n = n / 10;           // remove last digit
```

`n % 10` gives the last digit and `n / 10` drops it. Repeat until `n == 0`. Counting, summing, reversing, Armstrong and palindrome checks all use this loop.

### 🔍 Dry Run, Reverse (`n = 1234`)

```text
n = 1234 → lastdig = 4 → rev = 0 * 10 + 4   = 4
n = 123  → lastdig = 3 → rev = 4 * 10 + 3   = 43
n = 12   → lastdig = 2 → rev = 43 * 10 + 2  = 432
n = 1    → lastdig = 1 → rev = 432 * 10 + 1 = 4321
n = 0    → stop

Reversed number = 4321
```

---

## 🔢 Prime Numbers

A number is prime if nothing from `2` to `√n` divides it. Divisors come in pairs, so if `n` has a divisor above `√n`, it also has one below it.

```cpp
bool isPrime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
```

### Sieve of Eratosthenes

To count many primes, mark the multiples of each prime as not prime instead of testing every number.

```cpp
int countPrimes(int n) {
    vector<bool> isPrime(n, true);
    int count = 0;

    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
            for (int j = i * 2; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return count;
}
```

### 🔍 Dry Run (`n = 10`)

```text
i = 2 → prime, count = 1 → mark 4, 6, 8
i = 3 → prime, count = 2 → mark 6, 9
i = 4 → marked, skip
i = 5 → prime, count = 3
i = 6 → marked, skip
i = 7 → prime, count = 4
i = 8, 9 → marked, skip

Primes below 10 = 4  (2, 3, 5, 7)
```

---

## 🔤 Armstrong Number

A number is Armstrong if the sum of its digits, each raised to the power of the digit count, equals the number. These programs handle 3-digit numbers, so each digit is cubed.

```text
153 → 1³ + 5³ + 3³ = 1 + 125 + 27 = 153 ✅
```

`06` multiplies manually (`digit * digit * digit`), and `07` uses `pow(rem, 3)`. Manual multiplication is safer because `pow()` returns a `double`, which can round down when stored in an `int`.

---

## ➗ GCD and LCM

**Brute force** tries every number from `1` to `min(a, b)` and keeps the largest one that divides both.

**Euclid's algorithm** uses the fact that `gcd(a, b) = gcd(b, a % b)`, and stops when `b` becomes `0`.

```cpp
// Recursive
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Loop
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) a = a % b;
        else       b = b % a;
    }
    return a == 0 ? b : a;
}
```

**LCM** follows from `a * b = gcd(a, b) * lcm(a, b)`:

```cpp
int lcm(int a, int b) {
    int gcd = gcdRec(a, b);
    return (a * b) / gcd;
}
```

### 🔍 Dry Run, Euclid (`a = 12`, `b = 18`)

```text
gcd(12, 18) → gcd(18, 12)
gcd(18, 12) → gcd(12, 6)
gcd(12, 6)  → gcd(6, 0)
gcd(6, 0)   → b == 0 → return 6

GCD = 6
LCM = (12 * 18) / 6 = 36
```

---

## 🔁 Palindrome Number

Reverse the number and compare it with the original. Negative numbers and numbers ending in `0` (except `0`) can never be palindromes, so they return `false` early. The `INT_MAX / 10` check stops the reversed number from overflowing.

### 🔍 Dry Run (`x = 121`)

```text
x = 121 → rev = 1
x = 12  → rev = 12
x = 1   → rev = 121
x = 0   → stop

org == rev → 121 is a palindrome
```

---

## 🧪 Output

```text
01  Enter a number: 17
    17 is a prime number

02  Enter n: 10
    Number of primes less than 10 = 4

03  4
    3
    2
    2

04  4

05  11

06  Number is Armstrong

07  Enter a number: 153
    Armstrong number

08  GCD = 6

09  GCD = 6

10  GCD = 6

11  GCD = 6
    LCM = 36

12  Reversed number = 4321

13  121 is a palindrome
```

---

## 📈 Complexity

| Program                | Time                       | Space      |
| ---------------------- | -------------------------- | ---------- |
| Prime check            | `O(√n)`                    | `O(1)`     |
| Sieve                  | `O(n log log n)`           | `O(n)`     |
| Digit loops (03 to 07) | `O(log n)`                 | `O(1)`     |
| GCD brute force        | `O(min(a, b))`             | `O(1)`     |
| GCD Euclid (loop)      | `O(log(min(a, b)))`        | `O(1)`     |
| GCD Euclid (recursion) | `O(log(min(a, b)))`        | `O(log n)` |
| LCM                    | `O(log(min(a, b)))`        | `O(log n)` |
| Reverse / Palindrome   | `O(log n)`                 | `O(1)`     |

A number `n` has about `log10(n)` digits, so digit loops run `O(log n)` times.

---

## ⚠️ Common Mistakes

| Mistake                                          | Correct Approach                                             |
| ------------------------------------------------ | ------------------------------------------------------------ |
| Looping to `n` when checking prime               | Loop while `i * i <= n`                                      |
| Treating `1` or negatives as prime               | Return `false` for `n <= 1`                                  |
| Writing `a % b;` without assigning               | Use `a = a % b;`, or the value never changes                 |
| Using `pow()` and storing in `int`               | `pow()` returns `double` and can round down, so multiply manually |
| Calling `gcd(a, 0)` wrongly                      | Base case: `b == 0` returns `a`                              |
| Computing `(a * b) / gcd` for large values       | `a * b` can overflow, so use `(a / gcd) * b`                 |
| Reversing without an overflow check              | Compare `rev` with `INT_MAX / 10` before multiplying         |
| Forgetting `n == 0` in digit loops               | A `while (n != 0)` loop gives a count of 0 for `n = 0`       |

---

## 🎓 Interview Tip

Be ready to explain:

* Why checking up to `√n` is enough for primality
* How the Sieve avoids rechecking numbers, and why it is `O(n log log n)`
* Why `gcd(a, b) = gcd(b, a % b)` is true
* How LCM comes from GCD, and where overflow can happen
* How `% 10` and `/ 10` extract and remove digits
* Why palindrome checks need an overflow guard

A simple explanation:

> "I use `% 10` to take the last digit and `/ 10` to remove it, and repeat until the number is zero. For GCD I use Euclid's algorithm, replacing `(a, b)` with `(b, a % b)` until `b` is zero, which takes `O(log n)` time."

---

## 🌱 What This Chapter Builds

Digit Manipulation, Number Theory Basics, Sieve Technique, Euclid's Algorithm, Overflow Awareness, Edge Case Handling.

> **"Master `% 10` and `/ 10`, and half of number problems fall."** 💻
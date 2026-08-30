# 🚀 DSA Journey – Chapter 4: Bitwise Operators (C++)

Welcome to **Chapter 4** of my **Data Structures & Algorithms (DSA)** journey! ⚡

After understanding the **Binary Number System**, I moved on to **Bitwise Operators** in C++. This chapter focuses on performing operations directly on binary bits, understanding variable scope, operator precedence, data type modifiers, and solving common bit manipulation problems like checking whether a number is a **Power of 2**.

Bitwise Operators are extremely important in DSA because they help write **optimized and efficient code** for many algorithms and interview problems.

---

## 📚 Programs Covered

| # | File Name | Concept |
|---|-----------|---------|
| 01 | `01.BitwiseOperator.cpp` | Basic Bitwise Operators (`AND`, `OR`, `XOR`, `Left Shift`, `Right Shift`). |
| 02 | `02.OperatorPrecedence.cpp` | Understanding operator precedence and associativity in C++. |
| 03 | `03.LocalVariable.cpp` | Scope of local variables inside functions and blocks. |
| 04 | `04.GlobalVariable.cpp` | Declaring and accessing global variables in multiple functions. |
| 05 | `05.DataModifier.cpp` | Understanding integer data type modifiers using `sizeof()`. |
| 06 | `06.IsPowerOf2.cpp` | Checking whether a number is a Power of 2 using loops and bitwise operations. |
| 07 | `07.ReverseInteger.cpp` | Reversing an integer using mathematical operations. |

---

## 🎯 Concepts I Learned

This chapter introduced me to the fundamentals of **Bit Manipulation** and some important C++ concepts.

### 🧠 Bitwise Operators

Bitwise operators work on the binary representation of numbers.

| Operator | Symbol | Purpose |
|----------|--------|---------|
| AND | `&` | Sets bit to `1` only if both bits are `1`. |
| OR | `|` | Sets bit to `1` if either bit is `1`. |
| XOR | `^` | Sets bit to `1` if bits are different. |
| Left Shift | `<<` | Shifts bits to the left (multiplies by powers of 2). |
| Right Shift | `>>` | Shifts bits to the right (divides by powers of 2). |

**Example**

```cpp
int a = 4, b = 8;

cout << (a & b);
cout << (a | b);
cout << (a ^ b);
cout << (a << 2);
cout << (a >> 1);
```

---

### ⚙️ Operator Precedence & Associativity

Operators follow a priority order while evaluating expressions.

**Examples**

```cpp
cout << (5 - 2 * 6);      // Multiplication first.
cout << ((5 - 2) * 6);    // Parentheses change priority.
cout << (4 * 5 % 2);      // Same precedence follows associativity.
```

**Key Learning**

- `()` has the highest priority.
- `*`, `/`, `%` have higher precedence than `+` and `-`.
- Operators with the same precedence follow **left-to-right associativity** (except assignment).

---

### 📍 Local Variables

A local variable exists **only inside the block or function** where it is declared.

```cpp
if (3 > 2)
{
    int x = 10;
    cout << x;
}
```

**Key Learning**

- Accessible only within its scope.
- Destroyed after the block or function ends.
- Helps avoid unwanted modification outside the function.

---

### 🌍 Global Variables

A global variable is declared **outside all functions** and can be accessed from anywhere in the program.

```cpp
int x = 10;

void fun()
{
    cout << x;
}
```

**Key Learning**

- Accessible inside multiple functions.
- Lifetime is the entire execution of the program.
- Useful for shared values.

---

### 📏 Data Type Modifiers

Used `sizeof()` to understand memory occupied by different integer types.

```cpp
cout << sizeof(int) << endl;
cout << sizeof(long int) << endl;
cout << sizeof(short int) << endl;
cout << sizeof(long long int) << endl;
```

#### Common Integer Sizes

| Data Type | Typical Size |
|-----------|--------------|
| `short int` | 2 Bytes |
| `int` | 4 Bytes |
| `long int` | 4 or 8 Bytes (depends on compiler/system) |
| `long long int` | 8 Bytes |

**Key Learning**

- Different integer types occupy different memory.
- Helpful while working with large numbers in DSA.

---

### ⚡ Check Power of 2

Two approaches were explored.

#### Method 1 — Using Loop

Repeatedly divide by `2` until the number becomes `1`.

```cpp
while (n > 1)
{
    if (n % 2 != 0)
        return false;

    n = n / 2;
}
```

#### Method 2 — Using Bitwise Operator (Optimized)

```cpp
if (n > 0 && (n & (n - 1)) == 0)
    cout << "Power of 2";
else
    cout << "Not a Power of 2";
```

#### Why does this work?

A Power of 2 has exactly **one set bit**.

| Number | Binary | `n & (n-1)` |
|--------|--------|-------------|
| 1 | `0001` | `0000` |
| 2 | `0010` | `0000` |
| 4 | `0100` | `0000` |
| 8 | `1000` | `0000` |

**Key Learning**

- Bitwise solution runs in **O(1)** time.
- Frequently asked interview problem.

---

### 🔄 Reverse an Integer

Reverse digits using modulus and division.

```cpp
while (num > 0)
{
    int digit = num % 10;
    rev = rev * 10 + digit;
    num = num / 10;
}
```

#### Example

```text
Input : 12345
Output: 54321
```

**Algorithm**

1. Extract the last digit using `% 10`.
2. Add it to the reversed number.
3. Remove the last digit using `/ 10`.
4. Repeat until the number becomes `0`.

**Time Complexity:** `O(log₁₀N)`

**Space Complexity:** `O(1)`

---

## 💻 Language Used

- **C++**

### Concepts Used

- Bitwise Operators (`&`, `|`, `^`, `<<`, `>>`)
- Arithmetic Operators
- Variables
- Local & Global Scope
- `sizeof()` Operator
- `if-else`
- `while` Loop
- Integer Manipulation
- Bit Manipulation

---

## 📂 Folder Structure

```text
04-Bitwise-Operators/
│── output/
│── 01.BitwiseOperator.cpp
│── 02.OperatorPrecedence.cpp
│── 03.LocalVariable.cpp
│── 04.GlobalVariable.cpp
│── 05.DataModifier.cpp
│── 06.IsPowerOf2.cpp
│── 07.ReverseInteger.cpp
└── README.md
```

---

## 📝 Bitwise Operator Summary

| Operator | Example | Result |
|----------|---------|--------|
| `&` | `4 & 8` | Common set bits only. |
| `|` | `4 \| 8` | Combines set bits from both numbers. |
| `^` | `4 ^ 8` | Set bits where numbers differ. |
| `<<` | `4 << 2` | `16` |
| `>>` | `4 >> 1` | `2` |

---

## 🌱 What This Chapter Builds

By completing these programs, I strengthened my understanding of:

- Binary bit operations.
- Bitwise manipulation techniques.
- Operator precedence and associativity.
- Local vs Global variable scope.
- Memory occupied by integer data types.
- Efficient Power of 2 checking using bitwise logic.
- Reversing integers using mathematical operations.

This chapter lays the foundation for advanced **Bit Manipulation** problems used in DSA, competitive programming, and coding interviews.

---

## 📖 Key Takeaways

- Bitwise operators manipulate numbers at the **bit level**.
- `n & (n - 1)` is a powerful trick for checking Powers of 2.
- Variable scope determines where variables can be accessed.
- `sizeof()` helps understand memory allocation of data types.
- Operator precedence affects expression evaluation.
- Reversing an integer is a classic DSA problem using `%` and `/`.

---

> *"Bit manipulation is one of the fastest tools in a programmer's toolkit. Understanding bits makes many DSA problems simpler and more efficient."* ⚡
# 🚀 DSA Journey – Chapter 3: Binary Number System (C++)

Welcome to **Chapter 3** of my **Data Structures & Algorithms (DSA)** journey! 🌸

After learning **Patterns** and **Functions**, I started exploring the **Binary Number System** in C++. This chapter focuses on understanding how numbers are represented in binary and how to convert numbers between **Decimal** and **Binary** using simple mathematical logic.

The Binary Number System is one of the fundamental concepts in programming because computers store and process data in binary. This chapter helped me understand the logic behind number conversion using division, remainders, and powers of 2.

---

## 📚 Programs Covered

| # | File Name | Concept |
|---|-----------|---------|
| 01 | Decimal to Binary | Converting a decimal number into binary using division by 2. |
| 02 | Binary to Decimal | Converting a binary number into decimal using powers of 2. |

---

## 🎯 Concepts I Learned

This chapter helped me understand the basics of binary numbers and conversion techniques.

### Decimal to Binary

- Binary is a **Base-2** number system.
- Divide the decimal number by **2** repeatedly.
- Store the remainder (`0` or `1`) at each step.
- Build the binary number using powers of **10**.

### Binary to Decimal

- Read binary digits from **right to left**.
- Multiply each digit with the corresponding power of **2**.
- Add all the values together to get the decimal number.

### Number System Basics

- Difference between **Decimal (Base-10)** and **Binary (Base-2)**.
- Understanding positional values in binary.
- Using `%` (modulus) and `/` (division) operators for conversions.

---

## 💻 Language Used

- **C++**

### Concepts Used

- Functions
- `while` loops
- Arithmetic operators (`%`, `/`, `*`, `+`)
- Variables and integer manipulation
- Powers of 2 and powers of 10

---

## 📂 Folder Structure

```text
03-BinaryNumber/

│── output/
│── 01.DecimaltoBinary.cpp
│── 02.BinarytoDecimal.cpp
└── README.md
```

---

## 🔄 Conversion Logic

### Decimal → Binary

**Algorithm**

1. Divide the decimal number by `2`.
2. Store the remainder.
3. Continue dividing the quotient by `2` until it becomes `0`.
4. Read the remainders from bottom to top.

**Example**

```text
Decimal: 50

50 ÷ 2 = 25 → Remainder = 0
25 ÷ 2 = 12 → Remainder = 1
12 ÷ 2 = 6  → Remainder = 0
6 ÷ 2 = 3   → Remainder = 0
3 ÷ 2 = 1   → Remainder = 1
1 ÷ 2 = 0   → Remainder = 1

Binary = 110010
```

### Binary → Decimal

**Algorithm**

1. Start with `pow = 1` (which represents `2⁰`).
2. Extract digits from right to left using `% 10`.
3. Multiply each digit by the current power of `2`.
4. Double the power after every digit.
5. Add the result to get the decimal number.

**Example**

```text
Binary: 1010

0 × 2⁰ = 0
1 × 2¹ = 2
0 × 2² = 0
1 × 2³ = 8

Decimal = 10
```

---

## 🌱 What This Chapter Builds

By completing these binary number conversion problems, I strengthened my understanding of:

- Binary number representation.
- Decimal ↔ Binary conversion logic.
- Using remainder and division techniques.
- Working with positional values and powers.
- Building a foundation for **Bit Manipulation** and upcoming DSA topics.

This chapter lays the groundwork for understanding how numbers are stored internally in computers and prepares me for future DSA concepts involving bits and bitwise operators.

---

> *“Computers think in binary. Learning the Binary Number System is the first step toward understanding how data is represented and manipulated efficiently.”* 🌸
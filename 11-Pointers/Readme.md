# 🚀 DSA Journey – Chapter 11: Pointers in C++

Welcome to **Chapter 11** of my **Data Structures & Algorithms (DSA)** journey! 💻✨

In this chapter, I learned one of the most important concepts in C++ — **Pointers**. Pointers store the **memory address** of variables and help in efficient memory management, pass-by-reference, arrays, and many advanced data structures like linked lists, trees, and graphs.

This chapter covers the fundamentals of pointers, including **address operator, pointer initialization, pointer to pointer, dereference operator, NULL pointer, pass by reference using pointers and references, array pointers, and pointer arithmetic**.

---

## 📚 Programs Covered

| # | File Name | Concept |
|---|------------|---------|
| 01 | `01.Address.cpp` | Find the memory address of a variable using the address (`&`) operator. |
| 02 | `02.InitializingPointer.cpp` | Initialize a pointer and print addresses of a variable and pointer. |
| 03 | `03.PointerToPointer.cpp` | Understand pointer to pointer (`int **ptr`). |
| 04 | `04.DereferenceOperator.cpp` | Access a value stored at an address using the dereference (`*`) operator. |
| 05 | `05.NULLPointer.cpp` | Declare and use a NULL pointer. |
| 06 | `06.PassByReferenceUsingPointers.cpp` | Modify a variable using pointers (pass by reference). |
| 07 | `07.PassByReferenceUsingReference.cpp` | Modify a variable using C++ references. |
| 08 | `08.ArrayPointer.cpp` | Understand how an array name acts as a pointer. |
| 09 | `09.PointerArithmetic.cpp` | Perform increment, decrement, addition, subtraction, comparison, and pointer difference. |

---

# 🎯 Concepts I Learned

This chapter helped me understand how pointers work internally in C++ and how they interact with variables and arrays.

### Address Operator (`&`)

- Used to get the memory address of a variable.
- Every variable occupies a location in memory.
- `&variable` returns that address.

### Pointer Initialization

- A pointer stores the address of another variable.
- Syntax:

```cpp
int *ptr = &a;
```

- `ptr` stores the address of `a`.

### Pointer to Pointer

- A pointer can also store the address of another pointer.
- Syntax:

```cpp
int **ptr2 = &ptr;
```

- Useful for dynamic memory allocation and advanced programming.

### Dereference Operator (`*`)

- Used to access the value stored at a memory address.
- `*ptr` returns the value stored at the address.

### NULL Pointer

- A pointer that points to **no valid memory location**.
- Prevents accidental access to random memory.

### Pass by Reference Using Pointer

- Pass the address of a variable to a function.
- Changes inside the function affect the original variable.

### Pass by Reference Using Reference Variable

- Use C++ references (`&`) instead of pointers.
- Reference acts as an alias for the original variable.

### Array Pointer

- Array name represents the address of the first element.
- `arr` and `&arr[0]` point to the same location.

### Pointer Arithmetic

- Increment (`ptr++`)
- Decrement (`ptr--`)
- Addition (`ptr + n`)
- Subtraction (`ptr - n`)
- Difference between two pointers.
- Pointer comparison (`==`, `<`, `>`).

---

# 💻 Language Used

- **C++**

### Concepts Used

- Variables
- Memory Address
- Pointers
- References
- Arrays
- Functions
- Pointer Arithmetic

---

# 📂 Folder Structure

```text
11-Pointers/
│── output/
│── 01.Address.cpp
│── 02.InitializingPointer.cpp
│── 03.PointerToPointer.cpp
│── 04.DereferenceOperator.cpp
│── 05.NULLPointer.cpp
│── 06.PassByReferenceUsingPointers.cpp
│── 07.PassByReferenceUsingReference.cpp
│── 08.ArrayPointer.cpp
│── 09.PointerArithmetic.cpp
└── README.md
```

---

# 📍 Program 1 — Address Operator

### Objective

Print the memory address of a variable.

### Algorithm

1. Declare an integer variable.
2. Use the `&` operator.
3. Print its memory address.

### Example

**Input**

```cpp
int a = 10;
```

**Output**

```text
Memory Address of a : 0x61ff08
```

> **Note:** The memory address will be different every time the program runs.

### Time Complexity

- **Time:** `O(1)`
- **Space:** `O(1)`

---

# 📍 Program 2 — Initializing a Pointer

### Objective

Initialize a pointer and understand what it stores.

### Algorithm

1. Declare a variable.
2. Create a pointer pointing to it.
3. Print pointer address, variable address, and pointer's own address.

### Dry Run

```cpp
int a = 10;
int *ptr = &a;
```

| Statement | Meaning |
|-----------|---------|
| `ptr` | Address of `a`. |
| `&a` | Address of variable `a`. |
| `&ptr` | Address where pointer `ptr` is stored. |

### Output

```text
ptr  : 0x61ff08
&a   : 0x61ff08
&ptr : 0x61ff00
```

### Time Complexity

- **Time:** `O(1)`
- **Space:** `O(1)`

---

# 📍 Program 3 — Pointer to Pointer

### Objective

Store the address of a pointer inside another pointer.

### Algorithm

1. Declare a variable.
2. Create a pointer.
3. Create another pointer pointing to the first pointer.

### Dry Run

```cpp
int a = 10;
int *ptr = &a;
int **ptr2 = &ptr;
```

| Variable | Stores |
|----------|--------|
| `a` | `10` |
| `ptr` | Address of `a`. |
| `ptr2` | Address of `ptr`. |

### Output

```text
Address of ptr : 0x61ff00
ptr2           : 0x61ff00
```

### Time Complexity

- **Time:** `O(1)`
- **Space:** `O(1)`

---

# 📍 Program 4 — Dereference Operator

### Objective

Access the value stored at an address.

### Algorithm

1. Declare a variable.
2. Create a pointer.
3. Dereference the address.

### Dry Run

```cpp
int a = 10;
int *ptr = &a;
```

| Expression | Output |
|------------|--------|
| `*(&a)` | `10` |
| `*ptr` | `10` |

### Output

```text
10
10
```

### Time Complexity

- **Time:** `O(1)`
- **Space:** `O(1)`

---

# 📍 Program 5 — NULL Pointer

### Objective

Understand NULL pointers.

### Algorithm

1. Declare a pointer.
2. Initialize it with `NULL`.
3. Print its value.

### Example

```cpp
int *ptr = NULL;
```

### Output

```text
0
```

### Why Use NULL Pointer?

- Indicates the pointer is not pointing anywhere.
- Avoids undefined behavior caused by uninitialized pointers.

### Time Complexity

- **Time:** `O(1)`
- **Space:** `O(1)`

---

# 📍 Program 6 — Pass by Reference Using Pointer

### Objective

Modify the original variable using its address.

### Algorithm

1. Pass address using `&a`.
2. Receive it in pointer parameter.
3. Modify value using `*ptr`.

### Dry Run

**Before Function**

```text
a = 10
```

**Inside Function**

```cpp
*ptr = 20;
```

**After Function**

```text
a = 20
```

### Output

```text
Value of a: 20
```

### Time Complexity

- **Time:** `O(1)`
- **Space:** `O(1)`

---

# 📍 Program 7 — Pass by Reference Using Reference Variable

### Objective

Modify the original variable using C++ references.

### Algorithm

1. Pass variable as reference.
2. Reference becomes an alias.
3. Update the value directly.

### Dry Run

```cpp
void changeA(int &b)
{
    b = 20;
}
```

| Variable | Value |
|----------|-------|
| `a` | `10 → 20` |
| `b` | Alias of `a`. |

### Output

```text
Value of a: 20
```

### Pointer vs Reference

| Pointer | Reference |
|----------|-----------|
| Stores address. | Alias of variable. |
| Uses `*` and `&`. | Uses only `&` in declaration. |
| Can be NULL. | Cannot be NULL. |

### Time Complexity

- **Time:** `O(1)`
- **Space:** `O(1)`

---

# 📍 Program 8 — Array Pointer

### Objective

Understand that an array name is a pointer.

### Algorithm

1. Declare an array.
2. Print `*arr`.

### Dry Run

```cpp
int arr[] = {1,2,3,4,5};
```

| Expression | Output |
|------------|--------|
| `arr` | Address of first element. |
| `*arr` | First element (`1`). |

### Output

```text
1
```

### Time Complexity

- **Time:** `O(1)`
- **Space:** `O(1)`

---

# 📍 Program 9 — Pointer Arithmetic

### Objective

Perform arithmetic and comparison operations on pointers.

### Operations Covered

| Operation | Description |
|-----------|-------------|
| `ptr++` | Move to next element. |
| `ptr--` | Move to previous element. |
| `ptr + n` | Jump forward `n` elements. |
| `ptr - n` | Jump backward `n` elements. |
| `ptr1 - ptr2` | Difference in number of elements. |
| `ptr1 == ptr2` | Check equality. |
| `ptr1 > ptr2` | Compare addresses. |
| `ptr1 < ptr2` | Compare addresses. |

### Dry Run

**Array**

```text
[10, 20, 30, 40, 50]
```

| Statement | Points To |
|-----------|-----------|
| `ptr` | `10` |
| `ptr++` | `20` |
| `ptr--` | `10` |
| `ptr + 3` | `40` |
| `ptr - 2` | `20` |

### Pointer Difference

| Pointer | Value |
|----------|-------|
| `ptr1 = &arr[4]` | `50` |
| `ptr2 = &arr[1]` | `20` |
| `ptr1 - ptr2` | `3` |

### Output

```text
Initial Value: 10
After Increment (ptr++): 20
After Decrement (ptr--): 10
After Adding 3 (ptr + 3): 40
After Subtracting 2 (ptr - 2): 20
Pointer Difference (ptr1 - ptr2): 3
Pointers are Not Equal
ptr1 is after ptr2
ptr2 is before ptr1
```

### Time Complexity

- **Time:** `O(1)`
- **Space:** `O(1)`

---

# 📊 Summary of Pointer Concepts

| Concept | Syntax | Purpose |
|---------|--------|---------|
| Address Operator | `&a` | Get memory address of variable. |
| Pointer Declaration | `int *ptr` | Declare pointer variable. |
| Pointer Initialization | `ptr = &a` | Store address of variable. |
| Dereference | `*ptr` | Access value using address. |
| NULL Pointer | `int *ptr = NULL` | Pointer points nowhere. |
| Pointer to Pointer | `int **ptr2` | Stores address of another pointer. |
| Pass by Pointer | `change(&a)` | Modify original variable using address. |
| Pass by Reference | `change(int &a)` | Modify original variable using alias. |
| Array Pointer | `*arr` | Access first array element. |
| Pointer Arithmetic | `ptr++`, `ptr+n` | Traverse array using pointers. |

---

# 🌱 What This Chapter Builds

By completing this chapter, I strengthened my understanding of:

- Memory addresses and how variables are stored.
- Pointer declaration and initialization.
- Dereference operator (`*`) and Address operator (`&`).
- Pointer to pointer (`**`).
- NULL pointers and safe pointer initialization.
- Pass by reference using pointers and references.
- Arrays and pointers relationship.
- Pointer arithmetic and pointer comparison.

This chapter forms the **foundation for advanced C++ topics** such as **dynamic memory allocation, linked lists, trees, graphs, and memory management**.

---

> *“Pointers are not difficult—they simply help us understand where data lives in memory and how to access it efficiently.”* 🌸
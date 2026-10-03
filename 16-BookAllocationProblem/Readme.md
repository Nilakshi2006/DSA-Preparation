## 🚀 DSA Journey -- Chapter 16: Book Allocation Problem (C++)
Welcome to Chapter 16 of my Data Structures & Algorithms (DSA)
journey! 💻📚
In this chapter, I solved the Book Allocation Problem using an
optimized Binary Search on Answer approach.
The goal is to allocate books among students such that:
Each student gets at least one book.
Books are allocated in contiguous order.
A book cannot be shared between students.
We need to minimize the maximum number of pages assigned to any
student.
This is an important example of Binary Search on Answer, where we
don't directly search for an element. Instead, we search for the minimum
possible value that satisfies a given condition.
---
## 📚 Problem Statement
Given an array `arr` where:
`arr[i]` represents the number of pages in the `i-th` book.
`n` is the total number of books.
`m` is the number of students.
Allocate the books to students such that:
Each student receives at least one book.
Each student receives a contiguous sequence of books.
The maximum number of pages assigned to any student is minimized.
Return the minimum possible value of the maximum pages assigned to a
student.
---
💡 Example
``` text
arr = [2, 1, 3, 4]
m = 2
```
One possible allocation is:
``` text
Student 1 → [2, 1, 3] = 6 pages
Student 2 → [4]       = 4 pages
```
Maximum pages assigned to a student:
``` text
max(6, 4) = 6
```
Another allocation:
``` text
Student 1 → [2, 1] = 3 pages
Student 2 → [3, 4] = 7 pages
```
Maximum pages:
``` text
max(3, 7) = 7
```
Therefore, the minimum possible maximum is:
``` text
6
```
---
📚 Program Covered
---
#        File Name                         Concept
---
01        `01.BinarySearchApproach.cpp`     Binary Search on Answer for
Book Allocation
---
---
🎯 Main Concept --- Binary Search on Answer
The important idea is that we are not searching for an element inside
the array.
Instead, we are searching for the possible answer.
For:
``` text
arr = [2, 1, 3, 4]
```
The total number of pages is:
``` text
2 + 1 + 3 + 4 = 10
```
So the answer lies somewhere between:
``` text
0 → 10
```
We use Binary Search on this range.
For every possible maximum page limit `mid`, we check:
> Can all books be allocated to `m` students without giving any student
> more than `mid` pages?
This checking is done using the `isValid()` function.
---
💻 Language Used
C++
Concepts Used
Arrays
Vectors
Binary Search
Binary Search on Answer
Greedy Approach
Functions
Loops
Conditional Statements
Time and Space Complexity
---
📂 Folder Structure
``` text
16-BookAllocationProblem/

│── output/

│── 01.BinarySearchApproach.cpp

└── README.md
```
---
📍 Program 1 --- Binary Search Approach
🎯 Objective
Find the minimum possible value of the maximum number of pages assigned
to any student.
---
🧠 Key Idea
Suppose:
``` text
arr = [2, 1, 3, 4]
m = 2
```
We need to find the smallest maximum page limit that allows us to
distribute all books among 2 students.
We try a maximum page limit and check whether the books can be allocated
within that limit.
For example:
``` text
Maximum allowed pages = 5
```
Allocation:
``` text
Student 1 → [2, 1] = 3
Student 2 → [3]    = 3
Student 3 → [4]    = 4
```
This requires 3 students.
Since we only have:
``` text
m = 2
```
`5` is not a valid answer.
Now try a larger value:
``` text
Maximum allowed pages = 6
```
Allocation:
``` text
Student 1 → [2, 1, 3] = 6
Student 2 → [4]       = 4
```
Only 2 students are required.
Therefore, `6` is valid.
---
🔍 Step 1 --- Create the `isValid()` Function
The `isValid()` function checks whether a particular maximum page limit
can be used to allocate all books among the given number of students.
``` cpp
bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages)
```
Parameters
Parameter           Meaning
---
`arr`               Array containing pages in each book
`n`                 Number of books
`m`                 Number of students
`maxAllowedPages`   Maximum pages a student can receive
---
🧠 Logic of `isValid()`
We start with:
``` cpp
int stu = 1, pages = 0;
```
Initially:
``` text
stu = 1
pages = 0
```
This means we start allocating books to the first student.
---
Step 2 --- Check Each Book
``` cpp
for(int i = 0; i < n; i++)
```
We traverse every book.
First, we check:
``` cpp
if(arr[i] > maxAllowedPages){
    return false;
}
```
If a single book itself contains more pages than the allowed maximum,
then allocation is impossible.
For example:
``` text
arr[i] = 10
maxAllowedPages = 6
```
A student must take the entire book, so this book cannot be allocated.
Therefore:
``` text
return false
```
---
Step 3 --- Add Pages to Current Student
If adding the current book does not exceed the maximum allowed pages:
``` cpp
if(pages + arr[i] <= maxAllowedPages){
    pages += arr[i];
}
```
We continue giving books to the current student.
Example:
``` text
maxAllowedPages = 6

Current pages = 3
Current book = 3

3 + 3 <= 6
```
So:
``` text
pages = 6
```
---
Step 4 --- Move to the Next Student
If adding the current book exceeds the maximum allowed pages:
``` cpp
else{
    stu++;
    pages = arr[i];
}
```
We start allocating books to the next student.
For example:
``` text
Current pages = 6
Current book = 4
Maximum allowed = 6
```
Since:
``` text
6 + 4 > 6
```
we move to the next student:
``` text
stu++;
pages = 4;
```
---
Step 5 --- Check Number of Students
At the end:
``` cpp
return stu > m ? false : true;
```
If the number of students required is greater than the available
students:
``` text
stu > m
```
then the allocation is invalid.
Otherwise, it is valid.
---
💻 Complete `isValid()` Function
``` cpp
bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages){
    int stu = 1, pages = 0;

    for(int i = 0; i < n; i++){

        if(arr[i] > maxAllowedPages){
            return false;
        }

        if(pages + arr[i] <= maxAllowedPages){
            pages += arr[i];
        }
        else{
            stu++;
            pages = arr[i];
        }
    }

    return stu > m ? false : true;
}
```
---
🔎 Step 6 --- Calculate the Search Range
Inside `allocateBooks()`:
``` cpp
int sum = 0;
```
We calculate the total number of pages:
``` cpp
for(int i = 0; i < n; i++){
    sum += arr[i];
}
```
For:
``` text
arr = [2, 1, 3, 4]
```
we get:
``` text
sum = 10
```
Therefore, our search range becomes:
``` cpp
int st = 0, end = sum;
```
So:
``` text
Start = 0
End   = 10
```
---
🔍 Step 7 --- Binary Search
We calculate the middle:
``` cpp
int mid = st + (end - st) / 2;
```
This is the safe way to calculate the middle.
Instead of:
``` cpp
(st + end) / 2
```
we use:
``` cpp
st + (end - st) / 2
```
to avoid potential integer overflow.
---
✅ Step 8 --- Check Whether `mid` is Valid
``` cpp
if(isValid(arr, n, m, mid)){
```
If `mid` is valid, it means we can allocate all books using `mid` as the
maximum allowed pages.
Therefore, we store it:
``` cpp
ans = mid;
```
But we want to minimize the answer.
So we search on the left:
``` cpp
end = mid - 1;
```
---
❌ Step 9 --- If `mid` is Invalid
If:
``` cpp
isValid(arr, n, m, mid)
```
returns false, then `mid` is too small.
We need a larger maximum page limit.
So we search on the right:
``` cpp
st = mid + 1;
```
---
💻 Complete Code
``` cpp
#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages){
    int stu = 1, pages = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] > maxAllowedPages){
            return false;
        }

        if(pages + arr[i] <= maxAllowedPages){
            pages += arr[i];
        }
        else{
            stu++;
            pages = arr[i];
        }
    }

    return stu > m ? false : true;
}

int allocateBooks(vector<int>& arr, int n, int m){
    int sum = 0;

    // Range of possible answer
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    int ans = -1;
    int st = 0, end = sum;

    while(st <= end){
        int mid = st + (end - st) / 2;

        if(isValid(arr, n, m, mid)){
            ans = mid;

            // Search on the left
            end = mid - 1;
        }
        else{
            // Search on the right
            st = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {2, 1, 3, 4};

    int n = 4;
    int m = 2;

    cout << allocateBooks(arr, n, m) << endl;

    return 0;
}
```
---
🔍 Dry Run
Input
``` text
arr = [2, 1, 3, 4]
n = 4
m = 2
```
Total pages:
``` text
2 + 1 + 3 + 4 = 10
```
Initial search range:
``` text
st = 0
end = 10
```
---
Iteration 1
``` text
st = 0
end = 10
mid = 5
```
Check:
``` text
maxAllowedPages = 5
```
Allocation:
``` text
Student 1 → [2, 1] = 3
Student 2 → [3]    = 3
Student 3 → [4]    = 4
```
Students required:
``` text
3
```
Available:
``` text
2
```
Therefore:
``` text
5 is invalid ❌
```
Search right:
``` text
st = 6
```
---
Iteration 2
``` text
st = 6
end = 10
mid = 8
```
Check:
``` text
maxAllowedPages = 8
```
Allocation:
``` text
Student 1 → [2, 1, 3] = 6
Student 2 → [4]       = 4
```
Students required:
``` text
2
```
Therefore:
``` text
8 is valid ✅
```
Store:
``` text
ans = 8
```
Search left:
``` text
end = 7
```
---
Iteration 3
``` text
st = 6
end = 7
mid = 6
```
Check:
``` text
maxAllowedPages = 6
```
Allocation:
``` text
Student 1 → [2, 1, 3] = 6
Student 2 → [4]       = 4
```
Students required:
``` text
2
```
Therefore:
``` text
6 is valid ✅
```
Store:
``` text
ans = 6
```
Search left:
``` text
end = 5
```
---
Iteration 4
``` text
st = 6
end = 5
```
Since:
``` text
st > end
```
Binary Search stops.
Final answer:
``` text
6
```
---
📊 Dry Run Table
Step     `st`   `end`   `mid` Valid?   Action
---
1           0      10       5 ❌       Search right
2           6      10       8 ✅       Store answer, search left
3           6       7       6 ✅       Store answer, search left
4           6       5     --- ---      Stop
Final Answer
``` text
6
```
---
🧠 Why Binary Search Works Here
The important property is monotonicity.
Suppose:
``` text
6 is valid
```
Then:
``` text
7 is also valid
8 is also valid
9 is also valid
10 is also valid
```
because allowing more pages per student cannot make a previously
possible allocation impossible.
Similarly, if:
``` text
5 is invalid
```
then smaller values such as:
``` text
4, 3, 2, 1
```
will also be invalid.
Therefore, we get a pattern like:
``` text
Invalid Invalid Invalid | Valid Valid Valid Valid
                         ↑
                    Minimum Answer
```
This is exactly the type of problem where Binary Search on Answer
can be used.
---
## 📌 Important Pattern
For Binary Search on Answer problems, ask:
> **Can I check whether a particular answer is possible?**
If the answer follows a monotonic pattern:
``` text
False False False True True True
```
or:
``` text
True True True False False False
```
then Binary Search may be applicable.
---
🧪 Example 1
Input
``` cpp
vector<int> arr = {2, 1, 3, 4};
int n = 4;
int m = 2;
```
Output
``` text
6
```
---
🧪 Example 2
Input
``` cpp
vector<int> arr = {10, 20, 30, 40};
int n = 4;
int m = 2;
```
Possible allocation:
``` text
Student 1 → [10, 20, 30] = 60
Student 2 → [40]         = 40
```
Maximum:
``` text
60
```
Another allocation:
``` text
Student 1 → [10, 20] = 30
Student 2 → [30, 40] = 70
```
Maximum:
``` text
70
```
Therefore:
``` text
Output = 60
```
---
🧪 Example 3
Input
``` cpp
vector<int> arr = {12, 34, 67, 90};
int n = 4;
int m = 2;
```
One valid allocation is:
``` text
Student 1 → [12, 34, 67] = 113
Student 2 → [90]         = 90
```
Therefore:
``` text
Output = 113
```
---
⚙️ How the Logic Works
Case 1 --- Current Book Can Be Added
``` cpp
if(pages + arr[i] <= maxAllowedPages){
    pages += arr[i];
}
```
If adding the current book does not exceed the allowed limit, keep it
with the current student.
---
Case 2 --- Current Book Cannot Be Added
``` cpp
else{
    stu++;
    pages = arr[i];
}
```
If adding the book exceeds the limit, start a new student.
---
Case 3 --- A Book Is Larger Than the Allowed Limit
``` cpp
if(arr[i] > maxAllowedPages){
    return false;
}
```
A single book cannot be divided, so if it exceeds the limit, the current
limit is impossible.
---
Case 4 --- Too Many Students Are Required
``` cpp
return stu > m ? false : true;
```
If we need more students than available:
``` text
stu > m
```
the current maximum page limit is invalid.
---
📈 Complexity Analysis
Let:
``` text
n = number of books
S = total number of pages
```
Operation                 Time Complexity         Space Complexity
---
Checking one page limit   `O(n)`                  `O(1)`
Binary Search on Answer   `O(log S)` iterations   `O(1)`
Overall                   `O(n log S)`            `O(1)`
Therefore:
``` text
Time Complexity = O(n log S)
Space Complexity = O(1)
```
where `S` is the sum of all pages.
---
💡 Why `O(n log S)`?
For every Binary Search iteration, we traverse all `n` books inside
`isValid()`.
The answer range is approximately:
``` text
0 → S
```
where `S` is the total number of pages.
Binary Search takes:
``` text
O(log S)
```
iterations.
Therefore:
``` text
O(n) × O(log S)
```
gives:
``` text
O(n log S)
```
---
🔥 Binary Search on Answer Template
This problem follows a very useful pattern:
``` cpp
int st = minimumPossible;
int end = maximumPossible;

while(st <= end){

    int mid = st + (end - st) / 2;

    if(isValid(mid)){
        ans = mid;

        // Search for a smaller valid answer
        end = mid - 1;
    }
    else{
        // Need a larger answer
        st = mid + 1;
    }
}
```
The important part is the `isValid()` function.
---
⚠️ Important Notes
1. Books Must Be Allocated Contiguously
For:
``` text
[2, 1, 3, 4]
```
we cannot allocate:
``` text
Student 1 → 2, 3
Student 2 → 1, 4
```
because the books must be allocated in their given order.
---
2. A Book Cannot Be Divided
If:
``` text
book = 10 pages
```
then the 10 pages must go to a single student.
We cannot divide it between students.
---
3. Every Student Should Receive Books
The standard problem assumes:
``` text
m <= n
```
where `m` is the number of students and `n` is the number of books.
---
4. The Search Range
The current code uses:
``` cpp
int st = 0;
int end = sum;
```
A tighter lower bound can also be used:
``` text
max(arr)
```
because the answer can never be smaller than the largest single book.
For example:
``` text
arr = [2, 1, 3, 4]
```
The answer cannot be less than:
``` text
4
```
because someone must receive the book containing 4 pages.
---
## ❌ Common Mistakes
---
Mistake                      Correct Approach
---
Trying every possible        Use Binary Search on Answer
allocation
Forgetting that books must   Allocate books in order
remain contiguous
Dividing a book between      A book must go to one student
students
Not checking                 Return `false`
`arr[i] > maxAllowedPages`
Moving left when `mid` is    Search right
invalid
Moving right when `mid` is   Search left for a smaller answer
valid
Using `(st + end) / 2`       Use `st + (end - st) / 2`
Ignoring the number of       Check `stu > m`
students
---
🎓 Interview Tip
Be ready to explain:
What is the Book Allocation Problem?
Why can Binary Search be applied here?
What does `isValid()` do?
Why do we search on the answer instead of the array?
Why does an invalid `mid` make us move right?
Why does a valid `mid` make us move left?
Why is the complexity `O(n log S)`?
Why can't books be divided between students?
Why must the books be allocated in contiguous order?
Why can the lower bound be `max(arr)`?
---
🌱 What This Chapter Builds
This problem strengthens the concept of:
Binary Search
Binary Search on Answer
Monotonic Search Space
Greedy Validation
Optimization Problems
Time and Space Complexity
The key lesson is:
``` text
Don't always search for an element.

Sometimes search for the answer.
```
---
🚀 Binary Search on Answer Pattern
A useful way to recognize these problems is:
``` text
1. Identify the possible answer range.
2. Pick the middle value.
3. Check whether the middle value is possible.
4. If possible → try for a better/smaller answer.
5. If impossible → move toward larger values.
6. Continue until the minimum valid answer is found.
```
For this problem:
``` text
Possible answer
       ↓
Maximum pages allowed per student
       ↓
isValid(mid)
       ↓
Can all books be allocated?
       ↓
Yes → Search Left
No  → Search Right
```
---
🏆 Final Output
For:
``` cpp
vector<int> arr = {2, 1, 3, 4};
int n = 4;
int m = 2;
```
the program produces:
``` text
6
```
---
> **"In Binary Search on Answer, don't ask where the answer is --- ask
> whether a possible answer is valid."** 💻✨
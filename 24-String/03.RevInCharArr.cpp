#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    char ch[] = "Nilakshi";
    int n = strlen(ch);
    int start = 0, end = n - 1;
    while (start < end)
    {
        swap(ch[start], ch[end]);
        start++;
        end--;
    }
    cout << ch;
    return 0;
}
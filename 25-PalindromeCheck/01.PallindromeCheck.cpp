#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isAlphaNum(char ch) {

        if ((ch >= '0' && ch <= '9') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z')) {

            return true;
        }
        else {
            return false;
        }
    }

    bool isPalindrome(string s) {

        int n = s.length();

        int st = 0;
        int end = n - 1;

        while (st < end) {

            if (!isAlphaNum(s[st])) {
                st++;
                continue;
            }

            if (!isAlphaNum(s[end])) {
                end--;
                continue;
            }

            if (tolower(s[st]) != tolower(s[end])) {
                return false;
            }
            else {
                st++;
                end--;
            }
        }

        return true;
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    if (obj.isPalindrome(s)) {
        cout << "Palindrome" << endl;
    }
    else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}
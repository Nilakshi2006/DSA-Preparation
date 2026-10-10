
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    int n = s.length();
    string ans = "";

    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++) {
        // Store word
        string word = "";

        while (i < n && s[i] != ' ') {
            word += s[i];
            i++;
        }

        // Reverse word
        reverse(word.begin(), word.end());

        if (word.length() > 0) {
            ans += " " + word;
        }
    }

    return ans.empty() ? "" : ans.substr(1);
}

int main() {
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    cout << "Reversed words: " << reverseWords(s) << endl;

    return 0;
}

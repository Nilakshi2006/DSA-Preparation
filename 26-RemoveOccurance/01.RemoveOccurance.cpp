#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string removeOccurrences(string s, string part) {

        while (s.length() > 0 && s.find(part) < s.length()) {

            s.erase(s.find(part), part.length());
        }

        return s;
    }
};

int main() {

    Solution obj;

    string s, part;

    cout << "Enter the string: ";
    getline(cin, s);

    cout << "Enter the part to remove: ";
    getline(cin, part);

    string result = obj.removeOccurrences(s, part);

    cout << "After removing all occurrences: " << result << endl;

    return 0;
}
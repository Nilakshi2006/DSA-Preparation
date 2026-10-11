
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    int idx = 0;

    for (int i = 0; i < n; i++) {
        char ch = chars[i];
        int count = 0;

        while (i < n && chars[i] == ch) {
            count++;
            i++;
        }

        chars[idx++] = ch;

        if (count > 1) {
            string str = to_string(count);

            for (char dig : str) {
                chars[idx++] = dig;
            }
        }

        i--;
    }

    return idx;
}

int main() {
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    int len = compress(chars);

    cout << "Compressed length: " << len << endl;
    cout << "Compressed string: ";

    for (int i = 0; i < len; i++) {
        cout << chars[i];
    }

    cout << endl;

    return 0;
}

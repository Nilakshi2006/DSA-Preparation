
#include <iostream>
#include <string>
using namespace std;

bool isfreqSame(int freq1[], int freq2[]) {
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int freq[26] = {0};

    for (int i = 0; i < s1.length(); i++) {
        freq[s1[i] - 'a']++;
    }

    int windowSize = s1.length();

    for (int i = 0; i < s2.length(); i++) {
        int windowIdx = 0, strIdx = i;
        int windowFreq[26] = {0};

        while (windowIdx < windowSize && strIdx < s2.length()) {
            windowFreq[s2[strIdx] - 'a']++;
            windowIdx++;
            strIdx++;
        }

        if (isfreqSame(freq, windowFreq)) {
            return true;
        }
    }

    return false;
}

int main() {
    string s1, s2;

    cout << "Enter s1: ";
    cin >> s1;

    cout << "Enter s2: ";
    cin >> s2;

    if (checkInclusion(s1, s2)) {
        cout << "Permutation exists";
    } else {
        cout << "Permutation does not exist";
    }

    return 0;
}
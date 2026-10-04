#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int>& stalls, int n, int k, int minAllowedDistance) {
    int cows = 1;
    int lastStall = stalls[0];

    for (int i = 1; i < n; i++) {

        if (stalls[i] - lastStall >= minAllowedDistance) {
            cows++;
            lastStall = stalls[i];
        }

        if (cows == k) {
            return true;
        }
    }

    return false;
}

int aggressiveCows(vector<int>& stalls, int n, int k) {

    sort(stalls.begin(), stalls.end());

    int st = 1;
    int end = stalls[n - 1] - stalls[0];
    int ans = -1;

    while (st <= end) {

        int mid = st + (end - st) / 2;

        if (isValid(stalls, n, k, mid)) {
            ans = mid;
            st = mid + 1;       // try for a larger distance
        }
        else {
            end = mid - 1;      // distance is too large
        }
    }

    return ans;
}

int main() {

    vector<int> stalls = {1, 2, 4, 8, 9};

    int n = stalls.size();
    int k = 3;

    cout << aggressiveCows(stalls, n, k) << endl;

    return 0;
}
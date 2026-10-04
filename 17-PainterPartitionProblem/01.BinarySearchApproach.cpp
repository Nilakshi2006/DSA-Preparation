#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int>& arr, int n, int m, int maxAllowedTime) {
    int painters = 1;
    int time = 0;

    for (int i = 0; i < n; i++) {

        // If a single board takes more time than allowed
        if (arr[i] > maxAllowedTime) {
            return false;
        }

        // Assign board to current painter
        if (time + arr[i] <= maxAllowedTime) {
            time += arr[i];
        }
        else {
            // Give board to next painter
            painters++;
            time = arr[i];
        }
    }

    return painters <= m;
}

int minTimeToPaint(vector<int>& arr, int n, int m) {
    int sum = 0;
    int maxBoard = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        maxBoard = max(maxBoard, arr[i]);
    }

    int st = maxBoard;
    int end = sum;
    int ans = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (isValid(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            st = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {40, 30, 10, 20};
    int n = arr.size();
    int m = 2;

    cout << minTimeToPaint(arr, n, m);

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void mergeArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    int idx = m + n - 1;
    int i = m - 1;
    int j = n - 1;

    while (i >= 0 && j >= 0) {

        if (nums1[i] > nums2[j]) {
            nums1[idx] = nums1[i];
            idx--;
            i--;
        }
        else {
            nums1[idx] = nums2[j];
            idx--;
            j--;
        }
    }

    // Copy remaining elements of nums2
    while (j >= 0) {
        nums1[idx] = nums2[j];
        idx--;
        j--;
    }
}

int main() {

    vector<int> nums1 = {1, 3, 5, 0, 0, 0};
    vector<int> nums2 = {2, 4, 6};

    int m = 3;
    int n = 3;

    mergeArrays(nums1, m, nums2, n);

    cout << "Merged array: ";

    for (int i = 0; i < m + n; i++) {
        cout << nums1[i] << " ";
    }

    return 0;
}
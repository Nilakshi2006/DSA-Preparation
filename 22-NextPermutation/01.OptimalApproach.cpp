#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int pivot = -1;

    // Step 1: Find pivot
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            pivot = i;
            break;
        }
    }

    // If no pivot, this is the last permutation
    if (pivot == -1) {
        sort(nums.begin(), nums.end());
        return;
    }

    // Step 2: Find the element greater than nums[pivot]
    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] > nums[pivot]) {
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    // Step 3: Reverse the elements after pivot
    int i = pivot + 1;
    int j = n - 1;

    while (i < j) {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}

int main() {

    vector<int> nums = {1, 2, 5, 4, 3};

    nextPermutation(nums);

    cout << "Next Permutation: ";

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
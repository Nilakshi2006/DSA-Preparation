#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (freq[nums[i]] == 1) {
            return nums[i];
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4};

    cout << "Single element: " << singleNonDuplicate(nums);

    return 0;
}
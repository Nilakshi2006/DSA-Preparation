#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> freq;
    int n = nums.size();

    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }

    // Find majority element
    for (int i = 0; i < n; i++) {
        if (freq[nums[i]] > n / 2) {
            return nums[i];
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {2, 2, 1, 2, 3, 2, 2};

    cout << "Majority Element = " << majorityElement(nums);

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int st = 0, end = n - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        // Single element at start
        if (mid == 0 && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }

        // Single element at end
        if (mid == n - 1 && nums[mid] != nums[mid - 1]) {
            return nums[mid];
        }

        // Single element in the middle
        if (nums[mid] != nums[mid - 1] &&
            nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }

        // Check whether we are on the first or second element of a pair
        if (mid % 2 == 0) {
            if (nums[mid] == nums[mid + 1]) {
                // Pair is correct, go right
                st = mid + 2;
            } else {
                // Single element is on the left
                end = mid - 1;
            }
        }
        else {
            if (nums[mid] == nums[mid - 1]) {
                // Pair is correct, go right
                st = mid + 1;
            } else {
                // Single element is on the left
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5, 5};

    cout << singleNonDuplicate(nums);

    return 0;
}
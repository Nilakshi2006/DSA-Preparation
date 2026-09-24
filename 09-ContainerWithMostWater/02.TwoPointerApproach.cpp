#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int> &height) {
    int maxArea = 0;
    int n = height.size();

    int lp = 0;
    int rp = n - 1;

    while (lp < rp) {
        int width = rp - lp;
        int height1 = min(height[lp], height[rp]);
        int newArea = width * height1;

        maxArea = max(maxArea, newArea);

        if (height[lp] < height[rp]) {
            lp++;
        } else {
            rp--;
        }
    }

    return maxArea;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << "Maximum Area = " << maxArea(height);

    return 0;
}
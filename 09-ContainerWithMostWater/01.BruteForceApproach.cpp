#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int> &height) {
    int maxArea = 0;
    int n = height.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int width = j - i;
            int height1 = min(height[i], height[j]);
            int newArea = width * height1;

            maxArea = max(maxArea, newArea);
        }
    }

    return maxArea;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << "Maximum Area = " << maxArea(height);

    return 0;
}
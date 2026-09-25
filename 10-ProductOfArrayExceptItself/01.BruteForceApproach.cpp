#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> product(vector<int> &nums)    {
    int n=nums.size();
    vector<int>ans(n,1);

   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i!=j){
            ans[i]=ans[i]*nums[j];
        }
    }
}
return ans;
}
int main() {
    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = product(nums);

    cout << "Product is = ";

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
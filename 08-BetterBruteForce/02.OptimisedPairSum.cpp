//Using 2 pointer approach
#include <iostream>
#include<vector>
using namespace std;
vector<int>pairSum(vector<int>nums,int target){
    vector<int>ans;
    int n=nums.size();
   int i=0,j=n-1;
while(i<j){
  int pairSum=nums[i]+nums[j];
  if(pairSum>target){
    j--;
  }else if(pairSum<target){
    i++;
  }else{
    ans.push_back(i);
    ans.push_back(j);
    return ans;
  }
}
}
int main()
{

    vector<int>nums={2,7,1,15};
    int target=17;

    vector<int>ans=pairSum(nums,target);
    //Stores value of vector arr at index 0 and 1 
    cout<<ans[0]<<","<<ans[1]<<endl;

    return 0;
}
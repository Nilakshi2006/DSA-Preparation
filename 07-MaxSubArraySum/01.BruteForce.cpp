#include <iostream>
#include<vector>
#include <climits>
using namespace std;

int main()
{
int n=5;
    int arr[n]={1,2,3,4,5};
    int maxSum=INT_MIN;
for(int start=0;start<n;start++){
    int currSum=0;
    for(int end=start;end<n;end++){
       currSum+=arr[end];
       maxSum=max(currSum,maxSum);
    }
}
cout<<"Maximum Subarray Sum is: "<<maxSum;
    return 0;
}
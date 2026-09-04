#include <iostream>
#include<vector>
using namespace std;
void reverse(vector<int>& arr){
    int start=0;
    int end=arr.size()-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
int main()
{
vector<int>arr={1,2,3,4,5};
cout<<"Original Array is: ";
for(int value:arr){
    cout<<value<<" ";
}
cout<<endl;
reverse(arr);
    cout<<"Reversed Array is: ";
for(int value:arr){
    cout<<value<<" ";
}
    return 0;
}
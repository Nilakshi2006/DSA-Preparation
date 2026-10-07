#include <iostream>
#include<vector>
using namespace std;

int main()
{
//Intialization of vector arr
vector<int>arr;
cout<<arr.size()<<endl;
//add element in arr
    arr.push_back(1);
arr.push_back(2);
arr.push_back(3);
arr.push_back(4);
arr.push_back(5);
arr.emplace_back(6);//similar to push_back

//Delete last element
arr.pop_back();

//View element at specific position
cout<<"Element at index 3 is: "<<arr[3]<<endl;
cout<<"Element at index 2 is: "<<arr.at(2)<<endl;

//to view front element
cout<<"front element is: "<<arr.front()<<endl;

//to view last element
cout<<"Back Element is: "<<arr.back()<<endl;

//erase-delete elem at specific pos
arr.erase(arr.begin()+1);

//insert-add elem at specific pos
arr.insert(arr.begin()+1,2);

//clear-to clear every elem
//arr.clear();

//empty-give 0 if not empty and 1 if empty
cout<<"check if arr is empty: "<<arr.empty()<<endl;
//view each element
cout<<"Arr Element: ";
for(int val :arr){
    cout<<val<<" ";
}
    return 0;
}
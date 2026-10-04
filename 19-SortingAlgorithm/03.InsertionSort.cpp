//Ascending order..

// #include <iostream>
// using namespace std;
// //n^2 time complexity
// void insertionSort(int arr[],int n){
//     for(int i=1;i<n;i++)//start from unsorted part
//     {
//   int curr=arr[i];
//   int prev=i-1;
//   while(prev>=0 && arr[prev]>curr){
//     arr[prev+1]=arr[prev];
//     prev--;
//   }
//   arr[prev+1]=curr;//placing curr elem in correct pos

//   }
// }
// void printArray(int arr[],int n){
// for(int i=0;i<n;i++){
//     cout<<arr[i]<<" ";
// }
// cout<<endl;
// }
// int main()
// {

//     int n=5;
//     int arr[]={4,1,5,3,2};

//     insertionSort(arr,n);
//     printArray(arr,n);
//     return 0;
// }

//Descending Order..
#include <iostream>
using namespace std;
//n^2 time complexity
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++)//start from unsorted part
    {
  int curr=arr[i];
  int prev=i-1;
  while(prev>=0 && arr[prev]<curr){
    arr[prev+1]=arr[prev];
    prev--;
  }
  arr[prev+1]=curr;//placing curr elem in correct pos

  }
}
void printArray(int arr[],int n){
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
}
int main()
{

    int n=5;
    int arr[]={4,1,5,3,2};

    insertionSort(arr,n);
    printArray(arr,n);
    return 0;
}
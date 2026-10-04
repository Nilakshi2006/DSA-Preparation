//Ascending Order..

// #include <iostream>
// using namespace std;
// //n^2 time complexity
// void selectionSort(int arr[],int n){
//     for(int i=0;i<n-1;i++){
//    int smallestIdx=i; //usorted part starting
//    for(int j=i+1;j<n;j++){
//     if(arr[j]<=arr[smallestIdx]){
//         smallestIdx=j;
//     }
// }
// swap(arr[i],arr[smallestIdx]);
// }
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

//     selectionSort(arr,n);
//     printArray(arr,n);
//     return 0;
// }


//Descending Order..
#include <iostream>
using namespace std;
//n^2 time complexity
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
   int smallestIdx=i; //usorted part starting
   for(int j=i+1;j<n;j++){
    if(arr[j]>=arr[smallestIdx]){
        smallestIdx=j;
    }
}
swap(arr[i],arr[smallestIdx]);
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

    selectionSort(arr,n);
    printArray(arr,n);
    return 0;
}
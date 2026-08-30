#include <iostream>
using namespace std;

int main()
{

    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;

    int arr[n];
    int size=sizeof(arr)/sizeof(int);
    cout<<"Size of array is: "<<size;

    return 0;
}
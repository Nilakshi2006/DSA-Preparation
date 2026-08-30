#include <iostream>
using namespace std;

int main()
{

    int size=5;
    int arr[size];
    cout<<"Enter five Elements of Arr: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Element of arraya are: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}
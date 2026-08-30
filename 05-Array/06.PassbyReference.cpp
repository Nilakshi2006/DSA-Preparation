#include <iostream>
using namespace std;
void change(int arr[],int size){
    cout<<"\nArray in Function"<<endl;
    for(int i=0;i<size;i++){
        arr[i]=2*arr[i];
        cout<<arr[i];
    }
    cout<<endl;
}
int main()
{
int arr[]={1,2,3};
int size=3;
    cout<<"\nArray in Main"<<endl;
    for(int i=0;i<size;i++){
cout<<arr[i];
    }
change(arr,3);
    return 0;
}
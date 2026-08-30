#include <iostream>
using namespace std;

int main()
{
int n=5;
    int arr[n]={1,2,3,4,5};
    int sum=0;
    int product=1;

    for(int i=0;i<n;i++){
        sum+=arr[i];
        product*=arr[i];
    }
    cout<<"Sum is: "<<sum<<endl;
    cout<<"Product is: "<<product<<endl;

    return 0;
}
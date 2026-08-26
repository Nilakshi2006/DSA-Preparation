#include <iostream>
using namespace std;
int sumN(int n){
    int sum=0;
    for(int i=0;i<=n;i++){
        sum=sum+i;
    }
    return sum;
}
int main()
{

    cout<<sumN(10)<<endl;

    return 0;
}
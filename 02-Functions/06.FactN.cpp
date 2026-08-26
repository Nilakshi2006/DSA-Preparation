#include <iostream>
using namespace std;
int fact(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact=fact*i;
    }
    return fact;
}
int main()
{

    cout<<"Factorial is: "<<fact(5);

    return 0;
}
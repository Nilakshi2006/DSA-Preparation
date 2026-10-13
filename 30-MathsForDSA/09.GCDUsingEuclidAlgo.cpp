#include <iostream>
using namespace std;
int gcd(int a,int b){
    if(a>0 && b>0){
        if(a>b){
            a%b;
        }else{
            b%a;
        }
    }
    if(a==0){
        return b;
    }else{
        return a;
    }
}

int main()
{

    cout<<gcd(0,24);

    return 0;
}
#include <iostream>
using namespace std;
 void Digit(int n){
     int sum=0;
    while(n!=0){
        int digit=n%10;
       sum+=digit;
        n=n/10;
    }
    cout<<sum;
 }
int main()
{

    int n=2234;
    Digit(n);

    return 0;
}
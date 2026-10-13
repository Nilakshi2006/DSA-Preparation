#include <iostream>
using namespace std;
 void Digit(int n){
     int count=0;
    while(n!=0){
        int digit=n%10;
       count++;
        n=n/10;
    }
    cout<<count;
 }
int main()
{

    int n=2234;
    Digit(n);

    return 0;
}
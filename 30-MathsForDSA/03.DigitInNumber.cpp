#include <iostream>
using namespace std;
 void Digit(int n){
    while(n!=0){
        int digit=n%10;
        cout<<digit<<endl;
        n=n/10;
    }
 }
int main()
{

    int n=2234;
    Digit(n);

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
int num, rev=0;
cout<<"Enter the Number: ";
cin>>num;
int org=num;
while(num>0){
    int digit=num%10;
    rev=(rev*10)+digit;
   num=num/10;
}
cout<<"Original Number: "<<org<<endl;
cout<<"Reversd Number: "<<rev<<endl;

    return 0;
}
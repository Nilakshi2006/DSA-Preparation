#include <iostream>
using namespace std;
int minOfTwo(int a,int b){
if(a>b){
   return b;
}
else{
   return a;
}

}
int main()
{
    cout<<"Minimum is: "<<minOfTwo(10,15);
    return 0;
}
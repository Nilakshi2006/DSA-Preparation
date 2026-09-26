 #include <iostream>
 using namespace std;
 void chnageA(int*ptr){ //pass by reference using pointer
*ptr=20;
 }
 int main()
 {
 int a=10;
 chnageA(&a);
 cout<<"Value of a: "<<a<<endl;
     
 
     return 0;
 }
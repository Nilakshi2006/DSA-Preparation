#include <iostream>
#include<vector>
using namespace std;

int main()
{
vector<int>num;
num.push_back(1);
num.push_back(2);
num.push_back(3);
num.push_back(4);
num.push_back(5);
num.push_back(6);    

cout<<"Size of Vector is: "<<num.size()<<endl;
cout<<"Capacity of Vector is: "<<num.capacity()<<endl;
    return 0;
}
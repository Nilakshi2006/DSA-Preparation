#include <iostream>
using namespace std;

int main()
{

    int n=4;
   
    for(char i='A';i<=('A'+n);i++)
    //i<=(65+4)
    {
        for(int j='A';j<=i;j++){
            cout<<i;
        }
        cout<<endl;
    }

    return 0;
}

// Output
// A
// BB
// CCC
// DDDD
// EEEEE
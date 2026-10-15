#include <iostream>
using namespace std;

int main()
{
    // Defining
    //  int matrix[4][3];
    // int rows=4;
    //  int cols=3;
    // Initialization
    int matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int rows = 4;
    int cols = 3;

    //changing specific element
    matrix[2][2]=4;
    
//accessing specific element
cout<<matrix[2][2]<<endl;
    return 0;
}
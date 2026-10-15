#include <iostream>
using namespace std;

int main()
{

    int matrix[2][2]={{1,2},{3,4}};
    int rows=2;
    int cols=2;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
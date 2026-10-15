#include <iostream>
#include <climits>
using namespace std;
int maxRowSum(int mat[][2],int rows,int cols){
    int maxSum=INT_MIN;
    for(int i=0;i<rows;i++){
        int rowSum=0;
        for(int j=0;j<cols;j++){
rowSum+=mat[i][j];
        }
        maxSum=max(maxSum,rowSum);
    }
    return maxSum;

}
int main()
{

    int matrix[2][2]={{1,2},{3,4}};
    int rows=2;
    int cols=2;
   
    cout<<maxRowSum(matrix,rows,cols);
    return 0;
}
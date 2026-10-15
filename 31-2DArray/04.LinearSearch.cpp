#include <iostream>
using namespace std;
pair<int, int> linearSearch(int mat[][2], int rows, int cols, int key){
    for(int i=0;i<rows;i++){
for(int j=0;j<cols;j++){
    if(mat[i][j]==key){
       return {i,j};
    }
}
    }
    return {-1,-1};
}
int main()
{

    int matrix[2][2]={{1,2},{3,4}};
    int rows=2;
    int cols=2;
    pair<int,int> ans=linearSearch(matrix,rows,cols,3);
cout<<ans.first<<","<<ans.second;
    return 0;
}
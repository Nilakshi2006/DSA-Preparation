//With Function
#include <iostream>
using namespace std;
int linear(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i;
        } 
    }
    return -1;
}
int main()
{
int arr[]={4,2,7,8,1,2,5};
int size=7;
int target=8;
    cout<<linear(arr,size,target);

    return 0;
}

//Without using function
// #include <iostream>
// using namespace std;

// int main()
// {
//     int arr[] = {4, 2, 7, 8, 1, 2, 5};
//     int target = 8;
//     bool found = false;
//     int n = sizeof(arr) / sizeof(int);
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == target)
//         {
//             cout << "Array find at Index " << i << endl;
//         }
//     }
//     if (!found)
//     {
//         cout << "Element not Found" << endl;
//     }
//     return 0;
// }
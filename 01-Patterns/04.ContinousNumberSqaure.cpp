#include <iostream>
using namespace std;

int main()
{

    int n = 3;
    int num = 1;//For continous Number(if u dont want ur number to rest fater line)
    for (int i = 0; i < n; i++)
    {
        // int num=1;(when u wantt to reste number line after line)
        for (int j = 0; j < n; j++)
        {
            cout << num;
            num++;
        }
        cout << endl;
    }

    return 0;
}

// Output
// 123
// 456
// 789
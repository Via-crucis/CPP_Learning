
#include <iostream>


using namespace std;

int lowbit(int n)
{
    return n&-n;			//返回由n的二进制中从右往左数第一个1的数。
}

int main ()
{
    int n;
    cin >> n;
    int j = 0;
    int res = 0;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> j;
        while(j) j -= lowbit(j), res++;
        cout << res << " ";
        res = 0;
    }
}

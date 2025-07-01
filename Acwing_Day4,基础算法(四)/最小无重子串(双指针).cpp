#include <iostream>

using namespace std;

const int N = 100100;

int a[N] , s[N];

int main()
{
    int n ;
    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    int res = 0;
    for(int i = 0 ,j = 0; i < n ; i++)
    {
        s[a[i]]++ ;                 //桶排序;
        while (s[a[i]] > 1)
        {
            s[a[j]] --;             //注意是a[j]
            j++ ;
        }
        res = max(res , i - j + 1);     //结算
    }
    cout << res ;
}

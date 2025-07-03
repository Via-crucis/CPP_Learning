#include <iostream>
using namespace std;
const int N = 1000010;

int a[N] , up[N] , down[N];

int hh_u , tt_u , hh_d , tt_d ;

int main()
{
    int n , k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++) cin >> a[i] ;
    
    for(int i = 0 ; i < n ; i++)
    {
        if (hh_d <= tt_d && i - down[hh_d] == k) hh_d++;
        while(hh_d <= tt_d && a[down[tt_d]] >= a[i]) tt_d--;
        down[++tt_d] = i;
        if(i >= k - 1)
        cout<<a[down[hh_d]]<<" ";
    }
    cout<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        if (hh_u <= tt_u && i - up[hh_u] == k) hh_u++;
        while(hh_u <= tt_u && a[up[tt_u]] <= a[i]) tt_u--;
        up[++tt_u] = i;
        if(i >= k - 1)
        cout<<a[up[hh_u]]<<" ";
    }
}
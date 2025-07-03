#include <iostream>
using namespace std;

const int N = 10010;
int a[N] , stack[N] , tt;

int main()
{
    int n , x;
    cin >> n;
    for(int i = 0 ; i < n ; i++) 
    {
        cin >> x;
        while(tt)
        {
            if(x <= stack[tt]) 
            {
                tt-- ;
                continue;
            }
            cout << stack[tt] <<" ";
            stack[++tt] = x;
            break;
        }
        if(!tt) 
        {
            cout<< -1 <<" ";
            tt++;
            stack[tt] = x;
        }
    }
}
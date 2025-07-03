#include <iostream>

using namespace std;

const int M = 1000100 , N = 100010;
char s[M] , p[N] ;
int ne[N];
int n , m;

int main()
{
    
    cin >> n >> p + 1 >> m >> s + 1;
    for(int i = 2 , j = 0 ; i <= n ; i++ )
    {
        while(j && p[i] != p[j+1]) j = ne[j] ;  //判断j是否为0是为了减少一些循环跳转,且防止在一些情况下的死循环（aaaa)。
        if(p[i] == p[j+1]) j++;
        ne[i] = j;
    }
    for(int i = 1 , j = 0 ; i <= m ; i++)
    {
        while(j && s[i] != p[j+1]) j = ne[j];
        if(s[i] == p[j+1]) j++;
        if(j == n)
        {
            cout<<i - n<<" ";
            
            j = ne[j];
        }
    }
}
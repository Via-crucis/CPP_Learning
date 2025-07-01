#include <iostream>
using namespace std;

const int N = 1010;
int a[N][N] , b[N][N];

void op(int b[N][N] , int x1 , int y1 , int x2 , int y2 , int c , int n , int m)
{
    b[x1][y1] += c;
    if(x2 >= n && y2 < m) b[x1][y2+1] -=c;
    if(x2 < n && y2 >= m) b[x2+1][y1] -=c;
    if(x2 < n && y2 < m) b[x2+1][y1] -= c , b[x1][y2+1] -= c, b[x2+1][y2+1] +=c;
}

int main()
{
    int n , m , p;
    cin >> n >> m >> p ;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++) cin >> a[i][j];
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++) b[i][j] = a[i][j] - a[i-1][j] - a[i][j-1] + a[i-1][j-1];
    while(p--)
    {
        int x1,y1,x2,y2,c;
        cin >> x1 >> y1 >> x2 >> y2 >>c;
        op(b , x1 , y1 , x2 , y2 ,c , n , m);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++) 
        {
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] +b[i][j] ;
             cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
        
}
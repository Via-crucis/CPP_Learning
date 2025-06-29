#include <iostream>

using namespace std;

const int N = 100010;

int a[N] , s[N];

int main()
{
    int n ,m;
    cin >> n >> m;
    a[0] = 0;
    s[0] = 0;
    for(int i = 1 ; i < n + 1 ; i++) cin >> a[i];
    for(int i = 1 ; i < n + 1 ; i++) s[i] = a[i] + s[i-1];
    int i,j;
    while(m--)
    {
        cin >> i >> j;
        cout << s[j] - s[i-1] <<endl;
    }
}
#include <iostream>
using namespace std;

const int N = 100010;

int a[N] , b[N];

long long merge_sort(int a[] , int l , int r)
{
    if(l >= r) return 0;
    long long res = merge_sort(a , l , (l + r)/2) + merge_sort(a , (l+r)/2 + 1 , r);
    int mid = (l+r) / 2;
    int i = l ;
    int j = mid+1;
    int k = 0 ;
    while(i <= mid && j <= r)
    {
        if(a[i] <= a[j]) b[k++] = a[i++];
        else
        {
            b[k++] = a[j++];
            res+=mid + 1 - i;
        }
    }
    while(i <= mid) b[k++] = a[i++] ;
    while(j <= r) b[k++] = a[j++];
    for(int m = l,n = 0; m <= r ; m++ , n++) a[m] = b[n];
    return res;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    cout << merge_sort (a , 0 , n-1);
    
}
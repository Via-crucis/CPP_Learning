#include <iostream>
using namespace std;

const int N =100010;

int e[N] , l[N] , r[N] , index;
void init()
{
    r[0] = 1;
    l[0] = -1;
    l[1] = 0;
    r[1] = -1;
    index = 2;
}
void add_l(int x)
{
    e[index] = x;
    l[index] = 0;
    r[index] = r[0];
    
    l[r[index]] = index;
    r[0] = index;
    index++;
}
void add_r(int x)
{
    e[index] = x;
    r[index] = 1;
    l[index] = l[1];
    l[1] = index;
    r[l[index]] = index;
    index++;
}
void erase(int k)
{
    /*if(k == 0)
    {
        l[r[k-1]] = -1;
        return ;
    }
    if(k == 1)
    {
        r[l[k-1]] = -1;
        return ;
    }*/
    k = k+2;
    l[r[k-1]] = l[k-1];
    r[l[k-1]] = r[k-1];
}
void addk_l(int k , int x)
{
    k += 2;
    e[index] = x;
    l[index] = l[k-1];
    r[index] = k-1;
    l[k-1] = index;
    r[l[index]] = index;
    index++;
}
void addk_r(int k , int x)
{
    k += 2;
    e[index] = x;
    r[index] = r[k-1];
    l[index] = k-1;
    r[k-1] = index;
    l[r[index]] = index;
    index++;
}
int main()
{
    init();
    int m;
    cin >> m;
    string op;
    int k,x;
    while(m--)
    {
        cin>>op;
        if(op == "L") cin>>x , add_l(x);
        if(op == "R") cin>>x , add_r(x);
        if(op == "D") cin>>x , erase(x);
        if(op == "IL") cin>>k>>x , addk_l(k,x);
        if(op == "IR") cin>>k>>x , addk_r(k,x);
    }
    for(int i = r[0]; i!= 1 ; i = r[i]) cout<< e[i] <<" "; 
}
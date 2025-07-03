#include <iostream>


using namespace std;

const int N = 100010;
int head_next = -1;
int e[N],ne[N];
int index = 0;

void add(int x)    //在头部插入
{
    ne[index] = head_next;
    e[index] = x;
    head_next = index;
    index ++;
}

void erase(int k)
{
    if(!k) head_next = ne[head_next] ;
    ne[k-1] = ne[ne[k-1]];
}

void remove(int x , int k)
{
    e[index] = x;
    ne[index] = ne[k-1];
    ne[k-1] = index;
    index ++;
}
int main()
{
    int m;
    cin >> m;
    char op;
    int x , k;
    while(m--)
    {
        cin >> op;
        switch(op)
        {
            case 'H' : 
                cin >> x;
                add(x);
                break;
            case 'D' :
                cin >> k;
                erase(k);
                break;
            case 'I' :
                cin >> k >> x;
                remove(x , k);
                break;
        }
    }
    int i = head_next;
    while(i != -1)
    {
        cout<<e[i]<<" ";
        i = ne[i];
    }
}
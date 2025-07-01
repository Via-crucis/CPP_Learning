#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 300010;

int a[N] , s[N];

vector <int> alls;
vector <pair<int,int>> add;	//x和c
vector <pair<int,int>> query;	//选择区间

int query_find(int x)	//二分查找
{
    int l = 0;
    int r = alls.size()-1;
    while(l < r)
    {
        int mid = (l+r)/2;
        if(alls[mid] >= x) r = mid;
        //if(a[mid] == x) return mid;
        if(alls[mid] < x) l = mid + 1;
    }
    return r + 1;	//这里返回r+1是为了后续前缀和的使用。
}



int main()
{
    int n , m;
    cin >> n >> m;
    int x , c , l , r;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> x >> c;
        add.push_back({x,c});
        alls.push_back(x);
    }
    for(int i = 0 ; i < m ; i++)
    {
        cin >> l >> r;
        query.push_back({l , r});
        alls.push_back(l);
        alls.push_back(r);
    }
        sort(alls.begin() , alls.end());
        alls.erase(unique(alls.begin() , alls.end()) , alls.end());
    for(auto item : add)
    {
        int x = query_find(item.first);
        a[x] += item.second;
    }
    for(int i = 1 ; i <= alls.size() ; i++)s[i] = s[i-1] + a[i];	//前缀和
    for(auto item :query)
    {           
        cout<<s[query_find(item.second)] - s[query_find(item.first)-1]<<endl;
    }
    
}

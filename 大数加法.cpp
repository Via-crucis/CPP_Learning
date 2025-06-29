#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector <int> sal1 (vector <int> &a , int b)
{
    vector <int> c;
    int t = 0;
    int carry = 0;
    int a_size = a.size();
    for(int i = 0 ; i < a_size ; i++)
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    if (t) c.push_back(t); 
    while(c.size() > 1 && c.back() == 0) c.pop_back();  //去除先导0
    for(int i = c.size() - 1 ; i >= 0 ; i--) cout << c [i];
    return c;

}

vector <int> sal2 (vector <int> &a , int b)
{
    vector <int> c;
    int t = 0;
    int carry = 0;
    int a_size = a.size();
    for(int i = 0 ; i < a_size || t; i++)
    {
        if (i < a_size) t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    if (t) c.push_back(t);
    while(c.size() > 1 && c.back() == 0) c.pop_back();  //去除先导0
    for(int i = c.size() - 1 ; i >= 0 ; i--) cout << c [i];
    return c;

}
bool cmp (vector <int> &a , vector <int> &b)
{
    if (a.size() != b.size()) return a.size() > b.size();
    for (int i = a.size() - 1 ; i >= 0 ; i--)
    {
        if (a[i] == b[i]) continue;
        return a[i] > b[i];
    }
    return 1;
}
vector <int> sub(vector <int> &a , vector <int> &b)
{
    if (!cmp(a , b)) 
    {
        cout << "-";
        return sub (b , a);
    }
    vector <int> c;
    int t = 0;
    for(int i = 0 ;i < a.size() ;i++)
    {
        t = a[i] - t;
        if(i < b.size()) t -= b[i];
        c.push_back((t + 10) % 10);
        t < 0 ? t = 1 : t = 0;
    }
    while(c.size() > 1 && c.back() == 0) c.pop_back();  //去除先导0
    for(int i = c.size() - 1 ; i >= 0 ; i--) cout << c [i];
    return c;
}


vector <int> add(vector <int> &a , vector <int> &b)
{
    vector<int> c;
    int t = 0;
    int a_size = a.size();
    int b_size = b.size();
    for(int i = 0;i < a_size || i < b_size ; i++)
        {
            if (i < a_size) t += a[i];
            if (i < b_size) t += b[i];
            c.push_back(t % 10);
            t /= 10;
        }
        if (t) c.push_back(t);


    
    while(c.size() > 1 && c.back() == 0) c.pop_back();  //去除先导0
    for(int i = c.size() - 1 ; i >= 0 ; i--) cout << c [i];
    return c;
}

int main()
{
    vector<int>a,b;
    string num1,num2;
    int num3;
    cin >> num1 >> num3;
    for(int i = num1.size()-1 ; i >= 0 ;i--) a.push_back(num1[i] - '0');
    for(int i = num2.size()-1 ; i >= 0 ;i--) b.push_back(num2[i] - '0');
    sal2 (a , num3);
    cout<<endl;
}
/*
高精度运算实现笔记

核心思路：
1. 用vector存储大整数，每个元素存一位数字
2. 数字倒序存储（个位在前，便于进位处理）
3. 字符串输入转数字：减去'0'的ASCII码值
4. 所有运算都模拟人工竖式计算过程

关键技巧：
1. 处理进位：用t记录进位值
2. 去除前导零：while循环配合pop_back
3. 比较大小：先比较位数，再逐位比较
4. 输出处理：逆序遍历vector
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// 高精度除法：大整数除以单精度整数
// 参数说明：a-被除数, b-除数, r-最终余数
// 返回值：商的每一位数字构成的vector
// 算法：模拟竖式除法，从高位到低位逐位处理
vector <int > div (vector <int> &a , int b , int &r)
{
    vector <int> c;
    r = 0;
    for(int i = a.size() - 1 ; i >= 0 ; i--)
    {
        r = r * 10 + a[i];
        c.push_back(r / b);
        r %= b;
    }
    reverse(c.begin() , c.end());
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    for(int i = c.size() - 1 ; i >= 0 ; i--) cout << c [i];
    cout<<endl<<r;
    return c;
}

// 高精度乘法：大整数乘以单精度整数
// 参数说明：a-大整数, b-单精度整数
// 算法：模拟竖式乘法，处理好进位
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
// 比较两个大整数的大小
// 返回值：true表示a>b，false表示a<=b
// 算法：1.先比较位数 2.位数相同时从高位到低位比较
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
// 高精度减法：大整数减法
// 特殊处理：如果a<b，输出负号并交换顺序计算
// 算法：模拟竖式减法，注意借位处理
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


// 高精度加法：两个大整数相加
// 算法：模拟竖式加法，处理进位
// 技巧：统一处理a、b不等长的情况
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

// 主函数：演示高精度运算
// 输入格式：两个大整数字符串
// 数据预处理：字符串转为倒序存储的vector
int main()
{
    vector<int>a,b;
    string num1,num2;
    int num3;
    cin >> num1 >> num3;
    for(int i = num1.size()-1 ; i >= 0 ;i--) a.push_back(num1[i] - '0');
    for(int i = num2.size()-1 ; i >= 0 ;i--) b.push_back(num2[i] - '0');
    int r;
    div(a , num3 , r);
    cout<<endl;
}
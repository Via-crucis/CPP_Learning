#include <iostream>
using namespace std;


//类模板应用
template <typename T>
class Stu{
    public:
        T a;        //定义模板类型变量
        T b;
};
int main()
{
    Stu<int> a;     //将T指定为模板类型
    a.a = 1;
    a.b = 2;
    Stu<double> b;
    b.a = 114.1;
    b.b = 114.2;
}
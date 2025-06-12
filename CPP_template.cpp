#include <iostream>
using namespace std;


//类模板应用
template <typename T>
class Stu{
    public:
        T a;        //定义模板类型变量
        T b;
        friend bool operator>(Stu a,Stu b)  //重载运算符
        {
            return a.a>b.a;
        }
};

template <typename T>
class human{
    public:
        T a;
        T b;
        bool main()
        {
            cout<< "a大于b";
            return a>b; //如果a的类型和b的类型支持大于运算，则编译器不会报错
        }
};

template <typename T1,typename T2>         //类模板继承类模板
class human1:public human<T1>
{
    public:
    T2 aa;
    T2 bb;
};



int main()
{
    Stu<int> a;     //将T指定为模板类型
    a.a = 1;
    a.b = 2;
    Stu<double> b;
    b.a = 114.1;
    b.b = 114.2;
    human<Stu<int>> aa;
    aa.main();
    human1<Stu<int>,int> aaa;   //在类型赋值中添加多个模板类型变量，同时使用类模板继承类模板。
    aaa.aa = 1;
    aaa.bb = 2;
    cout<<aaa.aa<<endl<<aaa.bb<<endl<<aaa.main();   
}


/*总结:
    1.类型模板是用于替换类中未定义的类型的变量，而每一个类模板在创建时都需要对类型变量（typename）赋值
    2.类模板在继承类模板时，类似构造函数一样，需要为父类模板的类型变量赋值。模板声明是专为类型变量赋值的构造函数
    3.编译器在识别重载运算符时，会将原来的双目运算符以及其两侧的变量替换为函数调用。*/
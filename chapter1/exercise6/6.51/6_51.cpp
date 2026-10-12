#include <iostream>

using std::cout;
using std::endl;


void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);
void f(double a, int b);


int main() 
{
    f(2.56, 42); 
    /* 有多个 重载函数 "f" 实例与参数列表匹配:
    6_51.cpp(16, 5): 函数 "f(int a, int b)" (已声明 所在行数:28)
    6_51.cpp(16, 5): 函数 "f(double a, double b = (3.14))" (已声明 所在行数:32)
    6_51.cpp(16, 5): 参数类型为:  (double, int)*/
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}


void f()
{
    cout << "Null" << endl;
}
void f(int a)
{
    cout << a << endl;
}
void f(int a, int b)
{
    cout << a << " " << b << endl;
}
void f(double a, double b)
{
    cout << a << " " << b << endl;
}
void f(double a, int b)
{
    cout << a << " " << b << endl;
}
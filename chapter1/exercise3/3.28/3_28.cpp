#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

string sa[10];
int ia[10];

int main()
{
    string sa2[10];
    int ia2[10];
    for (auto i : ia)
        cout << i << " ";
    cout << endl;
    for (auto i : ia2)
        cout << i << " ";
    cout << endl;
    for (auto i : sa)
        cout << i;
    cout << endl;
    for (auto i : sa2)
        cout << i;
    cout << endl;

    return 0;
}

/*
1.全局变量（在函数外部定义）
无论是在 C++98、C++11 还是 C++20，全局变量都会被零初始化（Zero-initialized）。
int ia[10]：所有元素自动变为 0。
string sa[10]：所有元素自动调用默认构造函数，变成空字符串 ""。
结论：输出全是 0 或空，是符合所有 C++ 标准预期的。
2. 局部变量（在函数内部定义）
局部变量的默认初始化规则也保持不变：不做任何初始化，它们的值是未定义的（也就是内存中残留的随机垃圾值）。
int ia2[10]：里面的值是随机的。
string sa2[10]：在 C++11 中，std::string 的默认构造函数依然会将其初始化为空字符串 ""。
*/
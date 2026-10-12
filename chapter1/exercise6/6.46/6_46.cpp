#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

// 比较两个string对象的长度, 应放在头文件中
constexpr bool isShorter (const string &s1, const string &s2)
{
    return s1.size() < s2.size(); //《C++ Primer》第5版是基于 C++11 的。在 C++11 中，constexpr 函数只能包含一条 return 语句，且参数和返回类型必须是字面值类型。std::string 不符合要求。
}


int main()
{
    const string str1("hello");
    const string str2("hi");
    cout << (isShorter(str1, str2) ? str1 : str2) << endl;
    return 0;
}
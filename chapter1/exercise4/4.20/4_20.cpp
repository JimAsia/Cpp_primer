#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

int main()
{
   
    vector<string> v = {"Hello, World", "Good", "No"};
    auto iter = v.begin();
    cout << *iter++ << endl;
    // cout << (*iter)++ << endl; *iter 是 std::string 对象（如 "Hello, World"），++ 运算符不能直接用于 std::string 对象（std::string 没有定义后缀 ++ 运算符）。
    cout << (*iter).empty() << endl;    // error: *iter.empty()
    cout << iter->empty() << endl;
    // cout << ++*iter << endl;
    cout << iter++->empty() << endl;

    return 0;
}
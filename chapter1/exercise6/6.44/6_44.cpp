#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

// 比较两个string对象的长度, 应放在头文件中
inline bool isShorter (const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}


int main()
{
    string str1("hello");
    string str2("hi");
    cout << (isShorter(str1, str2) ? str1 : str2) << endl;
    return 0;
}
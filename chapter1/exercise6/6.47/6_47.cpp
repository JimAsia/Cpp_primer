#include <iostream>
#include <vector>
#define NDEBUG  // 关闭调试器

using std::vector;
using std::cout;
using std::endl;

void myVect(const vector<int> &a, vector<int>::const_iterator it);

int main()
{
    vector<int> ai = {10, 20, 30, 40};
    myVect(ai, ai.begin());
    return 0;
}

void myVect(const vector<int> &a, vector<int>::const_iterator it)
{
    #ifndef NDEBUG
    cout << "vector size: " << a.size() << endl;
    #endif
    if (it == a.end())
        return ;
    cout << *it << endl;
    ++it;
    // 检查变量 word 的长度是否小于阈值
    cout << "Error: " << __FILE__  // 输出当前源文件名
         << " : in function " << __func__  // 输出当前函数名
         << " at line " << __LINE__ << endl // 输出当前行号
         << "       Compiled on " << __DATE__  // 输出编译日期
         << " at " << __TIME__ << endl  // 输出编译时间
         << "       Word read was \"" << *it  // 输出读取到的 word 变量的值
         << "\": Length too short" << endl; // 输出具体的错误原因
    return myVect(a, it);
}
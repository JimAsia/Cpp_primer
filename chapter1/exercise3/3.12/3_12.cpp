#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
    vector<vector<int>> ivec;
    // vector<string> svec = ivec;  vector<int>和string是完全不同的类型，无法隐式转换（例如，无法将一个vector<int>对象当作string来初始化）。因此，该语句会触发编译错误（类型不匹配）。
    vector<string> svec(10, "null");
    for  (auto &j : ivec)
        for (auto i : j)
            cout << i << endl;
    for (auto &s : svec)
        cout << s << endl;
    return 0;
}
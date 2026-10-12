#include<iostream>
int main()
{
    int v1 = 0, v2 = 1;
    std::cout << "The sum of" << v1
     << " and " << v2 
     << " is " << v1 + v2 << std::endl;
    return 0;
}

/*错误信息：unterminated comment gcc c++[11, 1] 文件结尾的注释未闭合 C/C++[6, 1]*/

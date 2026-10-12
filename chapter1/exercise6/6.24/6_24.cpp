#include <iostream>

using namespace std;

void print(const int ia[10]); // 编译器会完全忽略 [10] 这个长度

int main()
{
    int j[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(j);
    return 0;
}

void print(const int ia[10]) 
{
    for (int i = 0; i != 12; ++i) // 当i！=12后，除了j的10位数，后面还会输出垃圾值
        cout << ia[i] << " ";
}
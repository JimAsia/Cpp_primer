#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int &ref = a;
    const int &ref2 = a;
    // 1. 定义一个指向引用的指针 p_ref
    // 这里的 &ref 依然会被解释为取 a 的地址，所以 p_ref 指向了 a
    int* p_ref = &ref; 

    // 2. 打印 a 的地址（这是 ref “逻辑上”的地址）
    cout << "a 的地址 (逻辑地址): " << &a << endl;

    // 3. 打印 p_ref 自己的地址
    // 这是存放“引用/指针”这个变量的物理内存地址
    cout << "p_ref 的物理地址: " << &p_ref << endl; 

    // 4. 打印 p_ref 里存的值
    // 你会发现它存的正是 a 的地址！这就证明了底层存的是地址。
    cout << "p_ref 里存的值: " << p_ref << endl; 

    a = 5;

    cout << ref2 << endl;
    ref = 8;
    cout << ref2 << endl;

    
    int *const curErr = &a;
    *curErr = 18;
    cout << a << endl << *curErr << endl;
    const double pi = 3.14;
    const double *const pip = &pi;
    const int &s = 0;
    int *const p = nullptr;
    return 0;
}
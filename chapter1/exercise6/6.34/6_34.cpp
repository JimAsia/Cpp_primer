#include <iostream>

using std::cout;
using std::endl;

/*
当 val 为负数时（致命缺陷）：
假设传入 -1。-1 != 0 为 true，执行 return factorial(-2) * -1;
接着 factorial(-2) 调用 factorial(-3) * -2...
因为负数永远不会等于 0，val 会一直递减（-1, -2, -3, -4...），永远无法触发停止条件。
每次函数调用都会在栈上压入一个新的栈帧，最终耗尽栈空间，引发段错误（Segmentation Fault）或抛出 std::overflow_error 异常（具体取决于编译器/系统，通常是直接崩溃）。
*/
int factorial(int val)
{
    if (val > 1)
        return factorial(val--) * val;  
    return 1;
}

int main()
{
    int val = 10;
    cout << factorial(val);
    return 0;
}

// 6.35
/*
会导致无限递归（最致命的错误）
val-- 是后缀递减运算符。它的规则是：先返回 val 当前的值，然后再将 val 减 1。

假设当前 val = 10。

执行 factorial(val--) 时，表达式返回的是 10，把这个 10 传给了下一层函数。

下一层函数收到 10，再次执行 val--，还是返回 10，继续传给下一层……

结果：val 永远以 10 的值被传递下去，永远无法到达 0（或 1）的终止条件。程序会不断压栈，最终导致栈溢出（Stack Overflow）崩溃。
*/
#include <iostream>

using namespace std;

int main()
{
    /*
    正常执行：程序从 try 代码块的顶部开始，像往常一样一行行往下执行。
    遇到问题抛出异常：如果在执行过程中遇到了 throw runtime_error(...) 这一行，程序会立刻停止当前 try 块里剩余的所有代码（比如下面的除法运算和输出）。
    跳转处理：程序会直接“跳转”到与之匹配的 catch 代码块中，开始执行里面的“补救”或“报错”逻辑。
    try-catch 本质上就是给程序写了一段“如果这里出问题，请跳到那里去处理”的预设方案。
    */
    double x, y;
    cout << "Enter x and y:" << endl;
    while(cin >> x >> y) {
        try {
            if (y == 0) {
                throw runtime_error("Divisor must not be zero.");
            }
            cout << x / y << endl;
        }
        catch (runtime_error err) {
            cout << err.what() << endl;
            cout << "Try Again? Enter y(Y) or n(N)" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n' || c == 'N')
                break;
        }  
    }
    return 0;

}
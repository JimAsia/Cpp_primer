#include <iostream>
#include <string>
#include <vector>

#include "greeter.h"
#include "math_utils.h"

// 这是整个工程唯一的 main()。
// 多文件工程里，只能有一个文件定义 main，其余文件只提供函数/类。
int main(int argc, char* argv[]) {
    const std::string name = (argc > 1) ? argv[1] : "world";
    std::cout << demo::greeting(name) << '\n';

    const std::vector<int> values{1, 2, 3, 4, 5};

    std::cout << "add(2, 3)     = " << demo::add(2, 3) << '\n';
    std::cout << "factorial(6)  = " << demo::factorial(6) << '\n';
    std::cout << "average(1..5) = " << demo::average(values) << '\n';

    return 0;
}

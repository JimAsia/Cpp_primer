#include <iostream>
#include <limits>

int main() {
    int num;

    std::cout << "请输入一个整数: ";
    std::cin >> num;

    if (std::cin.fail()) {
        std::cout << "输入错误！触发了 failbit。\n";
        
        // --- 核心操作：使用图片中的代码复位 failbit 和 badbit ---
        std::cin.clear(std::cin.rdstate() & ~std::cin.failbit & ~std::cin.badbit);
        
        // 注意：清除错误状态后，错误输入（比如字母'a'）还在缓冲区里
        // 必须清理缓冲区，否则下一次读取依然会读到这个'a'
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::cout << "错误状态已修复。\n";
        std::cout << "请重新输入一个整数: ";
        std::cin >> num;
    }

    if (!std::cin.fail()) {
        std::cout << "你输入的数字是: " << num << std::endl;
    }

    return 0;
}
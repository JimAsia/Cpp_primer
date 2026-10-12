#include <iostream>
#include <string>

using str = std::string[10];
str &my_str();


std::string (&myStr())[10];

auto mystr() -> std::string(&)[10]; // 尾置声明 auto 函数名(参数) -> 返回类型

/*
原版声明 std::string (&myFunc())[10]; 非常反人类，需要从内向外阅读（先看 myFunc()，再看 &，再看 [10]，最后看 std::string）。
而尾置返回类型完美符合人类从左到右的阅读习惯，一眼就能看出“返回的是一个包含10个string的数组的引用”。

*/


std::string arr[10];
decltype(arr) &a();

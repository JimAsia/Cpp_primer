// 第二套多文件练习的测试驱动
//
// 测试方法: 打开本文件, Ctrl+Shift+B 编译, 再跑 "C++: 编译并运行当前文件"。
// 预期产物: <工作区>\.build\main.exe
//
// 提示: 本目录和 sales_data 目录里都有 main.cpp, 但它们是两个独立目录。
// build.ps1 只编译"当前文件所在目录"的 .cpp, 所以两者互不干扰 ——
// 这正是每个练习单独放一个目录的原因。

#include <iostream>
#include <vector>
#include "Complex.h"

int main()
{
	Complex a(3.0, 4.0);
	Complex b(1.0, -2.0);

	std::cout << "a        = " << a << std::endl;
	std::cout << "b        = " << b << std::endl;
	std::cout << "a + b    = " << (a + b) << std::endl;
	std::cout << "a - b    = " << (a - b) << std::endl;
	std::cout << "-a       = " << (-a) << std::endl;

	std::cout << "\n==== 复合赋值会真的改掉 a ====" << std::endl;
	Complex c = a;
	c += b;
	std::cout << "c = a; c += b  ->  c = " << c << std::endl;
	std::cout << "a 未被改动     ->  a = " << a << std::endl;

	std::cout << "\n==== 比较运算 ====" << std::endl;
	std::cout << "a == a   : " << (a == a) << std::endl;
	std::cout << "a != b   : " << (a != b) << std::endl;
	std::cout << "a == (b + (a - b)) : " << (a == (b + (a - b))) << std::endl;

	std::cout << "\n==== 链式调用 ====" << std::endl;
	std::vector<Complex> values = { a, b, Complex(0.5, 0.5) };
	Complex sum;
	for (const auto& v : values) {
		sum += v;
		std::cout << "累加 " << v << "  ->  " << sum << std::endl;
	}
	return 0;
}

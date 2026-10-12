// 《C++ Primer》练习 7.6/7.7/7.11 的测试驱动
// 数据写死在代码里, 这样按 Ctrl+Shift+B 或用"编译并运行"任务都能直接出结果,
// 不需要在终端里手敲输入。
//
// 测试方法: 打开本文件, 按 Ctrl+Shift+B 编译, 或运行任务 "C++: 编译并运行当前文件"。
// 预期产物: <工作区>\.build\main.exe
//
// 注意: 本目录下有 2 个 .cpp (main.cpp / Sales_data.cpp),
// build.ps1 会自动发现并一起编译 —— 少编译任何一个都会报
// undefined reference, 这就是分离式编译最直观的验证。

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Sales_data.h"

int main()
{
	std::cout << "==== 1) 用 add / print 直接算 ====" << std::endl;
	Sales_data a{"978-7-121-15535-2", 3, 3 * 45.0};
	Sales_data b{"978-7-121-15535-2", 2, 2 * 45.0};
	Sales_data total = add(a, b);
	print(std::cout, total) << std::endl;

	std::cout << "\n==== 2) 模拟输入流, 按 ISBN 分组统计 (7.1.4 主程序) ====" << std::endl;
	const std::vector<std::string> lines = {
		"0-201-70353-X 4 24.99",
		"0-201-70353-X 2 24.99",
		"0-201-88954-4 5 12.00",
		"0-201-88954-4 3 12.00",
		"0-201-88954-4 2 12.00",
	};

	// 拼成一段文本喂给 istringstream, 行为与你手动敲 5 行输入完全一致
	std::string text;
	for (const auto& line : lines)
		text += line + "\n";
	std::istringstream input(text);

	Sales_data sum;
	if (read(input, sum)) {
		Sales_data trans;
		while (read(input, trans)) {
			if (sum.isbn() == trans.isbn()) {
				sum.combine(trans);
			} else {
				print(std::cout, sum) << std::endl;
				sum = trans;
			}
		}
		print(std::cout, sum) << std::endl;
	} else {
		std::cerr << "没有读到任何数据!" << std::endl;
		return -1;
	}

	std::cout << "\n==== 3) 拷贝 / 赋值 / avg_price ====" << std::endl;
	Sales_data copy = total;
	std::cout << "copy.isbn()      = " << copy.isbn() << std::endl;
	std::cout << "copy.avg_price() = " << copy.avg_price() << std::endl;
	copy = Sales_data{};
	std::cout << "默认构造后 units_sold = " << copy.units_sold
	          << ", avg_price() = " << copy.avg_price()
	          << "  (0 本时不会除以 0)" << std::endl;
	return 0;
}

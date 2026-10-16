// 《C++ Primer》练习 7.6/7.7/7.11 的测试驱动
// 测试方法: 打开本文件, 按 Ctrl+Shift+B 编译, 或运行任务 "C++: 编译并运行当前文件"。
// 预期产物: <工作区>\.build\main.exe
//
// 第 2) 段的数据从同目录的 saleData.md 读取 (每行: ISBN 数量 单价)。
//   * saleData.md 必须是【纯数据】, 不要写成 C++ 数组字面量那样带引号和逗号:
//     operator>> 会把开头的引号一起读进 ISBN; 而读完 24.99 后残留的 ",
//     会让下一次 >> 解析失败并置 failbit, 后面的记录就被静默丢掉了。
//   * 运行任务的工作目录 = 源文件所在目录 (tasks.json 里 cwd=${fileDirname}),
//     所以相对路径 "saleData.md" 能直接找到文件; 万一打不开, 代码会明确报错
//     而不是算出一份看着正常、其实是错的结果。
//
// 注意: 本目录下有 2 个 .cpp (main.cpp / Sales_data.cpp),
// build.ps1 会自动发现并一起编译 —— 少编译任何一个都会报
// undefined reference, 这就是分离式编译最直观的验证。

#include <iostream>
#include <string>
#include <fstream>      // ifstream / ofstream
#include <sstream>      // 只有"备选方案"(istringstream) 用得到
#include <vector>       // 同上
#include "Sales_data.h"

int main()
{
	std::cout << "==== 1) 用 add / print 直接算 ====" << std::endl;
	Sales_data a{"978-7-121-15535-2", 3, 3 * 45.0};
	Sales_data b{"978-7-121-15535-2", 2, 2 * 45.0};
	Sales_data total = add(a, b);
	print(std::cout, total) << std::endl;

	std::cout << "\n==== 2) 读 saleData.md, 按 ISBN 分组统计 (7.1.4 主程序) ====" << std::endl;

	// 【备选方案】不想读文件时, 把这 5 行数据直接喂给 istringstream,
	// 行为与手动在终端敲 5 行输入完全一致。用不到就保持注释。
	/*
	const std::vector<std::string> lines = {
		"0-201-70353-X 4 24.99",
		"0-201-70353-X 2 24.99",
		"0-201-88954-4 5 12.00",
		"0-201-88954-4 3 12.00",
		"0-201-88954-4 2 12.00",
	};
	std::string text;
	for (const auto& line : lines)
		text += line + "\n";
	std::istringstream input(text);
	*/

	std::ifstream input("saleData.md");
	if (!input) {
		std::cerr << "打不开 saleData.md: 请确认运行任务的工作目录 = 本文件所在目录" << std::endl;
		return -1;
	}
	std::ofstream output;   // 分组结果同时写一份到文件
	// exercise 8.8
	output.open("Data.md", std::ofstream::app);  // 模式更改为输出和追加

	Sales_data sum;
	if (!read(input, sum)) {           // 一条都没读进来: 空文件或格式不对
		std::cerr << "saleData.md 里没有可用记录 (每行应为: ISBN 数量 单价)" << std::endl;
		return -1;
	}

	Sales_data trans;
	while (read(input, trans)) {
		if (sum.isbn() == trans.isbn()) {
			sum.combine(trans);                   // 同一个 ISBN: 累加
		} else {
			print(std::cout, sum) << std::endl;   // 上一组: 输出到屏幕
			print(output, sum) << std::endl;      //         同时也写进 Data.md
			sum = trans;                          // 开启新的一组
		}
	}
	print(std::cout, sum) << std::endl;           // 循环结束后, 最后一组别漏掉
	print(output, sum) << std::endl;

	std::cout << "\n==== 3) 拷贝 / 赋值 / avg_price ====" << std::endl;
	Sales_data copy = total;
	std::cout << "copy.isbn()      = " << copy.isbn() << std::endl;
	std::cout << "copy.avg_price() = " << copy.avg_price() << std::endl;
	copy = Sales_data{};
	std::cout << "默认构造后 units_sold = " << copy.units_sold
	          << ", avg_price() = " << copy.avg_price()
	          << "  (0 本时不会除以 0)" << std::endl;
	output.clear();
	input.clear();
	return 0;
}

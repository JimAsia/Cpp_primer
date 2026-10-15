#ifndef SALES_DATA_H
#define SALES_DATA_H

// 《C++ Primer》第 7.1.4 节: 使用 Sales_data 类
// 这个头文件【只放声明】。函数体全部放在 Sales_data.cpp。
// 如果把函数体写在这里, 它会被 main.cpp 和 Sales_data.cpp 各包含一次,
// 链接时就会报 multiple definition —— 分离式编译的经典坑。

#include <string>
#include <iostream>

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	// 类内定义的成员函数是隐式 inline, 所以写在头文件里也是安全的
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);   // 声明在头, 定义在 .cpp
	double avg_price() const;                 // 声明在头, 定义在 .cpp
};

// 三个非成员函数接口 (第 7.1.3 节)
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);

#endif

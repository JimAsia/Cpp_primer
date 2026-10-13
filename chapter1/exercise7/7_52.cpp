#include "sales_data/Sales_data.h"


int main()
{
	Sales_data item = {"978-0590353403", 25, 15.99};  // 有类内初始值，不是聚合类
	return 0;
}

/*
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0; // 类内初始值
    double revenue = 0.0;    // 类内初始值
};


在 C++11 中，聚合类必须满足以下条件：

没有用户定义的构造函数。
没有私有或受保护的非静态数据成员
没有基类。
没有虚函数。
没有类内初始值（C++14 才允许聚合类有类内初始值）。

*/


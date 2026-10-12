#include <iostream>



class Date
{
public:
	Date() : Date(7, 7, 7) {std::cout << "default" << std::endl;}
	// 7_42
	Date(int y) : Date(y, 1, 1) {std::cout << "Use Date(int y)" << std::endl;}
	Date(int y, int m) : Date(y, m, 1) {std::cout << "Use Date(int y, int m)" << std::endl;}
	Date(int y, int m, int d) : year(y), month(m), day(d) {std::cout << "Use Date(int y, int m, int d)" << std::endl;}
	Date(std::istream &is);
	// Date(std::ostream &out); 如果确实需要输出，不是构造函数
private:
	int year = 2001;
	int month = 2;
	int day = 21;

	friend std::ostream &operator<<(std::ostream &out, const Date &d);
};

Date::Date(std::istream &is)
{
	is >> year >> month >> day;
}

std::ostream &operator<<(std::ostream &out, const Date &d)
{
	out << "year: " << d.year << std::endl;
	out << "month: " << d.month << std::endl;
	out << "day: " << d.day << std::endl;
	return out;
}

int main()
{
	Date d1;
	std::cout << d1;
	Date d2(std::cin);
	std::cout << d2;
	// 7_42
	Date d3(6);
	Date d4(6, 4);
	return 0;
}

/*
Date d1(std::cin);

这行代码是一个变量声明并初始化（直接初始化）。编译器会去 Date 类中寻找一个接受 std::istream& 的构造函数，并在为 d1 分配内存后，立刻调用该构造函数完成初始化。这是合法的。

Date d1; d1(std::cin);

Date d1; 会调用默认构造函数（假设存在），此时对象已经构造完毕。

d1(std::cin); 这行代码在编译器看来，是一个函数调用表达式。它会被解析为 d1.operator()(std::cin);，即试图调用 d1 对象的函数调用运算符 operator()。

由于 Date 类并没有重载 operator()，编译器会直接报错（例如：error: no match for call to '(Date) (std::istream&)'）。
*/
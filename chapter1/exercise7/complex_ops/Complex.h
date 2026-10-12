#ifndef COMPLEX_H
#define COMPLEX_H

// 第二套多文件练习: 运算符重载 + 分离式编译
// 结构: Complex.h (声明) / Complex.cpp (定义) / main.cpp (测试)
//
// 这里刻意演示两种写法并存:
//   - 成员函数 operator+= 的定义放在 .cpp 里
//   - 非成员函数声明在头里、定义在 .cpp 里

#include <iostream>

class Complex {
public:
	Complex() = default;
	Complex(double r, double i) : re_(r), im_(i) {}

	double real() const { return re_; }
	double imag() const { return im_; }

	Complex& operator+=(const Complex& rhs);
	Complex& operator-=(const Complex& rhs);

private:
	double re_ = 0.0;
	double im_ = 0.0;
};

// 非成员运算符: 声明在头文件, 定义在 Complex.cpp
Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& rhs);              // 一元负号
bool operator==(const Complex& lhs, const Complex& rhs);
bool operator!=(const Complex& lhs, const Complex& rhs);

std::ostream& operator<<(std::ostream& os, const Complex& value);

#endif

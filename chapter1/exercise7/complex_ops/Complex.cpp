#include "Complex.h"

Complex& Complex::operator+=(const Complex& rhs)
{
	re_ += rhs.re_;
	im_ += rhs.im_;
	return *this;
}

Complex& Complex::operator-=(const Complex& rhs)
{
	re_ -= rhs.re_;
	im_ -= rhs.im_;
	return *this;
}

// 非成员运算符全部实现在这里。注意 operator+ 是拿 lhs 的副本做 +=,
// 所以它不需要是友元, 也不需要直接碰私有成员 —— 复用了 operator+=。
Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex result = lhs;
	result += rhs;
	return result;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
	Complex result = lhs;
	result -= rhs;
	return result;
}

Complex operator-(const Complex& rhs)
{
	return Complex(-rhs.real(), -rhs.imag());
}

bool operator==(const Complex& lhs, const Complex& rhs)
{
	return lhs.real() == rhs.real() && lhs.imag() == rhs.imag();
}

bool operator!=(const Complex& lhs, const Complex& rhs)
{
	return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const Complex& value)
{
	os << "(" << value.real();
	if (value.imag() >= 0)
		os << "+";
	os << value.imag() << "i)";
	return os;
}

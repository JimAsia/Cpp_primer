#include <iostream>
#include <string>
// 产生二义性（Ambiguity）
// 一个类只能有一个默认构造函数。所谓默认构造函数，就是可以不提供任何实参就能调用的构造函数。
class Constructor
{
	Constructor(std::istream &is = std::cin);
	Constructor(std::string s = "");
	// 只给其中一个构造函数提供默认实参（保留一个默认构造函数）
	// 让另一个构造函数不提供默认实参，必须显式传入参数才能调用

};


int main()
{
	// Constructor C; // 类 "Constructor" 包含多个默认构造函数
}

#include <vector>

/*
class Exp
{
public:
	// 错误一：非 const 静态成员不能在类内直接初始化
	static double rate = 6.5;   // 带有类内初始值设定项的成员必须为常量
	static const int vecSize = 20;
	// 错误二：静态成员不能在类内使用圆括号 () 初始化
	static std::vector<double> vec(vecSize);  // 成员 "Exp::vecSize" 不是类型名
};

double Exp::rate;
std::vector<double> Exp::vec;

*/

class Exp
{
public:
	// 错误一：非 const 静态成员不能在类内直接初始化
	static double rate;   // 带有类内初始值设定项的成员必须为常量
	static const int vecSize = 20;
	// 错误二：静态成员不能在类内使用圆括号 () 初始化
	static std::vector<double> vec;  // 成员 "Exp::vecSize" 不是类型名
};

double Exp::rate = 6.5;
std::vector<double> Exp::vec(Exp::vecSize);

/*
在刚才那段代码中，vecSize 是类的静态常量。

cpp
std::vector<double> Exp::vec(Exp::vecSize); // 推荐：明确、无歧义
std::vector<double> Exp::vec(vecSize);      // 在某些编译器下也能过，但不推荐
在类外，如果 vecSize 不是一个全局变量，
直接写 vecSize 有时也能编译通过（因为编译器在解析 Exp::vec 定义时会查找 Exp 的作用域）。
但强烈建议写成 Exp::vecSize，不仅代码意图更清晰，而且能避免未来引入全局同名变量时的名称冲突。
*/
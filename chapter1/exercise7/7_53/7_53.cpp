
class Debug
{
public:
	constexpr Debug(bool b = true) : hw(b), io(b), other(b) { }
	constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) { }
	constexpr bool any() { return hw || io || other; }
	void setIo(bool b) { io = b; }
	void setHw(bool b) { hw = b; }
	void setOther(bool b) { other = b; }
private: 
	bool hw;
	bool io;
	bool other;
};

// 7.54
/*
1. constexpr 成员函数隐式是 const 的（C++11 标准）
在《C++ Primer》第 5 版对应的 C++11 标准中，constexpr 成员函数会被隐式地视为 const 成员函数。
这就意味着，在 constexpr 函数内部，this 指针是一个指向常量的指针（const Debug*），你不能修改类的任何非静态数据成员。

2. set_ 函数的核心职责是“修改状态”
set_ 开头的成员函数属于修改器（mutator），它们的作用恰恰是改变 Debug 对象内部的数据成员（如 hw、io、other）。

cpp
void set_io(bool b) { io = b; } // 修改了成员变量 io
这与 constexpr 隐式 const 的约束完全背道而驰。如果强行声明为 constexpr，编译器会直接报错，提示你“无法在 const 成员函数中修改成员变量”。

3. constexpr 函数体的限制（C++11）
C++11 标准对 constexpr 函数的函数体有极严格的限制：有且只能有一条 return 语句（不能有 if、循环、局部变量等）。
而 set_ 函数通常包含赋值语句，不返回任何值（返回类型为 void），且核心逻辑是“修改”而非“计算并返回一个常量”，完全不符合 constexpr 对函数体的要求。

💡 补充对比：Debug 类中哪些成员应该/可以声明为 constexpr？
在书中的 Debug 类里，构造函数和观察者（observer）函数是可以声明为 constexpr 的，例如：

cpp
constexpr Debug(bool b = true) : hw(b), io(b), other(b) {} // 构造函数：初始化成员，可以 constexpr
constexpr bool any() const { return hw || io || other; }  // 观察者函数：不修改状态，可以 constexpr
总结：constexpr 的核心语义是“能在编译期求值的常量表达式”以及“不会产生副作用的纯函数”。set_ 函数天生具有副作用（修改对象），因此绝对不适合被声明为 constexpr。
*/
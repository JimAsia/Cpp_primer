#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class NoDefault // 没有默认构造函数
{
public:
	NoDefault(int i) : a(i) { cout << " Use NoDefault(int i) " << endl; }
	int getVaule() { return a; }
private:
	int a;
};



class C
{
public:
	// 默认构造函数
	C(NoDefault no = allN) : n(no) {cout << " C(NoDefault no = allN) " << endl; }

	NoDefault n;
private:
	static NoDefault allN;
};

NoDefault C::allN(1);

int main()
{
	NoDefault n1(2);
	C c1(n1);
	cout << c1.n.getVaule() << endl;
	// 7_44 
	// 为了创建这 10 个对象，vector 必须对这 10 个元素进行默认初始化
	// 也就是调用 NoDefault 的默认构造函数 (NoDefault())。
	// vector<NoDefault> vec(10, NoDefault(2)); 
	// 这会调用 NoDefault(int) 一次，然后调用拷贝构造函数 10 次
	// vector<NoDefault> vec(10); // 创建一个包含 10 个 NoDefault 对象的 vector。

	// 7_45
	// 可以，C类拥有默认构造函数
	vector<C> vec(10);

	return 0;
}
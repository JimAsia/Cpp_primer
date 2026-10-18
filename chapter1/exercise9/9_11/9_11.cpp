#include <vector>
#include <iostream>
#include <string>
#include <list>

using std::cin;
using std::cout;
using std::vector;
using std::string;

int main()
{
	// one 9.11
	vector<int> v1 = {1, 2, 3, 4, 5};
	vector<int> v2{1, 2, 3, 4, 5};
	// two
	vector<int> v3;
	// three
	vector<int> v9(v1);
	v3 = v1;
	// four
	vector<int> v4(v1.begin(), v1.end());
	// five
	vector<int> v5(5);
	// six
	vector<int> v6(5, 2);

	// 9.13
	std::list<int> list1{1, 2, 3};
	vector<double> v7(list1.begin(), list1.end());
	vector<double> v8(v1.begin(), v1.end());
	
	// 9.14
	std::list<const char *> list2{"hello", "world"};  // 双引号括起来的字符串字面量（例如 "hello"）的类型是 const char*（指向常量字符的指针）。它们被存储在程序内存的只读数据段中。
	vector<string> vstr1;
	vstr1.assign(list2.cbegin(), list2.cend());
	for (const auto &c : vstr1)
		cout << c << " ";
	
	// 9.15 
	if (v1 == v2)
		cout << "v1 == v2\n";
	else
		cout << "v1 != v2\n";
	
	// 9.16
	vector<int> list1_copy(list1.begin(), list1.end());
	if (list1_copy < v1)
		cout << " ist1_copy < v1\n ";
	else
		cout << " ist1_copy > v1\n ";

	return 0;

}
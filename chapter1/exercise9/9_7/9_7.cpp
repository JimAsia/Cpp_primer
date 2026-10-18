#include <vector>
#include<iostream>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::string;

int main()
{
	// 9.7 9.8
	vector<int> i = {1, 2, 3, 4, 5};
	vector<string> s = {"hello", "world"};
	// difference_type 表示两个迭代器之间的距离
	// difference_type 是容器（如 vector、list）和迭代器定义的一种有符号整数类型。
	vector<int>::difference_type count = i.end() - i.begin();
	vector<string>::iterator iter;
	/*
	9.7
	vector<int>::size_type
	索引（即下标操作 []）是无符号的，且最大不能超过容器的容量。size_type 就是专门用来表示容器大小和索引的无符号整数类型（通常是 size_t 的别名）。
	注意区分： size_type 是无符号的（用来索引），而 difference_type 是有符号的（用来表示迭代器的距离，因为迭代器相减可能为负）。
	*/
	/*
	9.8
	应该使用 list<string>::iterator 或 list<string>::const_iterator。
	
	读取：如果 list 是 const 的，或者你只想读取不想修改，可以使用 list<string>::const_iterator；如果只是普通读取，直接用 list<string>::iterator 也可以。
	写入：题目问“如果写入”，说明这个 list 对象不是 const 的，你需要使用普通的 list<string>::iterator。通过这个迭代器解引用（*iter），你可以修改里面的 string 元素。const_iterator 只能读不能写。
	*/
}
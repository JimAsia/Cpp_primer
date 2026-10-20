#include <vector>
#include <iostream>
#include <string>
#include <list>
#include <deque>

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::string;
using std::deque;
using std::list;

int main()
{
	// 9.23
	vector<int> c{1};
	// 在解引用一个迭代器或调用 front 或 back 之前检查是否有元素
	// front和back返回的都是元素值
	if (!c.empty()) {
		// val 和 val2 是 c 中第一个元素值的拷贝
		auto val = *c.begin(), val2 = c.front();
		// val3 和 val4 是 c 中最后一个元素值的拷贝
		auto last = c.end();
		auto val3 = *(--last); // 不能递减 forward_list 迭代器
		auto val4 = c.back();  // forward_list 不支持
		cout << val << " " << val2 << " " << val3 << " " << val4 << " ";
	}

	// 9.24
	vector<int> empty_v;
	vector<int>::iterator it = empty_v.begin();
	// cout << empty_v.at(0) << endl;   // 出现异常。Unknown signal
	// cout << empty_v[0] << endl; // 出现异常。Unknown signal
	// cout << empty_v.front() << endl;
	// cout << *(it) << endl; // 出现异常。Segmentation fault

	return 0;
}
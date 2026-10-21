#include <vector>
#include <iostream>
#include <string>
#include <list>
#include <deque>
#include <forward_list>

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::string;
using std::deque;
using std::list;
using std::forward_list;

int main()
{
	// 傻瓜循环，删除偶数元素，复制每个奇数元素
	list<int> vi = {0,1,2,3,4,5,6,7,8,9};
	auto iter = vi.begin(); // 调用 begin 而不是 cbegin，因为我们要改变 vi
	
	while (iter != vi.end()) {
		++iter;      // it->1  // 1->2
		vi.insert(iter, 42); // 复制当前元素  1->42   // 2 ->42
		++iter; // 向前移动迭代器，跳过当前元素以及插入到它之前的元素 42->1
		// 0 42 1 2 42 3 4 42 5 6 42 7 8 42 9 
		// iter = vi.insert(iter, 42);  // 0 42 1 42 2 42 3 42 4 42 5 42 6 42 7 42 8 42 9 42 
	
	}
	for (const auto &i : vi) {
		cout << i << " ";
	}
	return 0;
}
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

/*
// list 1 1 3 3 5 5 7 7 9 9 
int main()
{
	// 傻瓜循环，删除偶数元素，复制每个奇数元素
	list<int> vi = {0,1,2,3,4,5,6,7,8,9};
	auto iter = vi.begin(); // 调用 begin 而不是 cbegin，因为我们要改变 vi
	
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter); // 复制当前元素
			++iter; // 向前移动迭代器，跳过当前元素以及插入到它之前的元素
			++iter;
		} else
			iter = vi.erase(iter);          // 删除偶数元素
			// 不应向前移动迭代器，iter 指向我们删除的元素之后的元素
	}
	for (const auto &i : vi) {
		cout << i << " ";
	}
	return 0;
}
*/
int main()
{
	// 傻瓜循环，删除偶数元素，复制每个奇数元素
	forward_list<int> vi = {0,1,2,3,4,5,6,7,8,9};
	auto iter = vi.begin(); // 调用 begin 而不是 cbegin，因为我们要改变 vi
	auto prev = vi.before_begin();
	while (iter != vi.end()) {
		if (*iter % 2 != 0) {
			iter = vi.insert_after(iter, *iter); // 复制当前元素
			prev = iter;
			++iter; // 向前移动迭代器，跳过当前元素以及插入到它之前的元素
		
		} else {
			iter = vi.erase_after(prev);          // 删除偶数元素
			// 不应向前移动迭代器，iter 指向我们删除的元素之后的元素
		}
	}
	for (const auto &i : vi) {
		cout << i << " ";
	}
	return 0;
}
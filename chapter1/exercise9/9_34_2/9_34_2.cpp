
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

int main() {
	list<int> vi = {0,2,4,6,8};
	list<int>::iterator iter = vi.begin(); 
	iter = vi.begin();
	while (iter != vi.end())
	if (*iter % 2) // 如果是奇数
		iter = vi.insert(iter, *iter); // 在 iter *之前* 插入 iter 的副本
	++iter; // 在 if 语句之外，在每次循环迭代结束时执行

	for (const auto &i : vi) {
		cout << i << " ";
	}
	return 0;
	}
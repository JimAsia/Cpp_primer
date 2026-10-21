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
	
	list<int> vi = {0,1,2,3,4,5,6,7,8,9};
	list<int>::iterator iter = vi.begin(); 
	/*
	// 如果容器中存在奇数，程序将陷入死循环（无限循环）；如果全是偶数，程序能正常结束。
	list<int> vi = {0,2,4,6,8};
	list<int>::iterator iter = vi.begin(); 
	iter = vi.begin();
	while (iter != vi.end())
    if (*iter % 2) // 如果是奇数
        iter = vi.insert(iter, *iter); // 在 iter *之前* 插入 iter 的副本
    ++iter; // 在 if 语句之外，在每次循环迭代结束时执行
	
	*/
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);
			++iter;
			++iter;
		}
		else
			iter = vi.erase(iter);
	}
	// 0 1 
	for (const auto &i : vi) {
		cout << i << " ";
	}
	return 0;
}
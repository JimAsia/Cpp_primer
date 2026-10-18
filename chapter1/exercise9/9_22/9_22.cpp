/*
死循环（最致命的错误）：
当 *iter == some_val 成立时，代码执行了 iv.insert(iter, 2 * some_val);。但是，iter 并没有被更新。下一次循环时，iter 依然指向原来的元素，依然满足 *iter == some_val 的条件，从而继续插入……导致程序陷入无限循环。

mid 迭代器失效（越界风险）：
mid 是基于初始的 iv.size() / 2 算出来的固定位置。每次执行 insert，vector 的长度都会增加。如果发生了内存重新分配（Reallocation），原来的 iter 和 mid 都会变成野指针，导致未定义行为（崩溃）。即使没有重新分配，mid 的位置也会被“挤”得向后偏移，循环的终止条件会被破坏。

插入位置与更新逻辑冲突：
insert(iter, val) 会在 iter 之前插入元素，并返回指向新插入元素的迭代器。如果没有正确处理返回值，原迭代器的指向就会乱套。

*/
#include <vector>
#include <iostream>

// 内存重新分配（Reallocation）导致的未定义行为（UB）。
int main() {
	std::vector<int> iv{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int>::iterator iter = iv.begin(),
						mid = iv.begin() + iv.size() / 2;
	int some_val = 5;
	while (iter != mid) {
		if (*iter == some_val) {
			// 接收新插入元素的迭代器
			iter = iv.insert(iter, 2 * some_val); 
			// 此时 iter 指向新元素，需要前进一步，让它指向原来的元素
			++iter; 
			// 因为插入了一个元素，原来的 mid 被向后推了，所以 mid 也要跟着后移
			++mid;  
		}
		// 移动到下一个元素（无论是新插入的元素之后，还是普通元素）
		++iter; 
	}
	for (const auto &i : iv)
		std::cout << i << " ";
	return 0;
}

/*
初始容量已满：当你用初始化列表创建 std::vector<int> iv{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 时，编译器分配的容量（capacity）通常刚好是 10。

触发搬家（Reallocation）：当循环走到 5（索引 4）准备执行 insert 时，因为容量满了，vector 在底层偷偷去内存里找了一块更大的新空间，把旧数据搬了过去，然后销毁了旧空间。

iter 活下来了，但 mid 死了：

iter = iv.insert(...)：这行代码用 insert 的返回值重新赋予了一个指向新内存的合法迭代器，所以 iter 安全了。

但是，mid 没有被更新！mid 依然指向那块已经被销毁的旧内存，它变成了一个危险的野指针（悬空迭代器）。

荒诞的越界：

当你执行 ++mid; 时，是在一块非法的内存上做加法。

随后，iter 继续在新数组里遍历（走到 6, 7, 8, 9, 10），最终走到了 end()。

正常情况下，iter 到 end() 循环就该结束了。但是因为 mid 已经变成了一个乱跑的野指针，iter != mid 依然成立！

疯狂乱插：

iter 越过了边界，继续往后读取内存。

如果越界的内存里恰好有值为 5 的垃圾数据，iter == some_val 就会成立，程序就会在越界的位置强行执行 insert。

这种非法的插入彻底搞乱了 vector 的底层结构，导致程序在末尾疯狂追加数据 10，直到读取到某个错误的终止符或者直接崩溃。
*/
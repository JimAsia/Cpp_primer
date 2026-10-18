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
	vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int>::iterator it = v1.begin() + 2; // 在3之前插入
	int n;
	cout << "输入一个数字（输入其他则结束循环）： ";
	while (cin >> n)
		it = v1.insert(it, n);
	for (const auto &i : v1)
		cout << i << " ";
	
	return 0;
	
}
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
	vector<int> v(25, 1);
	for (const auto &i : v)
		cout << i << " ";
	cout << endl;
	v.resize(100);
	for (const auto &i : v)
		cout << i << " ";
	cout << v.size();
	
	cout << endl;
	v.resize(10);
	for (const auto &i : v)
		cout << i << " ";
	cout << endl;
	return 0;
}
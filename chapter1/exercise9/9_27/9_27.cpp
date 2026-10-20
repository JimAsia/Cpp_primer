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
	std::forward_list<int> fl{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	forward_list<int>::iterator prev = fl.before_begin();
	forward_list<int>::iterator curr = fl.begin();
	while (curr != fl.end()) {
		if (*curr % 2 != 0) 
			curr = fl.erase_after(prev);
		else {
			prev = curr;
			++curr;
		}
	}
	cout << "Odd: ";
	for (const auto &i : fl)
		cout << i << " ";
	return 0;
}
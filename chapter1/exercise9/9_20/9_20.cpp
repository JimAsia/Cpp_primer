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
	list<int> list1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	deque<int> deque1;
	deque<int> deque2;
	deque<int>::iterator it;
	for (const auto &i : list1) {
		if (i % 2 == 0)
			deque2.push_back(i);
		else
			deque1.push_back(i);
	}
	cout << "Odd: ";
	for (it = deque1.begin(); it != deque1.end(); ++it)
		cout << *it << " ";
	cout << endl;
	cout << "Even: ";
	for (it = deque2.begin(); it != deque2.end(); ++it)
		cout << *it << " ";

	return 0;
}
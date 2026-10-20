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
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	vector<int> v;	
	for (unsigned int i = 0; i < sizeof(ia) / sizeof(int); ++i) {
		v.push_back(ia[i]);
	}
	vector<int>::iterator it = v.begin();
	list<int> l(v.begin(), v.end());
	list<int>::iterator it2 = l.begin();
	while (it != v.end()) {
		if(*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}
	while (it2 != l.end()) {
		if(*it2 % 2 != 0)
			it2 = l.erase(it2);
		else
			++it2;
	}
	cout << "even: " ;
	for (const auto &i : v)
		cout << i << " ";
	cout << endl;
	cout << "odd: ";
	for (const auto &i : l)
		cout << i << " ";
	cout << "\nindex of a[i]: ";
	cout << sizeof(ia) / sizeof(int);

	return 0;
}
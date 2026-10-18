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
	string s;
	list<string> list1;
	list<string>::iterator it = list1.end();
	while (getline(cin, s))
		it = list1.insert(it, s);
	list<string>::iterator it2 = list1.begin();
	while (it2 != list1.end()) {
		cout << *it2 << endl;
		++it2;
	}
	return 0;
}

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
	deque<string> queue;
	while (getline(cin, s))
		queue.push_back(s);
	deque<string>::iterator it = queue.begin();
	while (it != queue.end()) {
		cout << *it << endl;
		++it;
	}
	return 0;
}

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
	vector<char> c{'H', 'e', 'l', 'l', 'o', '\0'};
	string s(c.begin(), c.end());

	cout << s << endl;

	string s2(c.data(), c.size());

	cout << s2 << endl;
	return 0;

}
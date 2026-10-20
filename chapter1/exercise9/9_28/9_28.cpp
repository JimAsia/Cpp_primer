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


void inserFowardlist(forward_list<string> &fs, const string &s1, const string &s2)
{
	bool found = false;
	forward_list<string>::iterator prev = fs.before_begin();
	forward_list<string>::iterator curr = fs.begin();
	while (curr != fs.end()) {
		if (*curr == s1) {
			found = true;
			curr = fs.insert_after(curr, s2);
			++curr;
			return;
		}
		else {
			prev = curr;
			++curr;
		}
	}
	if (!found)
		fs.insert_after(prev, s2);

}

int main()
{
	forward_list<string> listString{"hello", "world", "nihao", "world", "shijie", "world"};
	string str1{"world"}; // print: hello world bye nihao world shijie
	// string str1{"no"}; // print: hello world nihao world shijie bye
	string str2{"world"};
	inserFowardlist(listString, str1, str2);
	for (const auto &i : listString)
		cout << i << " ";
	return 0;
}
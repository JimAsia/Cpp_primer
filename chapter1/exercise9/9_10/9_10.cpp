#include <vector>
#include<iostream>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::string;

int main()
{
	vector<int> v1;
	const vector<int> v2;
	auto it1 = v1.begin();  // iterator
	auto it2 = v2.begin();  // const_iterator
	auto it3 = v1.cbegin(); // error: iterator  right: const_iterator
	auto it4 = v2.cbegin(); // const_iterator

	return 0;
}
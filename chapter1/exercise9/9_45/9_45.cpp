#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

void replaceName(string &name, const string &forwardName, const string &lastName)
{
	string::iterator it = name.begin();
	it = name.insert(it, forwardName.begin(), forwardName.end());
	name = name.append(lastName);
}

int main()
{
	string n{"chenhan"};
	string n2{"Mr"};
	string n3{"Jr."};

	replaceName(n, n2, n3);
	cout << n << endl;
	return 0;
}
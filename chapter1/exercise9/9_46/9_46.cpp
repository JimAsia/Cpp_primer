#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

void replaceName(string &name, const string &forwardName, const string &lastName)
{
	std::size_t it = 0;
	name.insert(it, forwardName);
	name.insert(it + name.size(), lastName);
	
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
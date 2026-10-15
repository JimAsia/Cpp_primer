#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

void process(std::ifstream &i) 
{
	string s;
	vector<string> v;
	while (getline(i, s)) {
		v.push_back(s);
	}
	for (auto &i : v)
		cout << i << std::endl;
		
}

int main()
{
	std::ifstream input("test.md");
	if (input) {
		process(input);
	}
	else {
		std::cerr << "couldn't open: " << std::endl;
	}

	return 0;
}

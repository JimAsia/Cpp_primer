#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;


int main() {
	string numbers("0123456789"), name("r2d2");
	string::size_type pos = numbers.find(name);
	cout << "find inex: " << (bool)(pos == string::npos);
	return 0;
}

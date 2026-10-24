#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

int main()
{
	string s{"ab2c3d7R4E6"};
	string::size_type pos = 0;
	string number{"0123456789"};
	// (pos = s.find_first_of(number, pos)) 找到数字返回下标
	while ((pos = s.find_first_of(number, pos)) != string::npos) {
		cout << "find inex: " << pos << " element is " << s[pos] << endl;
		++pos;
	}
	
	pos = 0;
	while ((pos = s.find_first_not_of(number, pos)) != string::npos) {
		cout << "find inex: " << pos << " element is " << s[pos] << endl;
		++pos;
	}
		
	return 0;
}
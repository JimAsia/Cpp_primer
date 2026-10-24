#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

using std::string;

int main()
{
	int i = 42;
	string s = std::to_string(i);
	double d = std::stod(s);
	cout << s << endl;
	cout << d << endl;
	string s2 = "pi = 3.14";
	// substr(pos, count)：从下标 pos 开始，截取 count 个字符，返回一个新的字符串（原字符串不变）。
	// stod 非常聪明，它遇到数字就开始解析，遇到非数字字符（比如中文的“岁”）就会自动停止。所以 "25.5岁" 会被成功转换为浮点数 25.5。
	// find_first_of: 3, substr(): 3.14, stod : 3.14
	d = std::stod(s2.substr(s2.find_first_of("+-.0123456789")));
	cout << d << endl;
	

	vector<string> vstr{"100", "50", "50"};
	int sum = 0;
	for (const string &s : vstr) {
		sum += std::stoi(s);
	}
	cout << "int sum: ";
	cout << sum << endl;

	vector<string> vstr1{"100.25", "0.50", "1.50"};
	double sum2 = 0;
	for (const string &s : vstr1) {
		sum2 += std::stod(s);
	}
	cout << "double sum: ";
	cout << sum2 << endl;

	return 0;
}
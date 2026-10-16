#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::istream;

/*
istream &printLine(istream &in)
{
	string line;
	while (getline(in, line))
		cout << line << endl;
	cout << endl;
	return in;
}
*/

int main()
{
	
	string line, word;
	vector<string> vStr;
	std::ifstream inText("test.md");
	std::istringstream istr;
	if (inText.is_open()) {
		cout << "打印每行: " << endl;
		while (getline(inText, line)) {
			cout << line << endl;
			vStr.push_back(line);
		}
		cout << endl;
		inText.close();
	}
	else {
		std::cerr << "无法打开文件" << endl;
	}
	for (auto const &i : vStr) {
		// cout << i << endl;
		// 8_10 打印每个单词
		// std::istringstream istr(i);
		istr.str(i);
		string word;
		cout << "打印行 " << i << " 的每个单词: " << endl;
		while (istr >> word) {
			cout << word << endl;
		}
		istr.clear(); // 条件状态位复位，流状态有效。
	}
	
	
	
	
	
	return 0;
}
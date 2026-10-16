#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

// 8.1 8.2
// 输出一行打印一行
std::istream &inData(std::istream &in)
{
	string i;
	while (in >> i) {
			cout << i << " ";
	}
	cout << std::endl;
	// in.clear(in.rdstate() & ~in.failbit & ~in.badbit);  // 流已复位，当前状态是否有效: false。没有复位eof，所以还是流还是已经结束了的状态。
	in.clear(); // 流已复位，当前状态是否有效: true
	return in;
}

int main()
{
	string line;
	getline(cin, line);
	std::istringstream iss(line);
	inData(iss);
	std::cout << "请输入一些文本 (按 Ctrl+D 或 Ctrl+Z 结束):" << std::endl;
	// 验证流是否已经复位（此时应该输出 true 或 1）
	// boolalpha将1或0改成输出true或false
    std::cout << "流已复位，当前状态是否有效: " << std::boolalpha << std::cin.good() << std::endl;
	inData(cin);    // 流已复位，当前状态是否有效: true 可继续读入。false就不行。
	return 0;
}
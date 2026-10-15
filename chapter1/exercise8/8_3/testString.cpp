#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
	string i;
	while (cin >> i) {   // 换行符相当于一次循环，只在遇到 文件结束符（EOF） 时才会返回 false 导致循环结束。
			cout << i;
	}
	return 0;
}

// 遇到文件结束符（EOF）
// 输入类型不匹配（格式错误）
// 发生严重的流错误（badbit）
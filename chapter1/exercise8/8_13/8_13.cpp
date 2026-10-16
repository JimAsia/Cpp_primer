#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <cctype>

using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::ifstream;

struct PersonInfo {
    string name;
    vector<string> phones;
};

bool valid(const string& phone) {
    // 规则1：长度限制（比如不能太短或太长）
    if (phone.size() < 7 || phone.size() > 15) {
        return false;
    }
    // 规则2：必须全部是数字（或者允许横线'-'）
    for (char c : phone) {
        if (!isdigit(c) && c != '-') {
            return false;
        }
    }
    return true; // 验证通过
}

string format(const string& phone) {
    // 这里为了演示，我们简单做一下格式化，比如统一加上括号
    // 实际教材中可能是为了去掉横线或重新排列
    return "(" + phone + ")"; 
}

int main()
{
	string line, word;
	vector<PersonInfo> people;
	ifstream input("phoneNumber.md");
	if (input.is_open()) {
		cout << "每行电话号码数据： " << endl;
		while (getline(input, line)) {
			PersonInfo info;
			std::istringstream istr(line);
			istr >> info.name;
			while (istr >> word)
				info.phones.push_back(word);
			people.push_back(info);
		}

	}
	// 将修改结果保存到"newNumber.md"
	std::ofstream output("newNumber.md");
	// 8_14
	for (const auto &everyone : people) {
		std::ostringstream formatted, badNums;
		// 8_14
		for (const auto &nums : everyone.phones) {
			if (!valid(nums)) {       
				badNums << " " << nums;
			}
			else
				formatted << " " << format(nums);

		}
		if (badNums.str().empty()) {
			cout << everyone.name << " " << formatted.str() << endl;
			// 用ofstream流输出文件
			output << everyone.name << " " << formatted.str() << endl;
		}
		else
			std::cerr << "input error: " << everyone.name << " invalid number "<< badNums.str() << endl;
	}
	return 0;
}
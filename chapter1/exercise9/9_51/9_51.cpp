#include <iostream>
#include <string>
#include <map>
#include <sstream> // 必须包含这个头文件
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Date {
    unsigned year = 0;
    unsigned month = 0;
    unsigned day = 0;

public:
    Date(string date);
    void print() const { cout << year << "-" << month << "-" << day << endl; }
};

Date::Date(string date) {
    // 1. 用 map 替代又臭又长的 if-else
    static const std::map<string, unsigned> monthMap = {
        {"Jan", 1}, {"January", 1}, {"Feb", 2}, {"February", 2},
        {"Mar", 3}, {"March", 3}, {"Apr", 4}, {"April", 4},
        {"May", 5}, {"Jun", 6}, {"June", 6}, {"Jul", 7}, {"July", 7},
        {"Aug", 8}, {"August", 8}, {"Sep", 9}, {"September", 9},
        {"Oct", 10}, {"October", 10}, {"Nov", 11}, {"November", 11},
        {"Dec", 12}, {"December", 12}
    };

    std::istringstream iss(date);

    // 2. 判断是否是 1/1/1990 格式（包含斜杠）
    if (date.find('/') != string::npos) {
        char slash1, slash2;
        // istringstream 可以自动跳过斜杠读取数字
        iss >> month >> slash1 >> day >> slash2 >> year; 
    } 
    // 3. 英文月份格式
    else {
        string monthStr;
        iss >> monthStr; // 先读出第一个单词
        month = monthMap.at(monthStr); // 从 map 里拿月份数字

        string dayStr;
        iss >> dayStr; // 读出日，可能带逗号如 "1,"
        
        // 如果有逗号，去掉逗号再转数字
        if (dayStr.back() == ',') {
            dayStr.pop_back();
        }
        day = std::stoul(dayStr); // 字符串转无符号长整型

        iss >> year; // 最后读年份
    }
}

int main() {
    Date d1("January 1, 1900");
    Date d2("1/1/1990");
    Date d3("Jan 1 1900");

    d1.print(); // 输出: 1900-1-1
    d2.print(); // 输出: 1990-1-1
    d3.print(); // 输出: 1900-1-1

    return 0;
}
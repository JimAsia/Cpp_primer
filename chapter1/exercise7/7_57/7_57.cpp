#include <string>
// #include <vector>
using std::string;
// using std::vector;


class Account
{
public:
	Account() = default;
	Account(string u, double b, int c, string i) : userName(u), balance(b),code(c), id(i) {}
	// 设置利率（所有账户共享）
    static void set_interest_rate(double rate);
private:
	string userName;
	double balance;
	int code;
	string id;
	// 静态成员变量：用于生成账号和记录利率
    static int total_accounts_;
    static double interest_rate_;
};

int Account::total_accounts_ = 1000; // 账号从1001开始
double Account::interest_rate_ = 1.5; // 默认利率 1.5%
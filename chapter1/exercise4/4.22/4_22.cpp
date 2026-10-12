#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main()
{
    // 4.22
    vector<int> v = {10, 100, 60, 75, 90};
    for (auto &grade : v) {
        std::string f = (grade > 75) ? "high pass" : 
                                    (grade >= 75) ? "low pass" :
                                                (grade < 60) ?  "fail" : "pass";
        cout << f << endl;
    }
    // 4.23
    std::string s = "word";
    std::string p1 = s + (s[s.size() - 1] == 's' ? "" : "s");
    cout << p1 << endl;
    return 0;
}
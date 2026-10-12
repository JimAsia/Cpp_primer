#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned scores[11];  // 里面的值是随机的。
    unsigned grade;
    while (cin >> grade)
        ++scores[grade/10];
    for (auto i : scores)
        cout << i << " ";
    return 0;
}

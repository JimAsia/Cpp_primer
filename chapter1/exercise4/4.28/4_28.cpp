#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;

int f()
{
    return 0;
}

int main()
{
    // 4.28
    int a = 10;
    double d = 2.3;
    char c = 'a';
    char *p1 = &c;
    cout << sizeof(a) << endl;
    cout << sizeof(d) << endl;
    cout << sizeof(c) << endl;
    cout << sizeof(p1) << endl;
    // 4.29
    int x[10] = {1, 2, 9};
    int *p = x;
    cout << sizeof(x)/ sizeof(*x) << endl;
    cout << sizeof(p)/ sizeof(*p) << endl;
    // 4.30
    int x1 = 2, y = 4, b = 3;
    int i = 1;
    // std::vector<int> a = {1, 2, 3};
    // auto p1 = &a;
    cout << sizeof x1 + y << endl;
    // cout << sizeof p1->a[i] << endl;
    cout << (sizeof a < b) << endl;
    cout << sizeof f() << endl;
    return 0;

}         
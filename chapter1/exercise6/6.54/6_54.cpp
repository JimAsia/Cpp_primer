#include <iostream>
#include <vector>

using std::vector;
using pf = int (*)(int, int);

int f1(int, int);
int add(int, int);
int sub(int, int);
int mul(int, int);
int divd(int, int);
vector<pf> v{add, sub, mul, divd};

int main()
{
    int x = 10, y = 5;
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << (*it)(x, y) << std::endl;
    }
    return 0;
    
}

int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
int divd(int a, int b)
{
    return a / b;
}
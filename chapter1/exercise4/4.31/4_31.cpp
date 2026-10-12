#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main()
{
    // 4.31
    vector<int> ivec = {2, 4, 6, 8};
    vector<int>::size_type cnt = ivec.size();
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--) {
        ivec[ix] = cnt;
        cout << ivec[ix] << " ";
    }
    // 4.32
    // 条件中的 ix != size 和 ptr != ia + size 实际上是等价的（在正常遍历且数组未损坏的情况下）。
    constexpr int size = 5;
    int s = 0;
    int ia[size] = {1, 2, 3, 4, 5};
    for(int *ptr = ia, ix = 0; ix != size && ptr != ia+size; ++ix, ++ptr) {
        s++;
    }
        cout << s << endl;
    // 4.33
    int someValue = 1, x = 0, y = 0;
    someValue ? ++x, ++y : --x, --y;  // 实际执行: (someValue ? (++x, ++y) : (--x)), (--y)
    cout << x << endl;
    cout << y << endl;  // --y 在条件表达式外面，无论真假都会执行。
    return 0;
}
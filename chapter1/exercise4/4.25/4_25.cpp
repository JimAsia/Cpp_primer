#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::cin;

int main() {
    // 4.25
    char c = 'q';
    cout << (~c << 6) << endl;
    // 4.27
    unsigned long ull = 3, ul2 = 7;
    cout << (ull & ul2) << endl;
    cout << (ull | ul2) << endl;
    cout << (ull && ul2) << endl;
    cout << (ull || ul2) << endl;
    cout << std::bitset<4>(ull & ul2) << endl;
    cout << std::bitset<4>(ull | ul2) << endl;
    cout << std::bitset<4>(ull && ul2) << endl;
    cout << std::bitset<4>(ull || ul2) << endl;
    return 0;
}
/* 4.25
真正的完整计算过程：
确定 c 的值：
'q' 的 ASCII 码是 113，二进制 0111 0001。
类型提升：
提升为 32 位有符号 int：
0000 0000 0000 0000 0000 0000 0111 0001
按位取反（~c）：
每一位取反，得到 -114 的补码：
1111 1111 1111 1111 1111 1111 1000 1110
左移 6 位（<< 6）：
整个二进制数向左平移 6 位，低位补 6 个 0：
1111 1111 1111 1111 1110 0011 1000 0000
计算最终结果的十进制：
最高位是 1，是负数（补码）。
减 1 求反码：1111 ... 1110 0011 0111 1111s
按位取反求原码：1000 ... 0001 1100 1000 0000
计算绝对值：1 1100 1000 0000 = 4096+2048+1024+128=7296
4096+2048+1024+128=7296
加上负号：-7296
*/
// 4.4 4.5 4.6
#include <iostream>

using std::cout;
using std::endl;

bool is_even(int a) 
{
    if (a % 2 == 0)
        return true;
    else 
        return false;
}

int main()
{
    int a1 = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;
    int a = -30 * 3 + 21 / 5;
    int b = -30 + 3 * 21 / 5;
    int c = 30 / 3 * 21 % 5;
    int d = -30 / 3 * 21 % 4;

    cout << a1 << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;

    if (is_even(c))
        cout << c << " is even.";
    else
        cout << c << " is odd.";
    cout << endl;

    return 0;

}
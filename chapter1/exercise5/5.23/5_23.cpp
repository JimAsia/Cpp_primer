#include <iostream>

using namespace std;

int main()
{
    double x, y;
    cout << "Enter x and y:" << endl;
    cin >> x >> y;
    if (y == 0) {
        throw runtime_error("Divisor must not be zero.");  // 5.24
    }
    else
        cout << x / y << endl;
    // cout << x / y << endl;  // y = 0, print inf
    return 0;

}
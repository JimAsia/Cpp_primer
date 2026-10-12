#include <iostream>
using namespace std;
int fact(int val);

// 6.3 6.4
int main()
{
    int v;
    cout << "Enter a number: ";
    cin >> v;
    cout << "Result: ";
    cout << fact(v) << endl;
    return 0;
}

int fact(int val)
{
    if (val <= 1)
        return 1;
    return val * fact(val - 1);
}
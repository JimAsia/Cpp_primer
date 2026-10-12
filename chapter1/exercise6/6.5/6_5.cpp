#include <iostream>

using namespace std;

double myAbs(double val);

int main()
{
    double v;
    cout << "Enter a number: ";
    cin >> v;
    cout << "Result: ";
    cout << myAbs(v) << endl;
    return 0;
}

double myAbs(double val)
{
    if (val < 0)
        return -val;
    else
        return val;
}
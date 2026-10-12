#include <iostream>


using std::cout;
using std::endl;
using std::cin;

int main()
{
    int i = 3;
    double d = 4.5;
    cout << (i*=d) << endl;
    cout << static_cast<int> (i *= d) << endl;

    return 0;
}
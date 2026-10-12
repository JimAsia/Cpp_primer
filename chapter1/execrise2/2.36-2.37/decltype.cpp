#include <iostream>
using namespace std;

int main() {
    int a = 3, b = 4;
    decltype(a) c = a;  // int c
    decltype((b)) d = a;  // int &d
    ++c;
    ++d;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;

    int a1 = 3, b1 = 4;
    decltype(a1) c1 = a1;  // int c1
    decltype(a1 = b1) d1 = a1;  // int &d1
    d1 += 2;
    cout << "a1: " << a1 << endl;
    cout << "b1: " << b1 << endl;
    cout << "c1: " << c1 << endl;
    cout << "d1: " << d1 << endl;
    

    return 0;
}

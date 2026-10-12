#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *p;
    int *&ref = p;

    ref = &a;
    *ref = 0;
    cout << "*p: " << *p << endl;
    cout << "*ref: " << *ref << endl;
    cout << "a: " << a << endl;

    return 0;
}
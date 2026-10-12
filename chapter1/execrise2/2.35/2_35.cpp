#include <iostream>
using namespace std;

int main() {
    const int i = 42;
    auto j = i;   // int j
    const auto &k = i;  // const int &k
    auto *p = &i;   // const int *p
    const auto j2 = 1, &k2 = i;    // const int j2 = 1, const int &k2
    const int &cr = i;
    const int *ptr = &i;
    auto c = cr;   // int c
    auto d = ptr;  // const int *d
    return 0;
}

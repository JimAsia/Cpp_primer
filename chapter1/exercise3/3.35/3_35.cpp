#include <iostream>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    for (auto i = std::begin(a); i != std::end(a); i++) {
        *i = 0;
        cout << *i << " ";
    }
    for (auto i: a)
        cout << i << endl;
    return 0;
}
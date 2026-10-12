#include <iostream>

int main()
{
    int *i = nullptr, ri = 10, j = 6;
    i = &ri;
    std::cout << *i << " " << ri << std::endl;
    *i = 2;
    std::cout << *i << " " << ri << std::endl;
    ri = 5;
    i = &j;
    std::cout << *i << " " << ri << std::endl;
    return 0;
}
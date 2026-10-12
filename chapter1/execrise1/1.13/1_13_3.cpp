#include<iostream>
int main() 
{
    int x = 0, y = 0, max = 0, min = 0;
    std::cin >> x >> y;
    if (x > y) {
        max = x;
        min = y;
    }
    else {
        max = y;
        min = x;
    }
    for (;max >= min;max--) 
        std::cout << max << std::endl;
    return 0;
}
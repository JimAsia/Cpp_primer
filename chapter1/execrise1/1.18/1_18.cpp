#include<iostream>
int main() 
{
    int currVal = 0, val = 0;
    if (std::cin >> currVal) {
        int temp = 1;
        while (std::cin >> val) {
            if (currVal == val) {
                ++temp;
            }
            else {
                std::cout << currVal << " occurs " << temp << " times " << std::endl;
                currVal = val;
                temp = 1;
            }
        }
        std::cout << currVal << " occurs " << temp << " times " << std::endl;
    }
    return 0;
}
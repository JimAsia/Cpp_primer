#include <iostream>

int mySum(std::initializer_list<int> li);

int main()
{
    std::initializer_list<int> a = {10, 15};
    int sum = mySum(a);
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}

int mySum(std::initializer_list<int> li)
{
    int sum = 0;
    for (const auto &i : li)
    {
        sum += i;
    }
    return sum;
}
#include <iostream>
#include "Chapter6.h"

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3};
    print(v.begin(), v.end());

    return 0;
}

void print(std::vector<int>::const_iterator beg,std::vector<int>::const_iterator end)
{
    for (auto i = beg; i != end; ++i)
        cout << *i << endl;
}
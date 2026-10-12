#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    for (auto &i : v) {
        i = (i % 2 == 1) ? i * 2 : i;
        cout << i << " ";
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1(10, 5);
    for (auto i = v1.begin(); i != v1.end(); ++i) {
        *i *= 2;
        cout << *i << " ";
    }

    return 0;
}
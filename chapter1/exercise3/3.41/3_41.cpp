// 3.41    3.42
#include <iostream>
#include <vector>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int a1[] = {1, 2, 3, 4, 5};
    vector<int> v1(std::begin(a1), std::end(a1));
    for (auto &v : v1)
        cout << v << " ";
    cout << endl;
    const int index = v1.size();
    int a2[index] = {0};
    for (int i = 0; i < index; ++i) {
        a2[i] = v1[i];
        cout << a2[i] << " ";
    }
    return 0;
}
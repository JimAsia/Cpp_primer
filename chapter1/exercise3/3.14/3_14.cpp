#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int j;
    vector<int> i;
    while (cin >> j)
        i.push_back(j);
    for (auto &s : i)
        cout << s << " ";

    return 0;

}
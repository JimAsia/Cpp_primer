#include <iostream>
#include <vector>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main()
{
    int ia[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    for (const int (&i)[4] : ia)
        for (int j : i)
            cout << j << " ";
    cout << endl;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            cout << ia[i][j] << " ";
    cout << endl;
    for (int (*p)[4] = begin(ia); p != end(ia); ++p)
        for (int *q = begin(*p); q != end(*p); ++q)
            cout << *q << " ";
    
    return 0;
}
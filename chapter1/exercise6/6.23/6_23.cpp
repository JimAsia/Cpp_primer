#include <iostream>

using namespace std;

void print(const int *ia, int size);

int main()
{
    int i = 2;
    int j[2] = {0, 1};
    print(j, i);
    return 0;
}

void print(const int *ia, int size)
{
    for (int i = 0; i != size; ++i)
        cout << ia[i] << " ";
}
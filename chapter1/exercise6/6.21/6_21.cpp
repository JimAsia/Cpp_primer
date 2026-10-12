#include <iostream>

using namespace std;

const int *myMax(const int i, const int *j);

int main()
{
    const int a = 5, x = 6;
    const int *b = &x;
    cout << "Max: " << *myMax(a, b) << endl;
    return 0;
}

const int *myMax(const int i, const int *j) 
{
    const int *temp = &i;
    if (*temp > *j) {
        return temp;
    }
    return j;
}
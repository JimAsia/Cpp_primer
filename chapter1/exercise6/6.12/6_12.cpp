#include <iostream>

using namespace std;

void swap(int &x, int &y);

int main()
{
    int a, b;
    cout << "Enter two number: ";
    cin >> a >> b;
    // int *p1 = &a;
    // int *p2 = &b;
    swap(a, b);
    cout << "Swap: " << a << " " << b;
    return 0;

}

void swap(int &x, int &y) 
{
    int temp = x;
    x = y;
    y = temp;
}

// 引用好，无拷贝，效率高

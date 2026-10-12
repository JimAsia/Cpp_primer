#include <iostream>

using namespace std;

void reset(int &x);

int main()
{
    int a = 0;
    char c;
    cout << "Original number: " << a << endl;
    cout << "Enter a number to change it: ";
    cin >> a;
    cout << "Now: " << a << endl;
    cout << "Enter a Y(y) to reset it: ";
    cin >> c;
    if (c == 'y' || c == 'Y')
    {
        reset(a);
        cout << "Original: " << a << endl;
    }
    else
        cout << "Not reset";
    return 0;

}

void reset(int &x)
{
    x = 0;
}
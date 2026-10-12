#include <iostream>

using namespace std;

int counter();

int main()
{
    int v;
    
    cin >> v;
    while (v > 0) {  
        cout << counter() << " ";
        v--;
    }
    return 0;
}

int counter()
{
    static int j = 0;
    return ++j;
}
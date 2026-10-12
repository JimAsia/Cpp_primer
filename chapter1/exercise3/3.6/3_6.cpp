#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string s("123456");
    cout << "original: ";
    cout << s << endl;
    for (auto &s1 : s)
        s1 = 'X'; 
    cout << "convert: ";
    cout << s << endl;
    return 0;
}
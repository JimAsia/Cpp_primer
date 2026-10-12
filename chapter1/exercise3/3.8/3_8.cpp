#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string s("123456");
    int i = 0;
    cout << "original: ";
    cout << s << endl;
    /*while (i < s.size()) {
        s[i] = 'X';
        ++i;
    }*/
    for (i = 0; i < s.size(); ++i)
        s[i] = 'X';
    cout << "convert: ";
    cout << s << endl;

    string str;
    cout << str[0] << endl;
    return 0;
}
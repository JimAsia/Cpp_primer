#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string str;
    getline(cin, str);
    for (auto &s : str)
        if (!ispunct(s))
            cout << s;
    cout << endl;
    const string s1 = "Keep out!";
    for (auto &c : s1) // const char &c
        if (!ispunct(c))
            cout << c;
    return 0;

}
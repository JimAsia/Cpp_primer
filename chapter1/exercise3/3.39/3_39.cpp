#include <iostream>
#include <string>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s1 = "hello";
    string s2 = "hi";

    cout << "compare with s1 and s2: ";
    if (s1 > s2)
        cout << "s1 > s2" << endl;
    else if (s1 == s2)
        cout << "s1 = s2" << endl;
    else 
        cout << "s1 < s2" << endl;

    char c1[] = "hello";
    char c2[] = "hahaha";

    cout << "compare with c1 and c2: ";
    if (strcmp(c1, c2) > 0)
        cout << "c1 > c2" << endl;
    else if (strcmp(c1, c2) == 0)
        cout << "c1 = c2" << endl;
    else 
        cout << "c1 < c2" << endl;

    return 0;

}
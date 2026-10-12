#include "person.h"
#include<iostream>

using std::cout;
using std::endl;
using std::string;
using std::cin;

int main()
{
    string s1{"zhu"};
    string s2{"wuyi"};
    Person p(s1, s2);
    print(cout, p);
    cout << "Enter name and address: ";
    read(cin, p);
    print(cout, p);
    getchar();
    return 0;
}


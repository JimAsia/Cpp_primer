#include "person.h"
#include<iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string s1{"zhu"};
    string s2{"wuyi"};
    Person p(s1, s2);
    cout << p.getName() << endl;
    cout << p.getAdress() << endl;
    getchar();
    return 0;
    
}


#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isUpper(const string str);
void to_lower(string &str);

int main()
{
    string s = "Hello, World";
    if (isUpper(s))
        cout << "有大写字母" << endl;
    else
        cout << "没有大写字母" << endl;
    to_lower(s);
    cout << s << endl;
    return 0;
}

bool isUpper(const string str) 
{
    for (auto i : str)
        if (isupper(i))
            return true;
    return false;
}

void to_lower(string &str)
{
    for (auto &i : str) {
        i = tolower(i);
    }
    
}
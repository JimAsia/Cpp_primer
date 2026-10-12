#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
    string j;
    vector<string> i;
    while (cin >> j)
        i.push_back(j);
    for (auto &s : i) {
        for (auto &str : s)
            str = toupper(str);
        cout << s << endl;
    }
    return 0;

}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
    string j;
    vector<string> i;
    while (getline(cin, j))
        i.push_back(j);
    for (auto &s : i)
        cout << s << endl;

    return 0;

}
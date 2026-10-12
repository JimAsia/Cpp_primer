#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    string str;
    vector<string> v;
    bool found = false;
    while (cin >> str)
        v.push_back(str);
    if (v.empty()) {
        cout << "没有输入任何单词" << endl;
        return 0;
    }
    int i = 0;
    while (i != v.size() - 1) {
        if (v[i] != v[i+1]) {
            ++i;
            continue;
        }
        if (!isupper(v[i][0])) {
            v[i][0] = toupper(v[i][0]);
            found = true;
            cout << v[i] << endl;
            break;
        }
            
    }
    
    if (!found)
        cout << "None" << endl;
    return 0;
}
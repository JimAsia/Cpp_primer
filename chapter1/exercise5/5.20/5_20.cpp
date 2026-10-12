#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string str;
    vector<string> v;
    while (cin >> str)
        v.push_back(str);
    if (v.empty()) {
        cout << "没有输入任何单词" << endl;
        return 0;
    }
    auto i = v.begin();
    while (i != v.end() - 1) {
        if (*i == *(i + 1)) {
            cout << *i << endl;
            break;
        }
        else
            ++i;
    }
    if (i == v.end() - 1)
        cout << "None" << endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    cout << "Enter your grade: ";
    vector<int> g;
    int grade;
    vector<string> str;
    while (cin >> grade)
        g.push_back(grade);
    for (auto &i : g) {
        if (i >= 90) {
            str.push_back("A");
        }
        else if (i >= 60) {
            str.push_back("B");
        }
        else {
            str.push_back("C");
        }
    }
    for (auto &i : str) {
        cout << i << " ";
    }

    return 0;
}
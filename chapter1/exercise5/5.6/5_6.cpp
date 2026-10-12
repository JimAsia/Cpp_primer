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
        (i >= 90) ? str.push_back("A"):
                    (i >= 60) ? str.push_back("B") : str.push_back("C"); 
    }
    for (auto &i : str) {
        cout << i << " ";
    }

    return 0;
}
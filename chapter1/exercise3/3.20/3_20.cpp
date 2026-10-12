#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
    int a;
    vector<int> v1;
    while (cin >> a)
        v1.push_back(a);
    for (decltype(v1.size()) i = 0; i < v1.size()-1; ++i) {
        int sum = 0;
        sum = v1[i] + v1[i+1];
        cout << sum << " ";
    }
    cout << endl;
    for (decltype(v1.size()) i = 0; i < v1.size()/2; ++i) {
        int sum = 0;
        sum = v1[i] + v1[v1.size()-i-1];
        cout << sum << " ";
    }

    return 0;
}
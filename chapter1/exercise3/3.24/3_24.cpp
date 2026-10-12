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
    for (auto i = v1.cbegin(); i != v1.cend()-1; ++i) {
        cout << *i + *(i+1) << " ";
    }
    cout << endl;
    
    // ***** 
    for (auto i = v1.begin(), j = v1.end()-1; i <= j; ++i, --j) {
        cout << *i + *j << " ";
    }

    return 0;
}
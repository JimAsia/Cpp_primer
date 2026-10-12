#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
    int i;
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<int> v6{10};
    vector<string> v7{10, "hi"};
    cout << "v1: ";
    for (auto i : v1)
        cout << i << " ";
    cout << endl;
    cout << "v2: ";
    for (auto i : v2)
        cout << i << " ";
    cout << endl;
    cout << "v3: ";
    for (auto i : v3)
        cout << i << " ";
    cout << endl;
    cout << "v4: ";
    for (auto i : v4)
        cout << i << " ";
    cout << endl;
    cout << "v5: ";
    for (auto i : v5)
        cout << i << " ";
    cout << endl;
    cout << "v6: ";
    for (auto i : v6)
        cout << i << " ";
    cout << endl;
    cout << "v7: ";
    for (decltype(v7.size()) j = 0; j < v7.size(); ++j)
        cout << v7[j] << " ";
    cout << endl;



    cout << "v1: ";
    auto it = v1.begin();
    while (it != v1.end()) {
        cout << *it << " ";
        ++it; 
    }
    cout << endl;
    cout << "v2: ";
    it = v2.begin();
    while (it != v2.end()) {
        cout << *it << " ";
        ++it; 
    }
    cout << endl;
    cout << "v3: ";
    it = v3.begin();
    while (it != v3.end()) {
        cout << *it << " ";
        ++it; 
    }
    cout << endl;
    cout << "v4: ";
    it = v4.begin();
    while (it != v4.end()) {
        cout << *it << " ";
        ++it; 
    }
    cout << endl;
    cout << "v5: ";
    it = v5.begin();
    while (it != v5.end()) {
        cout << *it << " ";
        ++it; 
    }
    cout << endl;
    cout << "v6: ";
    it = v6.begin();
    while (it != v6.end()) {
        cout << *it << " ";
        ++it; 
    }
    cout << endl;
    cout << "v7: ";
    auto its = v7.begin();
    while (its != v7.end()) {
        cout << *its << " ";
        ++its; 
    }
    cout << endl;
    
    return 0;
}
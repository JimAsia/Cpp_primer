#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    vector<int> v1 = {0, 1, 1, 2};
    vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};
    int temp = 0;
    if (v1.size() < v2.size())
        temp = v1.size();
    else
        temp = v2.size();
    for (int i = 0; i != temp; ++i)
        if (v1[i] != v2[i]) {
            cout << "Not same" << endl;
            return 0;
        }
    cout << "Same" << endl;
    return 0;
}
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void myVect(const vector<int> &a, vector<int>::const_iterator it);

int main()
{
    vector<int> ai = {10, 20, 30, 40};
    myVect(ai, ai.begin());
    return 0;
}

void myVect(const vector<int> &a, vector<int>::const_iterator it)
{
    if (it == a.end())
        return ;
    cout << *it << endl;
    ++it;
    return myVect(a, it);
}
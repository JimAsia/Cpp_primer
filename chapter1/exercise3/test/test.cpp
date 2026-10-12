#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
    string word;
    /* while (cin >> word) 
        cout << word << endl;*/
    // string str = "Hello" + ", "; 两个运算符号都不是string
    // string str = "Hello" + ", " + word;   不能把字面值直接相加（"Hello" + ", "）
    vector<int> ivec{42};
    for (auto &i : ivec)
        cout << i;
    cout << endl;
    int ia[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int (&row)[4] = ia[1];
    for (auto i : row)
        cout << i << " ";
    
    return 0;
}

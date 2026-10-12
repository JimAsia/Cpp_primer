#include <iostream>
#include <vector>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::end;
using std::begin;



int main()
{
/* array[]
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[] = {5, 6, 7, 8, 9, 10};
    int a1[] = {1, 2, 3, 4, 5, 6};
    int b1[] = {5, 6, 7};

    cout << "a compare with b: ";
    if ((end(a) - begin(a)) == (end(a1) - begin(a1))) {
        for (int i = 0; i < end(a) - begin(a); ++i) {
            if (a[i] != a1[i]) {
                cout << "Not same";
                return 0;
            }
        }
        cout << "Same";
    }
    else
        cout << "Not same";
    return 0;
*/
    vector<int> a;
    vector<int> b;
    int temp;
    cout << "enter number of a: ";
    while (cin >> temp)
    {
        a.push_back(temp);
    }
    cout << endl;

    cin.clear(); // 1. 重置错误标志（重新打开水龙头）
    cin.sync();  // 2. 清除残留的输入（可选，但推荐加上）


    cout << "enter number of b: ";
    while (cin >> temp)
    {
        b.push_back(temp);
    }
    cout << endl;
    cout << "a compare with b: ";
    if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); ++i) {
            if (*(a.begin()+i) != *(b.begin()+i)) {
                cout << "Not same";
                return 0;
            }
        }
        cout << "Same";
    }
    else
        cout << "Not same";
    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

string (&myStr())[10]
{
    static string a[10] = {"ni", "hao", "hi"};
    return a;
}

int main()
{
    myStr()[3] = "Right";
    for (auto &i : myStr())
        cout << i << endl;
    
    return 0;
}
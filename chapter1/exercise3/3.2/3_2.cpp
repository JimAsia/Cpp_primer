#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string line;

    // 读入一行
    /*while (getline(cin, line)) 
        cout << line << endl;*/
    
    
    // 读入一个词
        while (cin >> line) 
        cout << line << endl;

    return 0;
}
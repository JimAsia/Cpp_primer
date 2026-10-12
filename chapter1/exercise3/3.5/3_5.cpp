#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string line1;
    string line2;
    string line3;
    getline(cin, line1);
    getline(cin, line2);
    getline(cin, line3);
    line3 = line1 + " " + line2 + " " + line3;
    cout << "line: ";
    cout << line3 << endl;
    

    return 0;

}
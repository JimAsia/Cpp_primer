#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string line1;
    string line2;
    getline(cin, line1);
    getline(cin, line2);
    cout << "compare with line1 and line2:, bigest: ";
    if (line1 > line2)
        cout << line1 << endl;
    else 
        cout << line2 << endl;
    cout << "compare with size of line1 and line2, longest: ";
    if (line1.size() > line2.size())
        cout << line1 << endl;
    else 
        cout << line2 << endl;

    return 0;


}
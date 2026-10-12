#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    const char c1[] = "Hello";
    const char c2[] = "World";
    char *c = new char [strlen(c1) + strlen(c2) + 1];
    strcpy(c, c1);
    strcat(c, c2);
    char *p = c;
    while (*p) {
        cout << *p;
        ++p;
    }
    delete [] c;
    return 0;
}
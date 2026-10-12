#include <iostream>
#include "Student.h"
using namespace std;

int main() {
    Student s1("张三", 20);
    Student s2("李四", 22);

    s1.show();
    s2.show();

    return 0;
}
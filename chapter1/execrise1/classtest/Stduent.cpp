#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string n, int a) {
    name = n;
    age = a;
}

void Student::show() {
    cout << "姓名：" << name << "，年龄：" << age << endl;
}
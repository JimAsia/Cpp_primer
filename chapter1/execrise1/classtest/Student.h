#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // 构造函数
    Student(string n, int a);

    // 成员函数
    void show();
};

#endif
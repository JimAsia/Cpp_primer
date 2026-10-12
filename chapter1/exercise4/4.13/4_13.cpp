#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{   
    // 4.13
    int i;
    double d;
    d = i = 3.5;
    cout << "d = " << d << endl;
    cout << "i = " << i << endl;
    i = d = 3.5;
    cout << "d = " << d << endl;
    cout << "i = " << i << endl;
    // 4.14
    // if (42 = i) 表达式必须是可修改的左值
    if (i = 42) cout << "Always true " << endl; // if (i == 42)
    // 4.15
    double dval;
    int ival;
    int *pi = &ival;
    dval = ival = *pi = 0;  // 不能将 "int *" 类型的值分配到 "int" 类型的实体 赋值步骤 dval = (ival = (pi = 0));
    cout << "dval = " << dval << endl;
    cout << "ival = " << ival << endl;
    cout << "pi address is " << pi << endl;
    cout << "pi value is " << *pi << endl;

    return 0;
}
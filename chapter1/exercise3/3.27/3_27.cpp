#include <iostream>

int txt_size();

int main() 
{
    unsigned buf_size = 1024;
    int ia[buf_size];
    int ib[4 * 7 - 14];
    int ic[txt_size()];
    // char st[11] = "fundamental"; "const char [12]" 类型的值不能用于初始化 "char [11]" 类型的实体
}

int txt_size()
{
    return 10;
}

/* int ia[buf_size]; (有问题)
原因：在标准 C++ 中，数组在编译时就必须在编译期确定其大小。而变量 buf_size 被声明为 unsigned buf_size = 1024;，它是一个运行时变量（即使被赋值为 1024）。
结果：使用变量 buf_size 来定义数组大小，这叫做变长数组 (VLA)。变长数组是 C99 标准的特性，不是标准 C++ 的特性（尽管某些编译器如 GCC 可能作为扩展支持）。标准 C++ 中这会报错。
解决办法：将 1024 定义为常量，例如 const int buf_size = 1024; 或者 #define BUF_SIZE 1024。
2. int ib[4 * 7 - 14]; (没问题)
原因：4 * 7 - 14 是一个常量表达式 (const expression)。编译器在编译时就能计算出它的结果是 14。
结果：这完全等同于写 int ib[14];，是合法的数组声明。
3. int ic[txt_size()]; (有问题)
原因：和 ia 一样，txt_size() 是一个函数调用，它的返回值只能在运行时确定（即使函数体内写死了 return 10;）。
结果：这同样是在使用变长数组 (VLA)，在标准 C++ 中是不允许的。
解决办法：如果要定义大小为 10 的数组，应该直接使用字面常量，如 int ic[10];。
总结：
只有 ib 的声明是合法的。ia 和 ic 都因为使用了运行时才能确定的值作为数组大小，在标准 C++ 中属于非法操作。*/
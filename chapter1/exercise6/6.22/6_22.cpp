#include <iostream>

using namespace std;

const int myMax(const int i, const int *j);
void swap(const int *&i, const int *&j);


int main()
{
    const int a = 5, x = 6;
    const int *b = &x;
    const int *c = &a;
    cout << "Max: " << myMax(a, b) << endl;
    cout << "b: " << *b << " c: "<< *c << endl;
    swap(b, c);
    cout << "b: " << *b << " c: "<< *c << endl;
    return 0;
}

// 6.21

const int myMax(const int i, const int *j) 
{  
    if (i > *j) {
        return i;
    }
    return *j;
}




void swap(const int *&i, const int *&j)
{
    const int *temp = i;
    i = j;
    j = temp;
}

/*
swap 函数的参数类型：const int *&i
这个参数的意思是：对“指向常量的指针”的引用（Reference to a pointer to const int）。
指针本身（i 和 j）并不是常量，所以它们是可以被修改的。我们交换的是指针的指向，而不是指针所指向的值。
在 main 函数中，b 和 c 的类型是 const int *，它们作为实参传递给 const int *& 是完全匹配的。
因此，swap 成功地交换了 b 和 c 的指向
*/
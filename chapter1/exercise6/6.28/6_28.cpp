/*
#include <iostream>
#include <string>

using namespace std;

void error_msg(ErrCode e, initializer_list<string> il)
{
    cout << e.msg() << ": ";
    for (const auto &elem : il)  // const std::string &elem
        cout << elem << " ";
    cout << endl;
}
*/

/*
直接回答：应该将循环控制变量声明成引用类型，但必须是 const 引用（即 const auto &）。

下面详细解释“为什么”：

1. 为什么推荐使用引用？（性能原因）
如果不使用引用，写成 for (auto item : il)，每次循环都会发生一次拷贝。
如果 initializer_list 里的元素是基本类型（如 int），拷贝代价很小，无所谓；但如果元素是庞大的对象（比如很长的 std::string、结构体或类），每次都拷贝一次会带来巨大的性能开销。使用引用（&）直接绑定原对象，避免了拷贝。

2. 为什么必须加上 const？（语法与语义限制）
这是这道题最核心的考点。

底层机制：initializer_list 的本质是一个底层由常量数组支持的轻量级容器。它的设计就是只读（read-only）的。

它的 begin() 和 end() 返回的都是 const T* 指针。

如果你试图写成普通引用 for (auto &item : il)，编译器会直接报错。因为普通引用（非 const）无法绑定到一个 const 对象上（你无法通过普通引用去修改一个本质上不可修改的常量）。
*/

/*
正因为 initializer_list 的元素是 const 的，你绝对不能在循环里试图修改元素的值。

此外，initializer_list 的生命周期通常和它所绑定的局部变量一样短（它内部指向的数组通常在栈上创建）。因此，永远不要返回一个指向局部 initializer_list 内部元素的指针或引用，否则会导致悬空指针。

总结一句话： 遍历 initializer_list 时，最佳实践是写成 for (const auto &item : il)。这样既避免了拷贝（高效），又符合其常量语义（合法）。
*/
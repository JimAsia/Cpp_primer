// 5.4

// while (string::iterator iter != s.end()) { /* ... */ }
/*
代码含义
这段代码试图在 while 循环的条件部分声明一个迭代器 iter，并将其与字符串 s 的结束迭代器 s.end() 进行比较。如果 iter 不等于 s.end()，则执行循环体。
2. 存在的问题
在 C++ 中，while 循环的条件部分允许声明变量（例如 while (int x = f())），但这个变量的作用域仅限于 while 循环的条件判断中。
在本题中：
string::iterator iter 是在条件判断中声明的。
每次判断 iter != s.end() 时，iter 都会被重新声明和初始化。
循环体 { } 内部无法访问这个 iter，因为 iter 在条件判断结束后就销毁了。
更重要的是，这里没有对 iter 进行初始化（例如 iter = s.begin()），也没有在循环体内更新 iter（例如 ++iter）。这会导致：
如果 iter 未初始化，它的值是随机的，行为未定义。
即使初始化了，由于 iter 在每次条件判断时都是一个新的局部变量，循环体内对 iter 的任何修改都不会影响下一次条件判断。
因此，这个循环无法正确遍历字符串，逻辑上是错误的。通常我们使用迭代器遍历字符串时，需要在循环外部声明并初始化迭代器，然后在循环体内更新它。
*/

/*
string::iterator iter = s.begin(); // 在循环外声明并初始化
while (iter != s.end()) {
    // 循环体：处理 *iter
    ++iter; // 每次循环后迭代器自增，直到到达 s.end()
}
*/

// while (bool status = find(word)) { /* ... */ } if (!status) { /* ... */ }
/*
代码含义
while (bool status = find(word))：在每次循环条件判断时，声明一个布尔变量 status，并将其初始化为 find(word) 的返回值。如果 status 为 true（即 find 返回真），则执行循环体。
if (!status) {  }：在 while 循环结束后，判断 status 是否为 false。
2. 存在的问题
这里的关键问题在于变量 status 的作用域。
在 while 条件中声明的 status，其作用域仅限于 while 循环（包括循环体和条件本身）。
当 while 循环结束后，status 变量就已经销毁了。
因此，循环后的 if (!status) 中的 status 是一个未定义的变量（编译器会报错，提示 status 未声明）。
此外，如果 find(word) 在第一次调用时就返回 false，循环体一次也不会执行，但程序仍然需要知道 status 是 false 来执行 if 语句。由于作用域问题，我们无法在循环外访问最后一次条件判断时的 status 值。
3. 修改建议
我们需要将 status 的声明提升到 while 循环之外，使得它在循环结束后仍然可见。同时，while 条件中应使用赋值表达式将 find(word) 的结果赋给 status，而不是重新声明。
*/

/*
bool status; // 在循环外声明 status
while (status = find(word)) { // 使用赋值，而非声明
    
}
if (!status) { // 此时 status 仍然有效，保存了最后一次 find 的返回值
    
}
*/
/*
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
    case 'a': aCnt++;
    case 'e': eCnt++;
    default: iouCnt++;
}

这里的问题在于 switch 语句中的 case 分支缺少 break。
在 switch 中，如果一个 case 后面没有 break，程序会继续执行后续的所有代码（即“贯穿”/fall-through）。


修改：
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
    case 'a':
        aCnt++;
        break;
    case 'e':
        eCnt++;
        break;
    default:
        iouCnt++;
        break;
}

*/


/*
unsigned index = some_value();
switch (index) {
    case 1:
        int ix = get_value();
        ivec[ ix ] = index;
        break;
    default:
        ix = ivec.size() - 1;
        ivec[ ix ] = index;
}

变量 ix 在 case 1 中被声明为局部变量（int ix = ...），其作用域仅限于 case 1 所在的块（即整个 switch 体内，但在 default 中未初始化）。
在 default 分支中，直接使用 ix 会导致编译错误，因为 ix 在 default 中未被声明（它是在 case 1 中定义的局部变量，不能在 default 中直接访问，除非在 switch 开头定义）。此外，如果执行 default，ix 未定义，会导致未定义行为。

unsigned index = some_value();
int ix; // 在 switch 前声明
switch (index) {
    case 1:
        ix = get_value(); // 移除 int，因为已声明
        ivec[ ix ] = index;
        break;
    default:
        ix = ivec.size() - 1;
        ivec[ ix ] = index;
        break; // 建议加上 break
}
*/


/*
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
    case 1, 3, 5, 7, 9:
        oddcnt++;
        break;
    case 2, 4, 6, 8, 10:
        evencnt++;
        break;
}

switch 语句的 case 标签不能像这样用逗号分隔多个值。case 1, 3, 5, 7, 9: 实际上使用了逗号运算符，只会将最后一个值（9）作为标签，前面的 1, 3, 5, 7 会被忽略（作为表达式计算后丢弃）。
因此，只有当 digit 为 9 时，才会执行 oddcnt++，其他奇数不会匹配。同理，10 也不在 0-9 范围内（digit 是 % 10 的结果，范围是 0-9）。

unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
        oddcnt++;
        break;
    case 0: // 0 是偶数
    case 2:
    case 4:
    case 6:
    case 8:
        evencnt++;
        break;
}

*/


/*
unsigned ival = 512, jval = 1024, kval = 4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch (swt) {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kvar * sizeof(int);
        break;
}

switch 语句的 case 标签必须是常量表达式（在编译时已知值的常量）。这里的 ival、jval、kval 都是普通变量（即使它们被初始化了，也不是 const），因此不能作为 case 标签。编译器无法在编译时确定这些值，会导致编译错误。

const unsigned ival = 512, jval = 1024, kval = 4096; // 添加 const
unsigned bufsize;
unsigned swt = get_bufCnt();
switch (swt) {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int); // 原代码中 kvar 是拼写错误，应为 kval
        break;
}


*/


#include<iostream>

using namespace std;

int main()
{
    int ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch[3]; // cin >> 读取到字符数组（或 C 风格字符串）时，会自动在末尾添加一个结束符 \0，所以不是ch[2]
    while (cin >> ch) {
        switch(ch[0]) {
            case 'f':
                switch(ch[1]) {
                    case 'f':
                        ++ffCnt;
                        break;
                    case 'l':
                        ++flCnt;
                        break;
                    case 'i':
                        ++fiCnt;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    cout << "Number of vowel ff: \t" << ffCnt<< '\n'
     << "Number of vowel fl: \t" << flCnt << '\n'
     << "Number of vowel fi: \t" << fiCnt << '\n';
    return 0;
}
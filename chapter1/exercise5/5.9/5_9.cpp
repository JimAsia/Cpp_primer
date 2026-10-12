#include<iostream>

using namespace std;

int main()
{
    // 为每个元音字母初始化其计数值
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (cin >> ch) {
        // 如果 ch 是元音字母，将其对应的计数值加 1
        if (ch == 'a') 
            ++aCnt;
        else if (ch == 'e')
                ++eCnt;
        else if (ch == 'i')
                ++iCnt;
        else if (ch == 'o')
            ++oCnt;
        else if (ch == 'u')
            ++uCnt;
    }
    cout << "Number of vowel a: \t" << aCnt << '\n'
     << "Number of vowel e: \t" << eCnt << '\n'
     << "Number of vowel i: \t" << iCnt << '\n'
     << "Number of vowel o: \t" << oCnt << '\n'
     << "Number of vowel u: \t" << uCnt << endl;
}
#include<iostream>
#include<string>
#include<vector>

using namespace std;


int main()
{
    string str;
    vector<string> v;
    vector<string> v1;
    vector<int> cnt;
    int count = 1;
    int maxCnt = 0;
    int maxTemp = 0;
    while (cin >> str)
        v.push_back(str);
    if (v.empty()) {
        cout << "没有输入任何单词" << endl;
        return 0;
    }
    for (auto i = v.begin(); i != v.end()-1; ++i) {
        if (*i == *(i+1))
            ++count;
        else {  
            cnt.push_back(count);
            v1.push_back(*i);
            count = 1;
        }

    }
    // for 如果输入的最后一个单词和它前面的单词是相同的（例如输入：hello hello hello），循环结束后，count 的值是 3，但因为后面没有“不同的单词”来触发 else，这个 3 永远没有被存入 cnt。
    // 在 for 循环结束后，手动把最后一次的统计结果存进去：
    cnt.push_back(count);
    v1.push_back(*(v.end() - 1));
    for (auto i : v1) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : cnt) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < cnt.size(); ++i) {
        if (maxCnt < cnt[i]) {
            maxCnt = cnt[i];
            maxTemp = i;
        }
    }
    if (maxCnt != 1)
        cout << "单词" << v1[maxTemp] << "连续出现了" << maxCnt << "次" << endl;
    else
        cout << "任何单词都没有连续出现过" << endl;
    return 0;
}
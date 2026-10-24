#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::vector;


using std::string;


int main() {
	string str("aceimnorsuvwxz");
	ifstream words("word.txt");
	string word;
	vector<string> all;
	if (!words.is_open()) {
        std::cerr << "无法打开文件！请检查文件是否存在。" << std::endl;
        return 1;
    }
	while (words >> word) {
		string::size_type pos = 0;
		string newWord;
		while ((pos = word.find_first_of(str, pos)) != string::npos) {
			newWord += word[pos];
			++pos;
		}
		if (!newWord.empty()) {
			all.push_back(newWord);
		}
	}
	string::size_type max = 0;
	string::size_type index = 0, maxIndex = 0;
	for (const auto &i: all) {
		if (i.size() > max) {
			max = i.size();
			maxIndex = index;
		}
		++index;
	}
	cout << "First max word: " << all[maxIndex] << endl;
	
	return 0;
}

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

void replace_string(string &s, const string &oldVal, const string &newVal)
{
	if(oldVal.empty()) {
		return;
	}
	string::iterator it = s.begin();
	while (it != s.end()) {
		if (string(it, it + oldVal.size()) == oldVal) {
			it = s.erase(it, it + oldVal.size());
			it = s.insert(it, newVal.begin(), newVal.end());
			it += newVal.size();
		}
		else {
			++it;
		}
	}
}

int main() {
    std::string s = "I think tho thru are through the way, tho it is hard.";
    std::cout << "Original: " << s << std::endl;
    
    replace_string(s, "tho", "though");
    replace_string(s, "thru", "through");
    
    std::cout << "Modified: " << s << std::endl;
    
    return 0;
}
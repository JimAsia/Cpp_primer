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
	std::size_t it = 0;
	while (it < s.length()) {
		if (s.compare(it, oldVal.size(), oldVal) == 0) {
			s.replace(it, oldVal.size(), newVal);
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
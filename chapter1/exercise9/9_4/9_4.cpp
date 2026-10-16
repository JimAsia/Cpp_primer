#include <vector>
#include<iostream>

using std::cin;
using std::cout;
using std::vector;

bool findNum(vector<int>::iterator first, vector<int>::iterator last, int value)
{
	while (first != last) {
		if (*first == value)
			return true;
		else
			++first;
	}
	return false;
}

int main()
{
	vector<int> num = {1, 2, 3, 4, 5, 6};
	cout << "Enter a number to find: ";
	int i;
	cin >> i;
	if (findNum(num.begin(), num.end(), i))
		cout << "Find it.\n";
	else
		cout << "Not find.\n";
	return 0; 
}

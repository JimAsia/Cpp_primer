#include <vector>
#include<iostream>

using std::cin;
using std::cout;
using std::vector;

vector<int>::iterator findNum(vector<int>::iterator first, vector<int>::iterator last, int value)
{
	while (first != last) {
		if (*first == value)
			return first;
		else
			++first;
	}
	return last;
}

int main()
{
	vector<int> num = {1, 2, 3, 4, 5, 6};
	cout << "Enter a number to find: ";
	int i;
	cin >> i;
	vector<int>::iterator it = findNum(num.begin(), num.end(), i);
	if (it != num.end())
		cout << "Find it.\n";
	else
		cout << "Not find.\n";
	return 0; 
}

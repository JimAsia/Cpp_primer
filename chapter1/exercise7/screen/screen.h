#ifndef SCREEN_H_
#define SCREEN_H_

#include <iostream>
#include <string>
using std::string;

class Screen
{
public:
	using pos = string::size_type;
	Screen() = default;
	Screen(pos wid, pos high) : width(wid), height(high) {}
	Screen(pos wid, pos high, char c) : width(wid), height(high), contents(wid * high, c) {}
	Screen &move(pos row, pos col);
	Screen &set(char c);
	void display(std::ostream &os) const;
	private:
	pos cursor = 0;
	pos width = 0, height = 0;
	string contents;


};



#endif
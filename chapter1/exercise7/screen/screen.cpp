#include "screen.h"

Screen &Screen::move(pos row, pos col)
	{
		width = row * width;
		cursor = width + col;
		return *this;
	}

Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}


void Screen::display(std::ostream &os) const
{
	os << contents;
}
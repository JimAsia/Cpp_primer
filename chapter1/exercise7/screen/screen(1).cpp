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



void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)   // 要写两个作用域ScreenIndex，addScreen都在类 Window_mgr中
{
	screens.push_back(s);
	return screens.size() - 1;  // 刚刚被添加进 screens 的那个 Screen 对象的下标（索引）
}
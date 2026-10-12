#ifndef SCREEN_H_
#define SCREEN_H_

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Screen;    // 前向声明，供 Window_mgr 使用

class Window_mgr
{
public:
	using ScreenIndex = vector<Screen>::size_type;
	Window_mgr() = default;
	void clear(ScreenIndex);  // 只声明，不定义
private:
	vector<Screen> screens;  // 成员声明：C++17 起允许不完整类型
};


class Screen
{ 

	friend void Window_mgr::clear(ScreenIndex);
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
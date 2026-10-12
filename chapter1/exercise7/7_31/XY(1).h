#ifndef XY_H_
#define XY_H_

class X;  // 前向声明

class Y
{
public:
	X object;
};

class X
{
public:
	Y *point;
};


#endif
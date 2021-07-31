#pragma once
#include "Point.h"
class Rectangle
{
private:
	Point m_upLeft;
	Point m_lowRight;
public:
	Rectangle();
	Rectangle(const int& x1, const int& y1, const int& x2, const int& y2);
	~Rectangle();
	void drawRectangle();
};


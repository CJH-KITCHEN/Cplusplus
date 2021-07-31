#pragma once
class Point
{
private:
	int m_x;
	int m_y;

public:
	Point();
	Point(const int& x, const int& y);
	~Point();
	void setX(const int& x);
	void setY(const int& y);
	int getX();
	int getY();
	void drawPoint();
};


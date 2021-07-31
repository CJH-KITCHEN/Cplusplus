#include "Point.h"
#include <iostream>
using namespace std;

Point::Point():Point(0,0){
	//cout << "디폴트 생성자" << endl;
}

Point::Point(const int& x, const int& y)
	:m_x(x),m_y(y){
	cout << m_x << "," << m_y << " : 인자있는 생성자" << endl;
}

Point::~Point()
{
	cout << m_x << "," << m_y << " : 소멸자" << endl;
}

void Point::setX(const int& x)
{
	m_x = x;
}

void Point::setY(const int& y)
{
	m_y = y;
}

int Point::getX()
{
	return m_x;
}

int Point::getY()
{
	return m_y;
}

void Point::drawPoint()
{
	cout << m_x << "," << m_y << endl;
}

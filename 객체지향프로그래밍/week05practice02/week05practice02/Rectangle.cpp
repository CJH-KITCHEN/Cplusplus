#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle():Rectangle(0,0,0,0)
{
	//cout << "Rectangle 디폴트 생성자" << endl;
}

Rectangle::Rectangle(const int& x1, const int& y1, const int& x2, const int& y2):m_upLeft(x1,y1) , m_lowRight(x2,y2)
{
	cout << "Rectangle 인자 있는 생성자" << endl;
}

Rectangle::~Rectangle()
{
	cout << "Rectangle 소멸자" << endl;
}

void Rectangle::drawRectangle()
{
	m_upLeft.drawPoint();
	m_lowRight.drawPoint();
}

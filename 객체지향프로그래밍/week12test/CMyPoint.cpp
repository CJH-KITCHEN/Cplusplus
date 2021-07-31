#include "CMyPoint.h"

CMyPoint::CMyPoint():x(0), y(0)
{
	cout << x << "," << y << " 디폴트 생성자" << endl;
}

CMyPoint::~CMyPoint()
{
	cout << x << "," << y <<" 소멸자" << endl;

}

CMyPoint::CMyPoint(const int x, const int y):x(x), y(y)
{
	cout << x << "," << y << "생성자" << endl;

}

CMyPoint::CMyPoint(const CMyPoint& pt):x(pt.x), y(pt.y)
{
	cout << x << "," << y << "복사 생성자" << endl;
}

CMyPoint::CMyPoint(CMyPoint&& pt) noexcept :x(pt.x), y(pt.y)
{
	cout << x << "," << y << "이동 생성자" << endl;

}

bool CMyPoint::operator<(const CMyPoint& pt)
{	
	return x<pt.x;
}

bool CMyPoint::operator>(const CMyPoint& pt)
{
	return x>pt.x;
}

bool CMyPoint::operator==(const CMyPoint& pt)
{	
	return x==pt.x&& y==pt.y;
}

ostream& operator<<(ostream& out, CMyPoint& pt) {
	out << pt.x << "," << pt.y << endl;
	return out;
}
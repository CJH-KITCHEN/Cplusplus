#include "CMyPoint.h"

CMyPoint::CMyPoint(const int x, const int y):x(x), y(y)
{
}

bool CMyPoint::operator<(const CMyPoint& pt)
{	
	return x<pt.x;
}

bool CMyPoint::operator>(const CMyPoint& pt)
{
	return x>pt.x;
}

ostream& operator<<(ostream& out, CMyPoint& pt) {
	out << pt.x << "," << pt.y << endl;
	return out;
}
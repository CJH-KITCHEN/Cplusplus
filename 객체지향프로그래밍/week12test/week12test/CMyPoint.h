#pragma once
#include <iostream>
using namespace std;

class CMyPoint
{
private:
	int x;
	int y;
public:
	CMyPoint();
	~CMyPoint();
	/*CMyPoint() = default;
	~CMyPoint() = default;*/
	CMyPoint(const int x, const int y);
	CMyPoint(const CMyPoint& pt);
	CMyPoint(CMyPoint&& pt) noexcept;
	friend ostream& operator<<(ostream& out, CMyPoint& pt);
	bool operator<(const CMyPoint& pt);
	bool operator>(const CMyPoint& pt);
	bool operator==(const CMyPoint& pt);

};


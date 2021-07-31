#pragma once
#include <iostream>
using namespace std;

class CMyPoint
{
private:
	int x;
	int y;
public:
	CMyPoint() = default;
	~CMyPoint() = default;
	CMyPoint(const int x, const int y);
	friend ostream& operator<<(ostream& out, CMyPoint& pt);
	bool operator<(const CMyPoint& pt);
	bool operator>(const CMyPoint& pt);

};


#pragma once
#include<string>
#include"CJHClient.h"
using namespace std;
class CJHItem
{
private:
	CJHClient** client;
	string itemname;
	int itemnum;
	int check = 0;
	int sum = 0;
public:
	CJHItem() = delete;
	CJHItem(string name, int num);
	CJHItem(const CJHItem& cjhitem);
	CJHItem(CJHItem&& cjhitem)noexcept;
	~CJHItem();
	void join(CJHClient* c);
	void printdata()const;
	friend ostream& operator<< (ostream& out, const CJHItem& item);

};


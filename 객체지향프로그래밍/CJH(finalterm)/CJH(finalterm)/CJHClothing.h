#pragma once
#include "CJHProduct.h"
class CJHClothing :
	public CJHProduct
{
private:
	string gender;
	string clothname;
	string clothsize;
public:
	CJHClothing() = delete;
	CJHClothing(string code, string ptype, int num, int price, string gender, string clothname, string clothsize);
	~CJHClothing();
	void join(string name);
	void show();
	string getcode();
	//friend ostream& operator<< (ostream& out, CJHClothing cloth);

};


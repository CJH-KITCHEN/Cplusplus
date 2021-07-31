#pragma once
#include "CJHProduct.h"
class CJHTV :
	public CJHProduct
{
private:
	string brand;
	string model;
	int screensize;
public:
	CJHTV()=delete;
	~CJHTV();
	CJHTV(string code, string ptype, int num, int price, string brand, string model, int screensize);
	void join(string name);
	void show();
	string getcode();

	//friend ostream& operator<< (ostream& out, CJHTV tv);
};


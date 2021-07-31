#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class CJHProduct
{
protected:
	string code;
	string ptype;
	int num;
	int price;
	vector<string> customer;

public:
	CJHProduct();
	CJHProduct(string code, string ptype, int num, int price);
	virtual ~CJHProduct();
	virtual void join(string name) = 0;
	virtual void show();
	friend ostream& operator<< (ostream& out, CJHProduct& product);
	virtual string getcode();
	int getPrice();
	string getptype();
	};


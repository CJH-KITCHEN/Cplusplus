#pragma once
#include <string>
#include <iostream>
using namespace std;

class Item
{
private:
	string code;
	string itemname;
	int itemcount;
	int price;
	int soldprice=0;
	string soldmart = "";


public:
	Item();
	Item(string code, string itemname, int itemcount, int price);
	Item(Item& item);
	void print();
	void print(bool p);
	string returnname();
	string returcode();
	bool remainitem();
	void sellitem(string mart);
};


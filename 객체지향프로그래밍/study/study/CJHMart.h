#pragma once
#include "Item.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class CJHMart
{
private:
	string pwd;
	int itemnum;
	Item** item;
	int	pricesum = 0;
	string filename;
public:
	CJHMart() = delete;
	CJHMart(string filename);
	CJHMart(string filename, string pwd);
	CJHMart(CJHMart& cjhmart);
	CJHMart(CJHMart&& cjhmart)noexcept;
	~CJHMart();
	void showItems();
	void showItems(string pwd);
	string findItems(string name);
	bool sellItem(string code, string mart);
};


#pragma once
#include "Item.h"
class CannedDrinks :
	public Item
{
private:
	string brand;

public:
	CannedDrinks();
	~CannedDrinks();
	CannedDrinks(string name, double price, string brand);
	void show();
};


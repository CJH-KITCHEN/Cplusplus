#pragma once
#include "Item.h"
class Coffee :
	public Item
{
private:
	int coffeesize;
	int creamsize;
	int sugarsize;
	bool ice;
	
public:
	Coffee();
	Coffee(string name, double price, int coffeesize, int creamsize, int sugarsize, bool ice);
	~Coffee();
	void show();
};


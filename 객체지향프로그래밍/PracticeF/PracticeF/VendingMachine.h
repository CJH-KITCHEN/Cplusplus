#pragma once
#include <string>
#include <iostream>
#include "Item.h"

using namespace std;

class VendingMachine
{
private:
	string code;
	int capacity;
	Item** arr;
	int count = 0;
public:
	VendingMachine();
	VendingMachine(string code, int capacity);
	~VendingMachine();
	void addItem(Item* item);
	VendingMachine(VendingMachine& machine);
	int getCount();
	void show();
};


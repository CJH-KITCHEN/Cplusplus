#pragma once
#include <string>
#include <iostream>

using namespace std;

class Item
{
protected:
	string name;
	double price;
	
public:
	Item();
	Item(string name, double price);
	Item(Item& item);
	virtual ~Item();
	virtual void show() = 0;
};


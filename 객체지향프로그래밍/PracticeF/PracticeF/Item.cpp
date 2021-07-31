#include "Item.h"

Item::Item():Item("null", 0.0)
{
}

Item::Item(string name, double price)
{
	this->name = name;
	this->price = price;

}

Item::Item(Item& item)
{
	this->name = item.name;
	this->price = item.price;
}

Item::~Item()
{
}

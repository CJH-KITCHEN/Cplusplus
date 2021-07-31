#include "Item.h"

Item::Item():Item("noinfo","noinfo",0,0)
{
}

Item::Item(string code, string itemname, int itemcount, int price)
{
	this->code = code;
	this->itemname = itemname;
	this->itemcount = itemcount;
	this->price = price;
}

Item::Item(Item& item)
	:code(item.code), itemname(item.itemname), itemcount(item.itemcount), price(item.price), soldprice(item.soldprice), soldmart(item.soldmart)
{

}

void Item::print()
{
	cout <<code<<'\t'<< itemname<< '\t'<< itemcount << '\t' << price<<" "<< endl;
}

void Item::print(bool p)
{
	if (p) {
		cout << code << '\t' << itemname << '\t' << itemcount << '\t' << price << '\t' << soldprice;
		cout << '\t' << '\t' << soldmart << endl;
	}
	else {
		print();
	}
}

string Item::returnname()
{
	return this->itemname;
}

string Item::returcode()
{	
	return this->code;
}

bool Item::remainitem()
{
	if (itemcount > 0) {
		return true;
}	
	else {
		return false;
	}
}

void Item::sellitem(string mart)
{	
	this->soldmart += (" " + mart);
	itemcount--;
	soldprice += price;
}


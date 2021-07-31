#include "CannedDrinks.h"

CannedDrinks::CannedDrinks():CannedDrinks("null", 0, "null")
{
}

CannedDrinks::~CannedDrinks()
{
}

CannedDrinks::CannedDrinks(string name, double price, string brand):
	Item(name, price)
{
	this->brand = brand;

}

void CannedDrinks::show()
{
	cout << "품목 : " << this->name << endl;
	cout << "가격 : " << this->price << endl;
	cout << "제조업체 : " << this->brand << endl;
	
}

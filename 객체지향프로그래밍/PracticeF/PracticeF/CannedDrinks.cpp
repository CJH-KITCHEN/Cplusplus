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
	cout << "ǰ�� : " << this->name << endl;
	cout << "���� : " << this->price << endl;
	cout << "������ü : " << this->brand << endl;
	
}

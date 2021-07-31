#include "Coffee.h"

Coffee::Coffee():Coffee("null", 0, 0, 0 ,0, false)
{
}

Coffee::Coffee(string name, double price, int coffeesize, int creamsize, int sugarsize, bool ice)
	:Item(name,price)
{
	this->coffeesize = coffeesize;
	this->creamsize = creamsize;
	this->sugarsize = sugarsize;
	this->ice = ice;
}

Coffee::~Coffee()
{
}

void Coffee::show()
{
	cout << "ǰ�� : " << this->name << endl;
	cout << "���� : " << this->price << endl;
	cout << "Ŀ�� : " << this->coffeesize << endl;
	cout << "ũ�� : " << this->creamsize << endl;
	cout << "���� : " << this->sugarsize << endl;
	if (this->ice) {
		cout << "�ÿ� : ������" << endl;

	}
	else {
		cout << "�ÿ� : ������" << endl;
	}
}

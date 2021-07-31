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
	cout << "Ç°¸ñ : " << this->name << endl;
	cout << "°¡°Ý : " << this->price << endl;
	cout << "Ä¿ÇÇ : " << this->coffeesize << endl;
	cout << "Å©¸² : " << this->creamsize << endl;
	cout << "¼³ÅÁ : " << this->sugarsize << endl;
	if (this->ice) {
		cout << "³Ã¿Â : ³ÃÀ½·á" << endl;

	}
	else {
		cout << "³Ã¿Â : ¿ÂÀ½·á" << endl;
	}
}

#include <iostream>
#include "Coffee.h"
#include "CannedDrinks.h"
#include "VendingMachine.h"
#include "VendingManager.h"
using namespace std;
ostream& operator<< (ostream& out, vector<VendingMachine*> mv) {
	for (auto i : mv) {
		i->show();
	}
	return out;
}

namespace CJH{
	void printName() {
		cout << "201711430 ÄÄÇ»ÅÍ°øÇÐºÎ Â÷ÁØÇõ" << endl << endl;
	}
}

int main() {
	CJH::printName();
	Item* item1 = new Coffee("¸Æ½ºÀ£", 500, 400, 400, 800, false);
	Item* item2 = new CannedDrinks("»çÀÌ´Ù", 1000, "·Ôµ¥");
	
	VendingMachine vending("s100", 3);
	vending.addItem(new Coffee("¸Æ½ºÀ£", 500, 400, 400, 800, false));
	vending.addItem(new CannedDrinks("»çÀÌ´Ù", 1000, "·Ôµ¥"));

	VendingMachine copyVending;
	copyVending = vending;

	VendingManager vmanager;
	vmanager.addMachine(new VendingMachine("s200", 4));
	vmanager.addMachine(new VendingMachine("s100", 5));
	vmanager.addMachine(new VendingMachine("s300", 6));

	vmanager[0]->addItem(new Coffee("¸Æ½ºÀ£", 500, 400, 400, 800, false));
	vmanager[0]->addItem(new Coffee("¸Æ½É", 500, 400, 400, 800, true));

	vmanager[1]->addItem(new Coffee("¸Æ½ºÀ£", 500, 400, 400, 800, false));
	vmanager[1]->addItem(new CannedDrinks("»çÀÌ´Ù",1000,"·Ôµ¥"));
	vmanager[1]->addItem(new CannedDrinks("»çÀÌ´Ù", 1000, "·Ôµ¥"));
	vmanager[1]->addItem(new Coffee("¸Æ½É", 500, 400, 400, 800, true));
	vmanager[1]->addItem(new CannedDrinks("Æé½Ã", 700, "·Ôµ¥"));

	vmanager[2]->addItem(new CannedDrinks("»çÀÌ´Ù", 1000, "·Ôµ¥"));
	vmanager[2]->addItem(new Coffee("¸Æ½É", 500, 400, 400, 800, true));
	vmanager[2]->addItem(new Coffee("¸Æ½É", 500, 500, 500, 800, true));

	vector<VendingMachine*> arr = vmanager.getMachine();
	sort(arr.begin(), arr.end(), [](VendingMachine* left, VendingMachine* right) {
		return left->getCount() < right->getCount();
		});
	cout << arr << endl;


}
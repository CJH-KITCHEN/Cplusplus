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
		cout << "201711430 ��ǻ�Ͱ��к� ������" << endl << endl;
	}
}

int main() {
	CJH::printName();
	Item* item1 = new Coffee("�ƽ���", 500, 400, 400, 800, false);
	Item* item2 = new CannedDrinks("���̴�", 1000, "�Ե�");
	
	VendingMachine vending("s100", 3);
	vending.addItem(new Coffee("�ƽ���", 500, 400, 400, 800, false));
	vending.addItem(new CannedDrinks("���̴�", 1000, "�Ե�"));

	VendingMachine copyVending;
	copyVending = vending;

	VendingManager vmanager;
	vmanager.addMachine(new VendingMachine("s200", 4));
	vmanager.addMachine(new VendingMachine("s100", 5));
	vmanager.addMachine(new VendingMachine("s300", 6));

	vmanager[0]->addItem(new Coffee("�ƽ���", 500, 400, 400, 800, false));
	vmanager[0]->addItem(new Coffee("�ƽ�", 500, 400, 400, 800, true));

	vmanager[1]->addItem(new Coffee("�ƽ���", 500, 400, 400, 800, false));
	vmanager[1]->addItem(new CannedDrinks("���̴�",1000,"�Ե�"));
	vmanager[1]->addItem(new CannedDrinks("���̴�", 1000, "�Ե�"));
	vmanager[1]->addItem(new Coffee("�ƽ�", 500, 400, 400, 800, true));
	vmanager[1]->addItem(new CannedDrinks("���", 700, "�Ե�"));

	vmanager[2]->addItem(new CannedDrinks("���̴�", 1000, "�Ե�"));
	vmanager[2]->addItem(new Coffee("�ƽ�", 500, 400, 400, 800, true));
	vmanager[2]->addItem(new Coffee("�ƽ�", 500, 500, 500, 800, true));

	vector<VendingMachine*> arr = vmanager.getMachine();
	sort(arr.begin(), arr.end(), [](VendingMachine* left, VendingMachine* right) {
		return left->getCount() < right->getCount();
		});
	cout << arr << endl;


}
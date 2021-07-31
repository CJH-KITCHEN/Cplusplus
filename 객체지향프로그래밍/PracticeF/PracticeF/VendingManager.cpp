#include "VendingManager.h"

VendingManager::VendingManager()
{
}

VendingManager::~VendingManager()
{
	for (int i = 0; i < count; i++) {
		delete marr[i];
	}
}

void VendingManager::addMachine(VendingMachine* machine)
{
	marr.push_back(machine);
	count++;
}

VendingMachine*& VendingManager::operator[](int num)
{
	// TODO: 여기에 return 문을 삽입합니다.
	if (count >= 0) {
		return marr[num];
	}
	else {
		cout << "배열 참조 오류" << endl;
		exit(0);
	}

}

vector<VendingMachine*> VendingManager::getMachine()
{	
	return this->marr;
}

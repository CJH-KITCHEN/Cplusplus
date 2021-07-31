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
	// TODO: ���⿡ return ���� �����մϴ�.
	if (count >= 0) {
		return marr[num];
	}
	else {
		cout << "�迭 ���� ����" << endl;
		exit(0);
	}

}

vector<VendingMachine*> VendingManager::getMachine()
{	
	return this->marr;
}

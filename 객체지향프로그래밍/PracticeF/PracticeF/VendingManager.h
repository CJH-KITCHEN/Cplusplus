#pragma once
#include "Item.h"
#include "VendingMachine.h"
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class VendingManager
{
private:
	vector<VendingMachine*> marr;
	int count = 0;

public:
	VendingManager();
	~VendingManager();
	void addMachine(VendingMachine* machine);
	VendingMachine*& operator[](int num);
	vector<VendingMachine*> getMachine();
};


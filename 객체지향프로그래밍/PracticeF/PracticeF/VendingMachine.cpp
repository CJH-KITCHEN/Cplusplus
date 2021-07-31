#include "VendingMachine.h"

VendingMachine::VendingMachine():VendingMachine("null",0)
{
}

VendingMachine::VendingMachine(string code, int capacity)
{
	this->code = code;
	this->capacity = capacity;
	arr = new Item * [capacity];
}

VendingMachine::~VendingMachine()
{
	if (arr != nullptr) {
		for (int i = 0; i < count; i++) {
			delete arr[i];
		}
		delete[] arr;
		arr = nullptr;
	}
}

void VendingMachine::addItem(Item* item)
{
	if (count <= capacity) {
		arr[count++] = item;
	}
	else {
		cout << "더 이상 저장할 수 없습니다" << endl;
	}
}

VendingMachine::VendingMachine(VendingMachine& machine)
{	
	if (arr != nullptr) {
		for (int i = 0; i < count; i++) {
			delete arr[i];
		}
		delete[] arr;
		arr = nullptr;
	}
	code = machine.code;
	capacity = machine.capacity;
	count = machine.count;
	arr = new Item * [machine.capacity];
	for (int i = 0; i < machine.count; i++) {
		*(arr + i) = *(machine.arr + i);
	}

}

int VendingMachine::getCount()
{
	return this->count;
}

void VendingMachine::show()
{
	cout << "=================================" << endl;
	for (int i = 0; i < this->count; i++) {
		this->arr[i]->show();
	}
	cout << "================================" << endl;

}


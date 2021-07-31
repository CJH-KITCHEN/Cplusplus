#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(const string& name, const int& number)
	:m_name(name), m_number(number)
{
	if (m_number > 0)
		items = new Product * [m_number];
	else
		items = nullptr;
}

Customer::~Customer()
{
	if (items != nullptr) {
		for (size_t i = 0; i < m_count; i++) {
			delete items[i];
		}
		delete[] items;
	}
}

void Customer::buy(Product* item)
{
	if (m_count < m_number) {
		items[m_count++] = item;
	}
}

string Customer::getName() const
{
	return m_name;
}

int Customer::getCount() const
{
	return m_count;
}

void Customer::showlist() const
{
	cout << "고객이름 : " << m_name << endl;
	cout << "구매개수 : " << m_count << endl;
	int price = 0;

	for (size_t i = 0; i < m_count; i++) {
		items[i]->show();
		price += items[i]->getPrice();
	}
	cout << "총 구매 금액 : " << price << endl;
}

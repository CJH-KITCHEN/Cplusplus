#include "Customer2.h"
#include "TV.h"
#include "Vegetable.h"
#include <iostream>
using namespace std;

Customer2::Customer2(const string& name, const int& number)
	:m_name(name), m_number(number), items(make_unique<unique_ptr<Product>[]>(m_number))
{
	/*if (m_number > 0)
		items = new Product * [m_number];
	else
		items = nullptr;*/
}

Customer2::~Customer2()
{
	/*if (items != nullptr) {
		for (size_t i = 0; i < m_count; i++) {
			delete items[i];
		}
		delete[] items;
	}*/
}

void Customer2::buy(unique_ptr<Product> item)
{
	if (m_count < m_number) {
		items[m_count++] = move(item);
	}
}

string Customer2::getName() const
{
	return m_name;
}

int Customer2::getCount() const
{
	return m_count;
}

void Customer2::showlist() const
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

void Customer2::showTVlist() const
{
	
	for (size_t i = 0; i < m_count; i++) {
		TV* tv = dynamic_cast<TV*>(items[i].get());
		if(tv!=nullptr)
			items[i]->show();
	}
}

void Customer2::showVegetablelist() const
{
	for (size_t i = 0; i < m_count; i++) {
		Vegetable* vegetable = dynamic_cast<Vegetable*>(items[i].get());
		if (vegetable != nullptr)
			items[i]->show();
	}
}

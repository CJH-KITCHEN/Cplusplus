#pragma once
#include <string>
#include "Product.h"
using std::string;

class Customer
{
private:
	string m_name;
	int m_number = 0;
	int m_count = 0;
	Product** items;
public:
	Customer(const string& name, const int& number);
	~Customer();
	void buy(Product* item);
	string getName() const;
	int getCount() const;
	void showlist() const;
};


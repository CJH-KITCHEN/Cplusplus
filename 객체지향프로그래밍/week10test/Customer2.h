#pragma once
#include <string>
#include "Product.h"
#include <memory>
using std::string;
using std::unique_ptr;

class Customer2
{
private:
	string m_name;
	int m_number = 0;
	int m_count = 0;
	unique_ptr<unique_ptr<Product>[]> items;
	//Product** items;

public:
	Customer2(const string& name, const int& number);
	~Customer2();
	//void buy(Product* item);
	void buy(unique_ptr<Product> item);
	string getName() const;
	int getCount() const;
	void showlist() const;
	void showTVlist() const;
	void showVegetablelist() const;

};


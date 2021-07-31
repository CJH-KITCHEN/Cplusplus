#include "Product.h"
#include <iostream>
using namespace std;

Product::Product(const string& name, const int& price)
	:m_name(name), m_price(price)
{
}

Product::~Product()
{

}

int Product::getPrice() const
{
	
	return m_price;
}

string Product::getName() const
{
	return m_name;
}

void Product::show() const
{
	cout << "-----------------------------" << endl;
	cout << "力 前 疙 : " << m_name << endl;
	cout << "力前啊拜 : " << m_price << endl;

}

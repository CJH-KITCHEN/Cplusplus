#pragma once
#include "Product.h"
class Vegetable :
	public Product
{
private:
	string m_origin;
	int m_weight;
public:
	Vegetable(const string& name, const int& price, const string& origin, const int& weight);
	~Vegetable();
	int getPrice() const;
	void show() const;
};


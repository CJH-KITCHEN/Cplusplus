#pragma once
#include "Product.h"
class TV :
	public Product
{
private:
	int m_size;
public:
	TV(const string& name, const int& price, const int& size);
	~TV();
	int getPrice() const;
	void show() const;
};


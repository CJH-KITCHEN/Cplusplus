#include "TV.h"
#include <iostream>
using namespace std;

TV::TV(const string& name, const int& price, const int& size)
	:Product(name, price), m_size(size)
{

}

TV::~TV()
{
}

int TV::getPrice() const
{
	return static_cast<int>(m_price -m_price*0.1);
}

void TV::show() const
{
	//__super::show();
	Product::show();
	cout << "화면크기 : " << m_size << endl;
	cout << "판매가격 : " << getPrice() << endl;
	cout << "-----------------------------" << endl;
}

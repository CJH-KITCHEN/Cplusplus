#include "CJHProduct.h"

CJHProduct::CJHProduct():CJHProduct("null","null",0,0)
{
}

CJHProduct::CJHProduct(string code, string ptype, int num, int price)
{
	this->code = code;
	this->ptype = ptype;
	this->num = num;
	this->price = price;
}

CJHProduct::~CJHProduct()
{
	
}

void CJHProduct::show()
{
	cout << "-------------------------" << endl;
	cout << "��Ϲ�ȣ : " << this->code << endl;
	cout << "��ǰ���� : " << this->ptype << endl;
	cout << "��ǰ���� : " << this->num << endl;
	cout << "���� : " << this->price << endl;
	cout << "-------------------------" << endl;

}

string CJHProduct::getcode()
{
	return this->code;
}

int CJHProduct::getPrice()
{
	return this->price;
}

string CJHProduct::getptype()
{
	return this->ptype;
}

ostream& operator<< (ostream& out, CJHProduct& product) {
	product.show();
	return out;
}

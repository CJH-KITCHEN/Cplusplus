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
	cout << "등록번호 : " << this->code << endl;
	cout << "제품유형 : " << this->ptype << endl;
	cout << "제품개수 : " << this->num << endl;
	cout << "가격 : " << this->price << endl;
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

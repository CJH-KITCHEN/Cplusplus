#include "CJHTV.h"

CJHTV::~CJHTV()
{
}

CJHTV::CJHTV(string code, string ptype, int num, int price, string brand, string model, int screensize)
	:CJHProduct(code,ptype,num,price)
{
	this->brand = brand;
	this->model = model;
	this->screensize = screensize;
}

void CJHTV::join(string name)
{
	this->customer.push_back(name);
}

void CJHTV::show()
{
	CJHProduct::show();
	cout << "����ȸ�� : " << this->brand << endl;
	cout << "��ǰ�� : " << this->model << endl;
	cout << "ȭ��ũ�� : " << this->screensize << endl;
	cout << "-------------------------" << endl;
	cout << "���� ������" << endl;
	cout << "-------------------------" << endl;
	vector<string>::iterator it = customer.begin();
	if (it != customer.end()) {
		for (auto i : customer) {
			cout << i << endl;
		}

	}

}

string CJHTV::getcode()
{
	return this->code;
}

//ostream& operator<< (ostream& out, CJHTV tv) {
//	tv.show();
//	return out;
//}
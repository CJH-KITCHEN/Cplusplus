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
	cout << "제조회사 : " << this->brand << endl;
	cout << "제품모델 : " << this->model << endl;
	cout << "화면크기 : " << this->screensize << endl;
	cout << "-------------------------" << endl;
	cout << "구매 참여자" << endl;
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
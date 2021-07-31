#include "CJHClothing.h"

CJHClothing::CJHClothing(string code, string ptype, int num, int price, string gender, string clothname, string clothsize)
	:CJHProduct(code,ptype,num,price)
{
	this->gender = gender;
	this->clothname = clothname;
	this->clothsize = clothsize;
}

CJHClothing::~CJHClothing()
{
}

void CJHClothing::join(string name)
{
	this->customer.push_back(name);
}

void CJHClothing::show()
{
	CJHProduct::show();
	cout << "성별유형 : " << this->gender << endl;
	cout << "옷 이름 : " << this->clothname << endl;
	cout << "옷 사이즈 : " << this->clothsize << endl;
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

string CJHClothing::getcode()
{
	return this->code;
}


//ostream& operator<< (ostream& out, CJHClothing cloth) {
//	cloth.show();
//	return out;
//}
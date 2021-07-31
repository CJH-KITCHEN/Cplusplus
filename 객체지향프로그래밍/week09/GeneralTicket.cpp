#include "GeneralTicket.h"
#include "iostream"
using namespace std;

GeneralTicket::GeneralTicket():GeneralTicket(0.0,"False")
{
}

GeneralTicket::GeneralTicket(double price, bool b):Ticket(price)
{
	this->payByCredit = b;
}

GeneralTicket::~GeneralTicket()
{
	order--;
	//cout << "GeneralTicket 소멸자 생성" << endl;
}

double GeneralTicket::getPrice() const
{
	return this->price;
}

bool GeneralTicket::getPayByCredit() const
{
	return this->payByCredit;
}

void GeneralTicket::show() const
{
	cout << "티켓번호 : " << this->number << endl;
	cout << "가격정보 : " << this->price << endl;
	if (this->payByCredit) {
		cout << "카드 결제 여부 : true" << endl;
		cout << "지불금액 : " << price * 1.1 << endl;
	}
	else {
		cout << "카드 결제 여부 : false" << endl;
		cout << "지불금액 : " << price << endl;
	}
}

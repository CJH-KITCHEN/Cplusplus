#include "AdvancedTicket.h"
#include "iostream"

using namespace std;

AdvancedTicket::AdvancedTicket():AdvancedTicket(0.0, 0)
{
	//cout << "AdvancedTicket 생성자 생성" << endl;
}

AdvancedTicket::AdvancedTicket(double price, int advanceDays):Ticket(price)
{		
	this->advanceDays = advanceDays;
}

AdvancedTicket::~AdvancedTicket()
{
	order--;
	//cout << "AdvancedTicket 소멸자 생성" << endl;

}

double AdvancedTicket::getPrice() const
{
	return this->price;
}

int AdvancedTicket::getAdvanceDays() const
{
	return this->advanceDays;
}

void AdvancedTicket::show() const
{
	cout << "티켓번호 : " << this->number << endl;
	cout << "가격정보 : " << this->price << endl;
	if (advanceDays >= 30) {
		cout << "사전예약일 : " << advanceDays << endl;
		cout << "지불금액 : " << this->price * 0.5 << endl;
	}
	else if (advanceDays >= 20) {
		cout << "사전예약일 : " << advanceDays << endl;
		cout << "지불금액 : " << this->price * 0.7 << endl;
	}
	else if (advanceDays >= 10){
		cout << "사전예약일 : " << advanceDays << endl;
		cout << "지불금액 : " << this->price * 0.9 << endl;
	}
	else {
		cout << "사전예약일 : " << advanceDays << endl;
		cout << "지불금액 : " << this->price << endl;
	}
}

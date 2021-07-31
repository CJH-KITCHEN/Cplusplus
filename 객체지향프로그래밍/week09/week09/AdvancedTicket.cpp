#include "AdvancedTicket.h"
#include "iostream"

using namespace std;

AdvancedTicket::AdvancedTicket():AdvancedTicket(0.0, 0)
{
	//cout << "AdvancedTicket ������ ����" << endl;
}

AdvancedTicket::AdvancedTicket(double price, int advanceDays):Ticket(price)
{		
	this->advanceDays = advanceDays;
}

AdvancedTicket::~AdvancedTicket()
{
	order--;
	//cout << "AdvancedTicket �Ҹ��� ����" << endl;

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
	cout << "Ƽ�Ϲ�ȣ : " << this->number << endl;
	cout << "�������� : " << this->price << endl;
	if (advanceDays >= 30) {
		cout << "���������� : " << advanceDays << endl;
		cout << "���ұݾ� : " << this->price * 0.5 << endl;
	}
	else if (advanceDays >= 20) {
		cout << "���������� : " << advanceDays << endl;
		cout << "���ұݾ� : " << this->price * 0.7 << endl;
	}
	else if (advanceDays >= 10){
		cout << "���������� : " << advanceDays << endl;
		cout << "���ұݾ� : " << this->price * 0.9 << endl;
	}
	else {
		cout << "���������� : " << advanceDays << endl;
		cout << "���ұݾ� : " << this->price << endl;
	}
}

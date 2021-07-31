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
	//cout << "GeneralTicket �Ҹ��� ����" << endl;
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
	cout << "Ƽ�Ϲ�ȣ : " << this->number << endl;
	cout << "�������� : " << this->price << endl;
	if (this->payByCredit) {
		cout << "ī�� ���� ���� : true" << endl;
		cout << "���ұݾ� : " << price * 1.1 << endl;
	}
	else {
		cout << "ī�� ���� ���� : false" << endl;
		cout << "���ұݾ� : " << price << endl;
	}
}

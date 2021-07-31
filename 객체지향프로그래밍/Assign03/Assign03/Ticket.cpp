#include "Ticket.h"
#include "iostream"

using namespace std;

Ticket::Ticket():Ticket(0.0)
{	
	//cout << "Ticket default ������ ����" << endl;
}

Ticket::Ticket(double price)
{
	order++;
	this->number = order;
	this->price = price;
	this->finalprice = 0;
	//cout << "Ticket ������ ����" << endl;
}

Ticket::~Ticket()
{	
	order--;
	//cout << "Ticket�Ҹ��ڻ���" << endl;
}

int Ticket::getNumber() const
{
	return this->number;
}

void Ticket::setPrice(const double& price)
{
	this->price = price;
}

void Ticket::show() const
{
	cout << "Ƽ�Ϲ�ȣ : " << number << endl;
	cout << "�������� : " << price << endl;
}


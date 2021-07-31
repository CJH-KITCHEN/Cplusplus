#include "Ticket.h"
#include "iostream"

using namespace std;

Ticket::Ticket():Ticket(0.0)
{	
	//cout << "Ticket default 积己磊 积己" << endl;
}

Ticket::Ticket(double price)
{
	order++;
	this->number = order;
	this->price = price;
	this->finalprice = 0;
	//cout << "Ticket 积己磊 积己" << endl;
}

Ticket::~Ticket()
{	
	order--;
	//cout << "Ticket家戈磊积己" << endl;
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
	cout << "萍南锅龋 : " << number << endl;
	cout << "啊拜沥焊 : " << price << endl;
}


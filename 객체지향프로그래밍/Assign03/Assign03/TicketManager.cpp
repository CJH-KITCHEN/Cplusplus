#include "TicketManager.h"
#include "Ticket.h"
#include "AdvancedTicket.h"
#include "GeneralTicket.h"
#include <iostream>
using namespace std;

TicketManager::~TicketManager()
{
	if (ticket != nullptr) {
		for (int i = 0; i < (this->count); i++) {
			delete ticket[i];
		}
		delete[] ticket;
	}
	ticket = nullptr;
}

TicketManager::TicketManager(const string& name, const int number)
{
	this->m_name = name;
	this->totalNumber = number;
	this->ticket = new Ticket * [this->totalNumber];
}

void TicketManager::buy(Ticket* t)
{
	ticket[this->count] = t;
	this->count = this->count + 1;
	this->sum += t->setFinalPrice();
}

void TicketManager::show() const
{
	for (size_t i = 0; i < this->count; i++) {
		(this->ticket[i])->show();
		cout << endl;
	}
	cout << "-------------------------------------" << endl;
	cout << "총 예약 금액 : "<<this->sum << endl;
	cout << "-------------------------------------" << endl;

}

void TicketManager::showGeneralTicket(const bool& card)
{
	double temp = 0;
	cout << "------------일반 예약 현황-----------" << endl;
	for (size_t i = 0; i < this->count; i++) {
		if (dynamic_cast<GeneralTicket*>(ticket[i])) {
			if (static_cast<GeneralTicket*>(ticket[i])->getPayByCredit() == card) {
				ticket[i]->show();
				temp += ticket[i]->setFinalPrice();
			}
		}

	}
	if (temp) {
		cout << "-------------------------------------" << endl;
		cout << "총 예약 금액 : " << temp << endl;
		cout << "-------------------------------------" << endl;
	}
}

void TicketManager::showAdvancedTicket()
{
	double temp = 0;
	cout << "------------사전 예약 현황-----------" << endl;
	for (size_t i = 0; i < this->count; i++) {
		if (dynamic_cast<AdvancedTicket*>(ticket[i])) {
				ticket[i]->show();
				temp += ticket[i]->setFinalPrice();
				cout << endl;
		}
	}
	if (temp) {
		cout << "-------------------------------------" << endl;
		cout << "총 예약 금액 : " << temp << endl;
		cout << "-------------------------------------" << endl;
	}
}

int TicketManager::returnCount() const
{
	return this->count;
}

ostream& operator<<(ostream& out, const TicketManager& manager)
{
	out << "-----------티켓 예약 현황------------" << endl<<endl;
	out << "총 예약 매수 : " << manager.returnCount() << endl;
	out << "-------------------------------------" << endl;
	manager.show();
	out << endl;
	return out;
}

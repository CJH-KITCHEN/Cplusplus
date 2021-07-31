#pragma once

#include "Ticket.h"
#include <iostream>
#include <string>
using namespace std;

class TicketManager
{
private:
	string m_name;
	int totalNumber;
	Ticket** ticket = nullptr;
	int count = 0;
	double sum = 0;
public:
	TicketManager() = delete;
	~TicketManager();
	TicketManager(const string& name, const int number);
	void buy(Ticket* t);
	void show() const;
	void showGeneralTicket(const bool& card);
	void showAdvancedTicket();
	int returnCount() const;
	friend ostream& operator<<(ostream& out, const TicketManager& manager);
	
};
//ostream& operator<< (ostream& out, const TicketManager& manager);


#include "Ticket.h"
#include "AdvancedTicket.h"
#include "GeneralTicket.h"
#include <iostream>

using namespace std;

namespace CJH {
	void printName() {
		cout << "학번 : 201711430 이름 : 차준혁" << endl << endl;
	}
}

int Ticket::order = 0;

int main() {
	CJH::printName();
	Ticket ticket(1000.0);
	ticket.show();
	cout << "-----------------------" << endl;

	AdvancedTicket aticket(1000.0, 20);
	aticket.show();
	cout << "-----------------------" << endl;

	GeneralTicket gticket(2000.0, true);
	gticket.show();
	cout << "-----------------------" << endl;


}
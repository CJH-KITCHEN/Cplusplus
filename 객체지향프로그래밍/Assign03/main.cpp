
#include "TicketManager.h"
#include "Ticket.h"
#include "AdvancedTicket.h"
#include "GeneralTicket.h"
#include <iostream>
using namespace std;

int Ticket::order = 0;

namespace CJH {
	void printName() {
		cout << "학번 : 201711430 컴퓨터공학부 차준혁" << endl << endl;
	}
}
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CJH::printName();
	TicketManager manager("아이유콘서트", 10);

	manager.buy(new AdvancedTicket(1000, 40));
	manager.buy(new AdvancedTicket(1500, 30));
	manager.buy(new AdvancedTicket(2000, 25));
	manager.buy(new AdvancedTicket(1000, 5));
	manager.buy(new GeneralTicket(2000, true));
	manager.buy(new GeneralTicket(1500, false));

	cout << manager << endl;
	
	manager.showGeneralTicket(true);
	manager.showGeneralTicket(false);
	manager.showAdvancedTicket();
}
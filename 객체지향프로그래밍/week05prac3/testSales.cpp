#include <iostream>
#include "SalesReport.h"
using namespace std;
namespace CJH {
	void printName() {
		cout << "학번 : 201711430 이름 : 차준혁" << endl << endl;
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

	SalesReport team1(3);
	team1.addMember();
	team1.addMember();
	team1.addMember();
	team1.addMember();

	team1.computeStats();

	if (team1.getNumber() > 0) {
		cout << team1.getBestClerk()->getSalesmanInfo() << endl;
		cout << team1.getTeamInfo() << endl;
	}

	return 0;
}
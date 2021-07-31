#include <iostream>
#include "Lamp.h"
#include "User.h"
using namespace std;

namespace CJH {
	void printName() {
		cout << "학번 : 201711430 이름 : 차준혁" << endl << endl;
	}
}

int main() {
	CJH::printName();
	Lamp lamp1, lamp2;
	User user;
	cout << "=======Lamp1=======" << endl;
	user.turnOnOff(lamp1);
	user.changeLight(lamp1);
	user.changeLight(lamp1);
	user.changeLight(lamp1);
	user.changeLight(lamp1);
	user.turnOnOff(lamp1);
	user.changeLight(lamp1);
	cout << "=======Lamp2=======" << endl;
	user.turnOnOff(lamp2);
	user.changeLight(lamp2);
	user.changeLight(lamp2);
	user.turnOnOff(lamp2);
	user.changeLight(lamp2);

	return 0;
}
#include <iostream>
//#include "User.h"
#include "Lamp.h"
//#include <string>
//#include "TV.h"
using namespace std;

namespace CJH {
	void printName() {
		cout << "학번 : 201711430 이름 : 차준혁" << endl << endl;
	}
}

int main() {
	CJH::printName();

	Lamp lamp1;
	lamp1.powerOnOff();
	lamp1.changeLight();
	lamp1.changeLight();
	lamp1.changeLight();
	lamp1.changeLight();
	lamp1.powerOnOff();
	lamp1.changeLight();
	/*TV tv1, tv2;
	User user, user2;
	user.setName("greenjoa");
	cout << "=====TV1=======" << endl;
	user.turnOnOff(tv1);
	user.changeChannel(tv1, 12);
	user.changeVolume(tv1, 10);
	cout << "=====TV2=======" << endl;
	user.turnOnOff(tv2);
	user.changeChannel(tv2, 12);
	user.changeVolume(tv2, 10);
	cout << "=====TV1=======" << endl;
	user.turnOnOff(tv1);
	user.changeChannel(tv1, 12);
	return 0;*/
}
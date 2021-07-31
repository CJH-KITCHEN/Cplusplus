#include "Lamp.h"
#include <iostream>

using std::cout;
using std::endl;

void Lamp::powerOnOff()
{
	isOn = !isOn;
	if (isOn) {
		cout << "Lamp On" << endl;
	}
	else {
		cout << "Lamp off" << endl;
	}
}

void Lamp::changeLight()
{
	if (isOn) {
		illuminance++;
		if (illuminance > 3) {
			illuminance = 1;
		}
		cout << "조도 : " << illuminance << endl;
	}
	else {
		cout << "lamp가 꺼져있습니다." << endl;
	}
}

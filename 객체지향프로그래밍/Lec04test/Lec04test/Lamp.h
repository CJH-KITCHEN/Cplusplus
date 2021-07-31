#pragma once
class Lamp
{
private:
	bool isOn = false;
	int illuminance = 1;

public:
	void powerOnOff();
	void changeLight();

};


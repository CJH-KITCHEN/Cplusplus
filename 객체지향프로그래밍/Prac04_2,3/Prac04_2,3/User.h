#pragma once
#include <string>
#include "Lamp.h"
using std::string;

class User
{
private:
	string name;
public:
	void turnOnOff(Lamp& lamp);
	void changeLight(Lamp& lamp);

};


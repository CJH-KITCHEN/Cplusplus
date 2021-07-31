#pragma once
#include <string>
#include "TV.h"
using std::string;

class User
{
private:
	string m_name;
public:
	void setName(const string& name);
	void turnOnOff(TV& tv);
	void changeVolume(TV& tv, const int volume);
	void changeChannel(TV& tv, const int channel);
};


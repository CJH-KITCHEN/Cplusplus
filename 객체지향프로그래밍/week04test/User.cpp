#include "User.h"

void User::setName(const string& name)
{
	m_name = name;
}

void User::turnOnOff(TV& tv)
{
	tv.powerOnOff();
}

void User::changeVolume(TV& tv, const int volume)
{
	tv.setVolume(volume);

}

void User::changeChannel(TV& tv, const int channel)
{
	tv.setchannel(channel);
}

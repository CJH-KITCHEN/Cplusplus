#include "TV.h"
#include <iostream>

using std::cout;
using std::endl;

int TV::getVolume()
{
	return m_volume;
}

void TV::setchannel(int Channel)
{	
	if(m_isOn)
		m_channel = Channel;
	showStatus();
}

int TV::getChannel()
{
	return m_channel;
}

void TV::showStatus()
{
	if (m_isOn) {
		cout << "ä�� : " << m_channel << ", ����: " << m_volume << " ��û��" << endl;
	}
	else {
		cout << "������ ��������" << endl;
	}
}

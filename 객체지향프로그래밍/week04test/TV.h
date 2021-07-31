#pragma once
class TV
{
private:
	bool m_isOn = false;
	int m_volume = 10;
	int m_channel = 5;
public:
	void powerOnOff()
	{
		m_isOn = !m_isOn;
	}
	void setVolume(int volume)
	{
		if (m_isOn)
			m_volume = volume;
		showStatus();
	}
	int getVolume();
	void setchannel(int Channel);
	int getChannel();
	void showStatus();
};


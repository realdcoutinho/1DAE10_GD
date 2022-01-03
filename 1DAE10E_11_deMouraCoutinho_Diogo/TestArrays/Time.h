#pragma once
class Time
{
public:
	Time(unsigned int seconds);
	Time(unsigned int seconds, unsigned int minutes);
	Time(unsigned int seconds, unsigned int minutes, unsigned int hours);
	void Print();
	unsigned int GetTotalSeconds();
	unsigned int GetSeconds();
	unsigned int GetMinutes();
	unsigned int GetHours();
	void AddSeconds(int seconds);
	void AddMinutes(int minutes);
	void AddHours(int hours);
private:
	unsigned int m_Seconds;
};


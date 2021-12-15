#pragma once
class Time
{
public:
	Time(int seconds);
	Time(int minutes, int seconds);
	Time(int hours, int minutes, int seconds);
	void Print();
	int GetTotalSeconds();
	int GetSeconds();
	int GetMinutes();
	int GetHours();
	void AddSeconds(int seconds);
	void AddMinutes(int minutes);
	void AddHours(int hours);
private:
	int m_Seconds;
};


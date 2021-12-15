#include "pch.h"
#include "Time.h"
#include <iomanip>
#include <iostream>


Time::Time(int seconds) : 
	Time{ 0, 0, seconds }
{
}

Time::Time(int minutes, int seconds) : 
	Time{ 0, minutes, seconds }
{
}
Time::Time(int hours, int minutes, int seconds) :
	m_Seconds { (hours * 3600) + (minutes * 60) + seconds}
{
}

void Time::Print()
{
	std::cout << std::setfill('0') << std::setw(2) << GetHours() << ':';
	std::cout << std::setfill('0') << std::setw(2) << GetMinutes() << ':';
	std::cout << std::setfill('0') << std::setw(2) << GetSeconds() << '\n';

}

int Time::GetTotalSeconds()
{
	return m_Seconds;
}

int Time::GetSeconds() 
{
	return (m_Seconds - (3600 * GetHours()) - (60 * GetMinutes()));
}

int Time::GetMinutes()
{
	return (m_Seconds - (3600 * GetHours())) / 60;
}

int Time::GetHours()
{
	return m_Seconds / 3600;
}


void Time::AddSeconds(int seconds)
{
	m_Seconds += seconds;
}

void Time::AddMinutes(int minutes)
{
	m_Seconds += minutes * 60;
}

void Time::AddHours(int hours)
{
	m_Seconds += hours * 3600;
}
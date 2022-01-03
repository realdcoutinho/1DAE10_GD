#include "pch.h"
#include "Time.h"
#include <iomanip>
#include <iostream>


Time::Time(unsigned int seconds) : 
	Time{ 0, 0, seconds }
{
}

Time::Time(unsigned int minutes, unsigned int seconds) :
	Time{ 0, minutes, seconds }
{
}
Time::Time(unsigned int hours, unsigned int minutes, unsigned int seconds) :
	m_Seconds { (hours * 3600) + (minutes * 60) + seconds}
{
}

void Time::Print()
{
	std::cout << std::setfill('0') << std::setw(2) << GetHours() << ':';
	std::cout << std::setfill('0') << std::setw(2) << GetMinutes() << ':';
	std::cout << std::setfill('0') << std::setw(2) << GetSeconds() << '\n';

}

unsigned int Time::GetTotalSeconds()
{
	return m_Seconds;
}

unsigned int Time::GetSeconds()
{
	return (m_Seconds - (3600 * GetHours()) - (60 * GetMinutes()));
}

unsigned int Time::GetMinutes()
{
	return (m_Seconds - (3600 * GetHours())) / 60;
}

unsigned int Time::GetHours()
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
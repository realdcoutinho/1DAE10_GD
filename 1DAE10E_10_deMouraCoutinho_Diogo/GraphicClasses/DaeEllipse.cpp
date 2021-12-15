#include "pch.h"
#include "DaeEllipse.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

DaeEllipse::DaeEllipse(const Point2f& center, float radX, float radY, const Color4f& fillColor) 
	: m_Center{center}, m_RadX{ radX }, m_RadY{radY}, m_FillColor{fillColor}
{
	float area{ radX * radY * float(M_PI) };
	
	std::cout << "The area of the ellipse is: " << area << '\n';

}

void DaeEllipse::ActiveTest(const Point2f& pos)
{
	const Ellipsef DaeEllipse( m_Center, m_RadX, m_RadY );

	if (IsPointInEllipse(DaeEllipse, pos)) {
		m_FillColor.a = 0.5f;
		std::cout << "Activated!";
	}
	else
	{
		m_FillColor.a = 1;
		std::cout << "Not Activated!";
	}
}

void DaeEllipse::Draw()
{
	const Ellipsef DaeEllipse(m_Center, m_RadX, m_RadY);
	SetColor(m_FillColor);
	FillEllipse(DaeEllipse);
}


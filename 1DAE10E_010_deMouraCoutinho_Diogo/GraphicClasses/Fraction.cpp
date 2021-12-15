#include "pch.h"
#include "Fraction.h"



Fraction::Fraction(int numerator, int denominator) :
	m_Numerator{ numerator }, m_Denominator{ denominator }
{
}

void Fraction::Draw(const Point2f& pos, float size)
{
	float posX = pos.x;
	float posY = pos.y;
	for (int k{0}; k < m_Numerator; k++) {

		SetColor(0, 0, 1, 1);
		posX = pos.x + (k * size);
		FillRect(posX, posY, size, size);
	}

	posX = pos.x;

	for (int i{ 0 }; i < m_Denominator; i++) {

		SetColor(1, 1, 1, 1);
		posX = pos.x + (i *size);
		DrawRect(posX, posY, size, size);
	}

}

float Fraction::GetValue()
{
	return float(float(m_Denominator) / float(m_Numerator));
}
#include "pch.h"
#include "Square.h"
#include <iostream>

Square::Square(float size, float left, float bottom) : m_Size{ size }, m_Left{ left }, m_Bottom{ bottom }
{
	std::cout << "Constructor is executing" << '\n';
}

Square::~Square()
{
	std::cout << "Square destructor: realease the resouces" << '\n';
}

void Square::SetSize(float newSize)
{
	if (newSize > 0) {
		m_Size = newSize;
	}
}

void Square::Translate(float deltaLeft, float deltaBottom)
{
	if (m_Left + deltaLeft > 0) {
		m_Left += deltaLeft;
	}

	if (m_Bottom + deltaBottom > 0) {
		m_Bottom += deltaBottom;
	}

}

float Square::GetArea()
{
	float area = m_Size * m_Size;
	return area;
}

float Square::GetPerimeter()
{
	float perimeter = m_Size * 4;
	return perimeter;
}

void Square::Print()
{
	float area{ GetArea() };
	float perimeter{ GetPerimeter() };

	std::cout << '\n';
	std::cout << "Square information:" << '\n';
	std::cout << "Left: " << m_Left << '\n';
	std::cout << "Bottom: " << m_Bottom << '\n';
	std::cout << "Area: " << area << '\n';
	std::cout << "perimeter: " << perimeter << '\n';
	std::cout << '\n';

}



void Square::SetLeft(const float left)
{
	if (left > 0) {
		m_Left = left;
	}
}

void Square::SetBottom(const float bottom)
{
	if (bottom > 0) {
		m_Bottom = bottom;
	}
}

void Square::GetSize()
{
	std::cout << "Size: " << m_Size << '\n';
}

void Square::GetLeft()
{
	std::cout << "Left: " << m_Left << '\n';
}

void Square::GetBottom()
{
	std::cout << "Bottom: " << m_Bottom << '\n';
}


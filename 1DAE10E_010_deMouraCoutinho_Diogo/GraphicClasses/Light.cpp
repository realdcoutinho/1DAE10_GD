#include "pch.h"
#include "Light.h"
#include <iostream>

Light::Light(const Rectf& rect, const Color4f color) :
	m_Rect{rect}, m_Color{ Color4f{ rand() % 256 / 255.0f,rand() % 256 / 255.0f,rand() % 256 / 255.0f,1 } }
{
	std::cout << "Created Rect" << '\n';
}

void Light::Draw()
{
	if (m_IsOn) {
		SetColor(m_Color);
		FillRect(m_Rect);
	}
	if (!(m_IsOn)) {
		SetColor(0.5f, 0.5f, 0.5f, 1);
		FillRect(m_Rect);
	}

	SetColor(1, 1, 1, 1);
	DrawRect(m_Rect);
}

bool Light::IsHit(const Point2f& pos)
{
	if (IsPointInRectangle(m_Rect, pos)) {
		//std::cout << "YES" << '\n';
		m_IsOn = !m_IsOn;
		return true;
	}
	else {
		//std::cout << "NO" << '\n';
		return false;
	}
}

bool Light::IsOn()
{
	if (m_IsOn) {
		std::cout << "light is on" << '\n';
		return true;
	}
	else {
		std::cout << "light is off" << '\n';
		return false;
	}

}
#pragma once

class Square
{
public:
	Square(float size = 10, float left = 10, float bottom= 10);
	~Square();

	void SetSize(float newSize);
	void Translate(float deltaLeft, float deltaBottom);
	void Print();
	
	void SetLeft(const float left);
	void SetBottom(float bottom);

	void GetSize();
	void GetLeft();
	void GetBottom();
	
private:

	float GetArea();
	float GetPerimeter();
	float m_Size;
	float m_Left;
	float m_Bottom;

};



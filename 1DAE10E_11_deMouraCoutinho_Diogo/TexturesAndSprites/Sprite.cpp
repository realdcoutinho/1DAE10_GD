#include "pch.h"
#include "Sprite.h"
#include "utils.h"
#include <iostream>
using namespace utils;


Sprite::Sprite(const std::string& filename, int nrCols, int nrRows, int nrOfFrames, float frameSec, float scale)
	:m_Cols{ nrCols }
	, m_Rows{ nrRows }
	, m_NrOfFrames{ nrOfFrames }
	, m_FrameSec{ frameSec }
	, m_AccuSec{ 0 }
	, m_ActFrame{ 0 }
	, m_Scale{ scale }
{
	if (!TextureFromFile(filename, m_Texture))
	{
		std::cout << "SpriteClassError: failed to load image, is the filename correct?\n";
	}
	else
		std::cout << "It was sucefull" << '\n';
}

Sprite::Sprite(std::string& text, const std::string& filename, int textSize, Color4f textColor)
	:m_Text{ text }
	, m_TextSize{ textSize }

{
	if (!TextureFromString(text, filename,textSize, textColor, m_Texture))
	{
		std::cout << "SpriteClassError: failed to load text, is the filename correct?\n";
	}
	else
		std::cout << "It was sucefull" << '\n';
}

Sprite::~Sprite()
{
	DeleteTexture(m_Texture);
	std::cout << "Sprite destructor: realease the resouces" << '\n';
}

void Sprite::Update(float elapsedSec)
{
	m_AccuSec += elapsedSec;
	if (m_FrameSec < m_AccuSec)
	{
		++m_ActFrame %= m_NrOfFrames;
		m_AccuSec -= m_FrameSec;
	}
}


void Sprite::Draw(const Point2f& pos)
{
	Rectf sourceRectangle{ GenerateSourceRectangleForSprite(m_Texture) };

	//Draw it at the top of the window
	Rectf destinationRectangle{};
	destinationRectangle.left = pos.x;
	destinationRectangle.bottom = pos.y;
	destinationRectangle.width = sourceRectangle.width * m_Scale;
	destinationRectangle.height = sourceRectangle.height * m_Scale;
	
	DrawTexture(m_Texture, destinationRectangle, sourceRectangle);
}

void Sprite::DrawText(const Point2f& pos)
{
	DrawTexture(m_Texture, pos);
}

Rectf Sprite::GenerateSourceRectangleForSprite(utils::Texture texture)
{
	Rectf sourceRectangle{};
	sourceRectangle.width = m_Texture.width / m_Cols;
	sourceRectangle.height = m_Texture.height / m_Rows;
	sourceRectangle.left = (float)((m_ActFrame % m_Cols) * sourceRectangle.width);
	sourceRectangle.bottom = (float)((m_ActFrame / m_Cols + 1) * sourceRectangle.height);
	return sourceRectangle;
}

// Gives the width of the scaled frame
float Sprite::GetFrameWidth()
{
	return ((m_Texture.width / m_Cols) * m_Scale);
}
// Gives the height of the scaled frame
float Sprite::GetFrameHeight()
{
	return ((m_Texture.height / m_Rows) * m_Scale);
}
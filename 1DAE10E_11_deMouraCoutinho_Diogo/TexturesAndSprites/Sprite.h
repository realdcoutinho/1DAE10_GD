#pragma once
#include "utils.h"

class Sprite
{
private:
	utils::Texture m_Texture;
	int m_Cols{1};
	int m_Rows{1};
	float m_FrameSec{}; //Frame Time
	float m_AccuSec{}; // accumulated Time
	int m_ActFrame{}; // Current Frame
	int m_NrOfFrames{};
	float m_Scale{1};
	
	std::string m_Text{};
	int m_TextSize{};


	
public:
	Sprite(const std::string& filename, int nrCols, int nrRows, int nrOfFrames, float frameSec, float scale);
	Sprite(std::string& text, const std::string& filename, int textSize, Color4f textColor);
	Rectf GenerateSourceRectangleForSprite(utils::Texture texture);
	~Sprite();
	void Update(float elapsedSec);
	void Draw(const Point2f& pos);
	void DrawText(const Point2f& pos);
	float GetFrameWidth();
	//float GetDistinationWidth();
	float GetFrameHeight();
};


#pragma once
#include "utils.h"



class Tile 
{
public:
	Tile(const Rectf& dstRect, const std::string& textPath, int nrAnimals );

	//void Draw();
	//void CheckActivation(const Point2f& pos);
	//bool CheckHit(const Point2f& pos);
	//int GetCurrentAnimal( );
	//void Deactivate();
	//void Randomize( );

private: 

	utils::Texture m_TextureAnimal;
	int m_Cols{ 1 };
	int m_Rows{ 1 };
	int m_NrAnimals{};
	Rectf m_Rect{};
	std::string m_AnimalName{};
	float m_Scale{ 1 };
};


//class Tile
//{
//public:
//	Tile(const std::string& filename, int nrCols, int nrRows, const int nrAnimals, Rectf rectangleArea);
//	~Tile();
//	void Draw(const Point2f& pos);
//	void DrawText(const Point2f& pos);
//
//	Rectf GenerateSourceRectangleForSprite(utils::Texture texture);
//
//private:
//
//
//};
#include "pch.h"
#include "Game.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//Basic game functions
#pragma region gameFunctions											
void Start()
{

	// initialize game resources here
	bool succesfull = TextureFromString(g_Numbers, "Resources/DIN-Light.otf", 18, Color4f{ g_Blue }, g_SomeText);
	TwoDArrays();
}

void Draw()
{
	ClearBackground(0, 0, 0);
	// Put your own draw statements here
	DrawTracingPoints(g_TracingPoint);

	DrawClickedPoints(g_clickedPoints);
	DrawBars(g_ArrayInt, g_MaxInterval);
	
	Point2f position{ 10, 10 };
	DrawTexture(g_DAELogo, position);
	DrawGrid();
	//DrawDrid();
}

void Update(float elapsedSec)
{
	UpdateRandStats(g_ArrayInt, g_MaxInterval);

}

void End()
{
	// free game resources here
	DeleteTexture(g_SomeText);
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };


	g_MousePosTracing.x = float(e.x);
	g_MousePosTracing.y = float(g_WindowHeight - e.y);
	AddTracingPoints();
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	g_MousePosToggle.x = float(e.x);
	g_MousePosToggle.y = float(g_WindowHeight - e.y);
	ToggleCell(g_MousePosToggle);
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y);
	AddClickedPoints();


	g_IsClicked = true;

}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void AddClickedPoints()
{
	for (int j{ 0 }; j < 1; ++j) {
		for (int i{}; i < g_maxClicked - 1; ++i) {
			//SwapPosition(g_clickedPoints, i, i + 1, g_maxClicked);
			g_clickedPoints[i] = g_clickedPoints[i + 1];
		}
		g_clickedPoints[g_maxClicked - 1] = g_MousePos;
	}
	//PrintPointCoordinates(g_clickedPoints, g_maxClicked);
}
void DrawClickedPoints(Point2f* pArray) 
{
	if (g_IsClicked) {
		for (int i{}; i < g_maxClicked; ++i) {
			SetColor(g_White);
			DrawLine(pArray[i].x, pArray[i].y, pArray[i + 1].x, pArray[i + 1].y);
			SetColor(g_Red);
			FillEllipse(pArray[i].x, pArray[i].y, 10, 10);
		}
	}
}


void DrawBars(int* pArray, int size)
{
	const float left{ 30.0f };
	const float border{ 10.0f };
	const float height{ 20.0f };
	float difference{ border + height };
	float bottom{g_WindowHeight};
	float width{};
	bool succesfull{};
	
	SetColor(g_Blue);

	for (int j{}; j < size; ++j) {
		bottom -= difference;
		width = float(pArray[j]);
		g_Numbers = std::to_string(j);
		Point2f positionNr{ 15.0f, bottom };

		succesfull = TextureFromString(g_Numbers, "Resources/DIN-Light.otf", 18, Color4f{ g_Blue }, g_SomeText);
		DrawTexture(g_SomeText, positionNr);
		FillRect(left, bottom, width, height);
	}
}
void UpdateRandStats(int* pArray, int size) 
{
	int randomIndex = GetRandom(size);
	pArray[randomIndex] += 1;
	//PrintArray(pArray, size);
}
int GetRandom(int maxInterval) 
{
	int randomInt{ rand() % maxInterval };
	return randomInt;
}


void AddTracingPoints()
{

	for (int j{ 0 }; j < 1; ++j) {
		for (int i{}; i < g_MaxTracing - 1; ++i) {
			//SwapPosition(g_clickedPoints, i, i + 1, g_maxClicked);
			g_TracingPoint[i] = g_TracingPoint[i + 1];
		}
		g_TracingPoint[g_MaxTracing - 1] = g_MousePosTracing;
	}
	//PrintPointCoordinates(g_TracingPoint, g_MaxTracing);
}
void DrawTracingPoints(Point2f* pArray)
{
	float l{};
	float radius{ 10 };
	Ellipsef Tracing{};

	g_Green.a = 0;
	for (int i{}; i < g_MaxTracing; ++i) {
		SetColor(g_Green);
		g_Green.a += float(0.5f / float(g_MaxTracing));
		Tracing = Ellipsef(pArray[i].x, pArray[i].y, radius, radius);
		FillEllipse(Tracing);
		radius += radius / float(g_MaxTracing);
	}
}

void ToggleCell(Point2f MousePoint)
{
	for (int row{ 0 }; row < g_CellRows; row++)
	{
		for (int column{ 0 }; column < g_CellColumns; column++)
		{
			int index{ GetIndex(row, column, g_CellColumns) };
			Rectf gridCell{ g_GridBottomLeft.x + (g_GridCellLenght * column),
							g_GridBottomLeft.y + (g_GridCellLenght * row), g_GridCellLenght, g_GridCellLenght };
			if (IsPointInRectangle(gridCell, g_MousePosToggle))
			{
				g_CellsArray[index] = !g_CellsArray[index];
				return;
			}
		}
	}
}
void DrawGrid() 
{
	const Color4f toggleOn{ g_Orange };
	const Color4f toggleOff{ g_Grey };
	for (int row{ 0 }; row < g_CellRows; row++)
	{
		for (int column{ 0 }; column < g_CellColumns; column++)
		{
			Point2f bottomLeft{ g_GridBottomLeft.x + (column * g_GridCellLenght), g_GridBottomLeft.y + (row * g_GridCellLenght) };
			int index{ GetIndex(row, column, g_CellColumns) };
			SetColor(toggleOff);
			if (g_CellsArray[index])
				SetColor(toggleOn);
			FillRect(bottomLeft, g_GridCellLenght, g_GridCellLenght);
			SetColor(g_White);
			DrawRect(bottomLeft, g_GridCellLenght, g_GridCellLenght);

		}

	}
}





//Draw Grid
/*
void DrawDrid() {
	const float border{ 10 };
	const int rows{ 5 };
	const int columns{ 6 };
	const float cellLenght{ 50 };
	float gridBottom{ border };
	float gridLeft{ border };
	SetColor(g_Grey);
	FillRect(gridLeft, gridBottom, cellLenght * columns, cellLenght * rows);

	for (int i{1}; i < columns; ++i) {// vertical lines

		Point2f bottom{ gridBottom + cellLenght * i, border };
		Point2f top{ gridBottom + cellLenght * i, cellLenght * rows + border };
		SetColor(g_White);
		DrawLine(bottom, top);
	}
	for (int j{ 1 }; j < rows; ++j) {// vertical lines

		Point2f left{border , gridBottom + cellLenght * j };
		Point2f right{ gridBottom + cellLenght * columns, cellLenght * j + border };
		SetColor(g_White);
		DrawLine(left, right);
	}
}
*/








void TwoDArrays()
{
	std::cout << "-- 2D arrays --" << std::endl;
	const int rows{ 3 };
	const int columns{ 4 };
	const int linearGridArraySize{ rows * columns };
	int linearGridArray[linearGridArraySize]{};
	for (int row{ 0 }; row < rows; row++)
	{
		for (int column{ 0 }; column < columns; column++)
		{
			int index{ GetIndex(row, column, columns) };
			linearGridArray[index] = (row + 1) * 10 + column + 1;
		}
	}
	Print2DElements(linearGridArray, rows, columns);
}

void Print2DElements(int* pNumbers, int rows, int columns)
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			int index{ GetIndex(row, column, columns) };
			std::cout << pNumbers[index] << " ";
		}
		std::cout << std::endl;
	}
}

int GetIndex(int rowIndex, int columnIndex, int nrOfColumns)
{
	return rowIndex * nrOfColumns + columnIndex;
}







void PrintPointCoordinates(Point2f* pArray, int size) 
{
	for (int i{}; i < size; ++i) {
		std::cout << "Array[" << i << "] :" << ToString(pArray[i]) << '\n';
	}
}

void SwapPosition(Point2f* pArray, int idx1, int idx2, int size)
{
	swap(pArray[idx1], pArray[idx2]);
}

void PrintArray(int* pArray, int size) {

	for (int i{ 0 }; i < size; ++i) std::cout << pArray[i] << ' ';
	std::cout << '\n';
}
#pragma endregion ownDefinitions